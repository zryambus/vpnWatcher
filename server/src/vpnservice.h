#ifndef VPNSERVICE_H
#define VPNSERVICE_H

#include <pistache/http.h>
#include <pistache/endpoint.h>
#include <pistache/router.h>

#include <msgpack.hpp>

#include "common/include/client.h"

class VpnService
{
public:
    VpnService(Net::Address addr)
        : httpEndpoint_(std::make_shared<Net::Http::Endpoint>(addr))
        , router_()
    { }

    void init(unsigned int threads) {
        auto opts = Net::Http::Endpoint::options()
                .threads(threads)
                .flags(Net::Tcp::Options::InstallSignalHandler);
        httpEndpoint_->init(opts);

        Net::Rest::Routes::Get(router_, "/api/ready", Net::Rest::Routes::bind(&VpnService::handlerReady, this));
        Net::Rest::Routes::Post(router_, "/api/post", Net::Rest::Routes::bind(&VpnService::handlerUpdateUser, this));
    }

    void start() {
        httpEndpoint_->setHandler(router_.handler());
        httpEndpoint_->serve();
    }

    void shutdown() {
        httpEndpoint_->shutdown();
    }


private:

    void handlerGetAll(const Net::Http::Request& request, Net::Http::ResponseWriter response);
    void handlerUpdateUser(const Net::Http::Request& request, Net::Http::ResponseWriter response);
    void handlerReady(const Net::Http::Request& request, Net::Http::ResponseWriter response);

    std::shared_ptr<Net::Http::Endpoint> httpEndpoint_;
    Net::Rest::Router router_;
};

#endif // VPNSERVICE_H
