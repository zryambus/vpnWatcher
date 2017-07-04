#include <iostream>
#include <pistache/endpoint.h>

#include "vpnservice.h"

int main()
{
    Pistache::Port port(8080);

    int threads = 2;

    Pistache::Address addr(Pistache::Ipv4::any(), port);

    std::cout << "Server started at " << addr.host() << ":" << addr.port() << std::endl;
    std::cout << "Cores = " << Pistache::hardware_concurrency() << std::endl;
    std::cout << "Using " << threads << " threads" << std::endl;

    VpnService vpnService(addr);

    vpnService.init(threads);
    vpnService.start();

    vpnService.shutdown();
}
