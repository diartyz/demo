#include <chrono>
#include <condition_variable>
#include <fstream>
#include <iostream>
#include <mutex>
#include <ostream>
#include <queue>
#include <string>
#include <thread>
#include <vector>

#include "fmt/format.h"

class Logger {
public:
    Logger();
    Logger(const Logger& src) = delete;
    Logger& operator=(const Logger& src) = delete;
    virtual ~Logger();
    void log(std::string entry);

private:
    void processEntries();
    void processEntriesHelper(std::queue<std::string>& queue, std::ofstream& ofs) const;
    std::mutex mutex_;
    std::condition_variable cv_;
    std::queue<std::string> queue_;
    std::thread thread_;
    bool exit_{false};
};

Logger::Logger()
{
    thread_ = std::thread(&Logger::processEntries, this);
}

Logger::~Logger()
{
    {
        std::unique_lock<std::mutex> lock{mutex_};
        exit_ = true;
    }
    cv_.notify_all();
    thread_.join();
}

void Logger::log(std::string entry)
{
    std::unique_lock lock(mutex_);
    queue_.push(std::move(entry));
    cv_.notify_all();
}

void Logger::processEntries()
{
    std::ofstream logFile{"log.txt"};
    if (logFile.fail()) {
        std::cerr << "Failed to open log file" << std::endl;
        return;
    }

    std::unique_lock lock{mutex_, std::defer_lock};
    while (true) {
        lock.lock();
        if (exit_) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            processEntriesHelper(queue_, logFile);
            break;
        } else {
            cv_.wait(lock);
        }
        std::queue<std::string> localQueue;
        localQueue.swap(queue_);
        lock.unlock();
        processEntriesHelper(localQueue, logFile);
    }
}

void Logger::processEntriesHelper(std::queue<std::string>& queue, std::ofstream& ofs) const
{
    while (!queue.empty()) {
        ofs << queue.front() << std::endl;
        queue.pop();
    }
}

void logSomeMessages(int id, Logger& logger)
{
    for (int i{0}; i < 10; ++i) {
        logger.log(fmt::format("Log Entry {} from thread {}", i, id));
    }
}

int main()
{
    Logger logger;
    std::vector<std::thread> threads;
    for (int i{0}; i < 10; ++i) {
        threads.emplace_back(logSomeMessages, i, std::ref(logger));
    }
    for (auto& t : threads) {
        t.join();
    }
}
