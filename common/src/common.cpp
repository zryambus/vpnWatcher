#include "common.h"

byte* Common::encrypt(const byte* plain, unsigned int length)
{
    byte* encrypted = new byte[16];
    CryptoPP::CBC_Mode<AES>::Encryption encryption(Common::key, sizeof(Common::key), Common::iv);
    encryption.ProcessData(encrypted, plain, length);
    return encrypted;
}

byte* Common::decrypt(const byte* cipher, unsigned int length)
{
    byte* decrypted = new byte[16];
    CryptoPP::CBC_Mode<AES>::Decryption decryption(Common::key, sizeof(Common::key), Common::iv);
    decryption.ProcessData(decrypted, cipher, length);
    return decrypted;
}
