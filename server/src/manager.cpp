#include "manager.h"


Manager::Manager(): storage_(new Storage) {

}

Manager::~Manager(){

}

void Manager::update(const Client &client) {
    StorageItem& item = std::find_if(storage_.get()->begin(), storage_.get()->end(), [](const StorageItem& item) {
        return item.client->getIp() == client.getIp() && item.client->getName() == client.getName();
    });
    if (item != storage_.get()->end())
    {
        item.lastOnline = std::chrono::system_clock::now();
    }
    else
    {
        StorageItem newStorageItem;
        newStorageItem.client = std::make_shared(client);
        newStorageItem.lastOnline = std::chrono::system_clock::now();
        storage_.get()->push_back(newStorageItem);
    }
}