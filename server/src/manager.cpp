#include "manager.h"

Manager::Manager() {

}

Manager::~Manager(){

}

void Manager::update(const Client &client) {
    const auto& item = std::find_if(storage_.get()->begin(), storage_.get()->end(), [&client](const StorageItem& item) {
        return item.client->getIp() == client.getIp() && item.client->getName() == client.getName();
    });
    if (item != this->storage_.get()->end())
    {
        (*item).lastOnline = std::chrono::system_clock::now();
    }
    else
    {
        StorageItem newStorageItem;
        newStorageItem.client = std::make_shared<Client>(client);
        newStorageItem.lastOnline = std::chrono::system_clock::now();
        storage_.get()->push_back(newStorageItem);
    }
}