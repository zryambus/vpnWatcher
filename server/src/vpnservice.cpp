#include "vpnservice.h"

void VpnService::handlerReady(const Net::Http::Request& request, Net::Http::ResponseWriter response) {
    response.send(Net::Http::Code::Ok, "1");
}

void VpnService::handlerGetAll(const Net::Http::Request &request, Net::Http::ResponseWriter response)
{

}

void VpnService::handlerUpdateUser(const Net::Http::Request &request, Net::Http::ResponseWriter response)
{
    const auto body = request.body();
    msgpack::sbuffer sbuf;
    sbuf.write(body.c_str(), body.length());

    msgpack::object_handle oh = msgpack::unpack(sbuf.data(), sbuf.size());
    msgpack::object obj = oh.get();

    Client client;
    obj.convert(client);
    client.print();
}
