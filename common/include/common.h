#include <cryptopp/modes.h>
#include <cryptopp/aes.h>
using CryptoPP::AES;
#include <cryptopp/ccm.h>
#include <cryptopp/filters.h>
#include <cryptopp/base64.h>

#include <msgpack.hpp>

#include "client.h"

namespace Common {
    const byte key[16] = "123456789012345";
    const byte iv[16]= "098765432109876";

    byte* encrypt(const byte* plain, unsigned int length);
    byte* decrypt(const byte* cipher, unsigned int length);

    template <typename T>
    void readFromString(T& object, const std::string& buffer) {
        msgpack::sbuffer sbuf;
        sbuf.write(buffer.c_str(), buffer.length());

        msgpack::object_handle oh = msgpack::unpack(sbuf.data(), sbuf.size());
        msgpack::object obj = oh.get();

        obj.convert(object);
    }

}