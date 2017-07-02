#include <server/include/manager.h>
#include "vpnservice.h"

void VpnService::handlerReady(const Net::Http::Request& request, Net::Http::ResponseWriter response) {
    response.send(Net::Http::Code::Ok, "1");
}

void VpnService::handlerGetAll(const Net::Http::Request &request, Net::Http::ResponseWriter response)
{

    response.send(Net::Http::Code::Ok);
}

void VpnService::handlerUpdateUser(const Net::Http::Request &request, Net::Http::ResponseWriter response)
{
//    const std::string body = request.body();
//    Client client;
//    Common::readFromString(client, body);
//    client.print();
//    Manager::Instance().update(client);

    response.send(Net::Http::Code::Ok);
}

