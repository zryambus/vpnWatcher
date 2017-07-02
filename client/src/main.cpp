#include <iostream>
#include <chrono>
#include <pistache/net.h>
#include <pistache/http.h>
#include <pistache/client.h>
#include <msgpack.hpp>

#include "client.h"
#include "common.h"

int main()
{
    Net::Http::Client netClient;
    std::vector<Async::Promise<Net::Http::Response>> responses;

    auto opts = Net::Http::Client::Options()
        .threads(5)
        .maxConnectionsPerHost(5);
    netClient.init(opts);

    auto resp = netClient.get("http://127.0.0.1:8080/api/ready").send();
    resp.then([&](Net::Http::Response response) {
        std::cout << response.code() << std::endl;
        std::cout << response.body() << std::endl;
    }, Async::IgnoreException);
    responses.push_back(std::move(resp));

    auto client = ClientBuilder()
    .ip("192.168.1.1")
    .name("dotka")
    .build();

    std::stringstream ss;
    msgpack::pack(ss, client);

    auto postResp = netClient.post("http://127.0.0.1:8080/api/post").body(ss.str()).send();
    postResp.then([&](Net::Http::Response response) {
        std::cout << response.code() << std::endl;
    }, Async::IgnoreException);
    responses.push_back(std::move(postResp));

    auto sync = Async::whenAll(responses.begin(), responses.end());
    Async::Barrier<std::vector<Net::Http::Response>> barrier(sync);

    barrier.wait_for(std::chrono::seconds(2));

    netClient.shutdown();
}