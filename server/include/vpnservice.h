#ifndef VPNSERVICE_H
#define VPNSERVICE_H

#include <iostream>

#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>

#include <msgpack.hpp>

#include "common/include/client.h"
#include "common/include/common.h"
#include "manager.h"

class VpnService
{
public:
    VpnService(Pistache::Address addr)
        : httpEndpoint_(std::make_shared<Pistache::Http::Endpoint>(addr))
        , router_()
    { }

    void init(unsigned int threads) {
        auto opts = Pistache::Http::Endpoint::options()
                .threads(threads)
                .flags(Pistache::Tcp::Options::InstallSignalHandler);
        httpEndpoint_->init(opts);

        Pistache::Rest::Routes::Get(router_, "/api/ready", Pistache::Rest::Routes::bind(&VpnService::handlerReady, this));
        Pistache::Rest::Routes::Get(router_, "/api/get", Pistache::Rest::Routes::bind(&VpnService::handlerGetAll, this));
        Pistache::Rest::Routes::Post(router_, "/api/post", Pistache::Rest::Routes::bind(&VpnService::handlerUpdateUser, this));
    }

    void start() {
        httpEndpoint_->setHandler(router_.handler());
        httpEndpoint_->serve();
    }

    void shutdown() {
        httpEndpoint_->shutdown();
    }

private:

    void handlerGetAll(const Pistache::Http::Request& request, Pistache::Http::ResponseWriter response);
    void handlerUpdateUser(const Pistache::Http::Request& request, Pistache::Http::ResponseWriter response);
    void handlerReady(const Pistache::Http::Request& request, Pistache::Http::ResponseWriter response);

    std::shared_ptr<Pistache::Http::Endpoint> httpEndpoint_;
    Pistache::Rest::Router router_;
};

#endif