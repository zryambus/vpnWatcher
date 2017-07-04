#ifndef MANAGER_H
#define MANAGER_H

#include <chrono>
#include <vector>
#include <memory>
#include <mutex>

#include "client.h"

struct StorageItem {
    std::shared_ptr<Client> client;
    std::chrono::time_point<std::chrono::system_clock> lastOnline;
};

typedef std::vector<StorageItem> Storage;

class Manager {
public:
    static Manager& Instance() {
        static Manager instance_;
        return instance_;
    }

    Manager(Manager const&) = delete;
    Manager(Manager&&) = delete;
    Manager& operator=(Manager const&) = delete;
    Manager& operator=(Manager&&) = delete;

    void update(const Client& client);

protected:
    Manager();
    ~Manager();

private:
    static std::once_flag flag_;
    static std::mutex mutex_;
    static std::shared_ptr<Manager> instance_;

    std::unique_ptr<Storage> storage_;
};

#endif