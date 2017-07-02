#include <chrono>
#include <vector>
#include <memory>

#include "client.h"

struct StorageItem {
    std::shared_ptr<Client> client;
    std::chrono::time_point lastOnline;
};

typedef std::vector<StorageItem> Storage;

class Manager {
public:
    static Manager& Instance() {
        std::lock_guard<std::mutex> lock(mutex_);

        std::call_once(flag_, [&](){
           instance_.reset(new Manager);
        });
        return *instance_.get();
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
    static std::unique_ptr<Manager> instance_;

    std::unique_ptr<Storage> storage_;
};