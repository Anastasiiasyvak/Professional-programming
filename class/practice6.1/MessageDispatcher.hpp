#pragma once

#include <functional>
#include <string>
#include <vector>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <thread>

struct GreenMessage {
    std::string message;
    int counter;
};

struct BlueMessage {
    double value1;
    double value2;
};

struct OrangeMessage {
    std::string message1;
    std::string message2;
    int number;
    double value;
};

class MessageDispatcher {
public:
    MessageDispatcher() : stop(false) {
        workerThread = std::thread(&MessageDispatcher::processMessages, this);
    }

    ~MessageDispatcher() {
        {
            std::lock_guard<std::mutex> lock(queueMutex);
            stop = true;
        }
        cv.notify_all();
        if (workerThread.joinable()) {
            workerThread.join();
        }
    }

    void subscribeGreen(const std::function<void(const GreenMessage&)>& subscriber) {
        std::lock_guard<std::mutex> lock(subscribersMutex);
        greenSubscribers.push_back(subscriber);
    }

    void subscribeBlue(const std::function<void(const BlueMessage&)>& subscriber) {
        std::lock_guard<std::mutex> lock(subscribersMutex);
        blueSubscribers.push_back(subscriber);
    }

    void subscribeOrange(const std::function<void(const OrangeMessage&)>& subscriber) {
        std::lock_guard<std::mutex> lock(subscribersMutex);
        orangeSubscribers.push_back(subscriber);
    }

    void publish(const GreenMessage& message) {
        {
            std::lock_guard<std::mutex> lock(queueMutex);
            greenMessages.push(message);
        }
        cv.notify_all();
    }

    void publish(const BlueMessage& message) {
        {
            std::lock_guard<std::mutex> lock(queueMutex);
            blueMessages.push(message);
        }
        cv.notify_all();
    }

    void publish(const OrangeMessage& message) {
        {
            std::lock_guard<std::mutex> lock(queueMutex);
            orangeMessages.push(message);
        }
        cv.notify_all();
    }

private:
    void processMessages() {
        while (true) {
            std::unique_lock<std::mutex> lock(queueMutex);
            cv.wait(lock, [this] { return !greenMessages.empty() || !blueMessages.empty() || !orangeMessages.empty() || stop; });

            if (stop && greenMessages.empty() && blueMessages.empty() && orangeMessages.empty()) {
                break;
            }

            if (!greenMessages.empty()) {
                GreenMessage message = greenMessages.front();
                greenMessages.pop();
                lock.unlock();
                notifySubscribers(message);
                lock.lock();
            }

            if (!blueMessages.empty()) {
                BlueMessage message = blueMessages.front();
                blueMessages.pop();
                lock.unlock();
                notifySubscribers(message);
                lock.lock();
            }

            if (!orangeMessages.empty()) {
                OrangeMessage message = orangeMessages.front();
                orangeMessages.pop();
                lock.unlock();
                notifySubscribers(message);
                lock.lock();
            }
        }
    }

    void notifySubscribers(const GreenMessage& message) {
        std::lock_guard<std::mutex> lock(subscribersMutex);
        for (const auto& subscriber : greenSubscribers) {
            subscriber(message);
        }
    }

    void notifySubscribers(const BlueMessage& message) {
        std::lock_guard<std::mutex> lock(subscribersMutex);
        for (const auto& subscriber : blueSubscribers) {
            subscriber(message);
        }
    }

    void notifySubscribers(const OrangeMessage& message) {
        std::lock_guard<std::mutex> lock(subscribersMutex);
        for (const auto& subscriber : orangeSubscribers) {
            subscriber(message);
        }
    }

    std::vector<std::function<void(const GreenMessage&)>> greenSubscribers;
    std::vector<std::function<void(const BlueMessage&)>> blueSubscribers;
    std::vector<std::function<void(const OrangeMessage&)>> orangeSubscribers;

    std::queue<GreenMessage> greenMessages;
    std::queue<BlueMessage> blueMessages;
    std::queue<OrangeMessage> orangeMessages;

    std::mutex queueMutex;
    std::mutex subscribersMutex;
    std::condition_variable cv;
    std::thread workerThread;
    bool stop;
};

