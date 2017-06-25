#ifndef CLIENT_H
#define CLIENT_H

#include "msgpack.hpp"

class ClientBuilder;

class Client {
private:
    std::string ip_;
    std::string name_;
public:
    friend class ClientBuilder;
    void print(){ std::cout << "Client " << ip_ << " " << name_ << std::endl; }
    MSGPACK_DEFINE(ip_, name_)
};

class ClientBuilder {
private:
    Client client_;
public:
    ClientBuilder ip(std::string ip)
    {
        client_.ip_ = ip;
        return *this;
    }
    ClientBuilder name(std::string name)
    {
        client_.name_ = name;
        return *this;
    }

    Client build()
    {
        return client_;
    }
};

#endif // CLIENT_H
