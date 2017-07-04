#include "vpnservice.h"

void VpnService::handlerReady(const Pistache::Http::Request& request, Pistache::Http::ResponseWriter response) {
    response.send(Pistache::Http::Code::Ok, "1");
}

void VpnService::handlerGetAll(const Pistache::Http::Request &request, Pistache::Http::ResponseWriter response)
{

    response.send(Pistache::Http::Code::Ok);
}

void VpnService::handlerUpdateUser(const Pistache::Http::Request &request, Pistache::Http::ResponseWriter response)
{
    const std::string body = request.body();
    Client client;
    Common::readFromString(client, body);
    client.print();
    Manager::Instance().update(client);

    response.send(Pistache::Http::Code::Ok);
}

