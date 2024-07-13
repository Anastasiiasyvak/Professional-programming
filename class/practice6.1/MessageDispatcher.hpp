#ifndef MESSAGE_DISPATCHER_HPP
#define MESSAGE_DISPATCHER_HPP

#include <functional>
#include <string>
#include <vector>
#include <mutex>

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
    void subscribeGreen(const std::function<void(const GreenMessage&)>& subscriber) {
        std::lock_guard<std::mutex> lock(mutex_);
        greenSubscribers.push_back(subscriber);
    }

    void subscribeBlue(const std::function<void(const BlueMessage&)>& subscriber) {
        std::lock_guard<std::mutex> lock(mutex_);
        blueSubscribers.push_back(subscriber);
    }

    void subscribeOrange(const std::function<void(const OrangeMessage&)>& subscriber) {
        std::lock_guard<std::mutex> lock(mutex_);
        orangeSubscribers.push_back(subscriber);
    }

    void publish(const GreenMessage& message) {
        std::lock_guard<std::mutex> lock(mutex_);
        for (const auto& subscriber : greenSubscribers) {
            subscriber(message);
        }
    }

    void publish(const BlueMessage& message) {
        std::lock_guard<std::mutex> lock(mutex_);
        for (const auto& subscriber : blueSubscribers) {
            subscriber(message);
        }
    }

    void publish(const OrangeMessage& message) {
        std::lock_guard<std::mutex> lock(mutex_);
        for (const auto& subscriber : orangeSubscribers) {
            subscriber(message);
        }
    }

private:
    std::vector<std::function<void(const GreenMessage&)>> greenSubscribers;
    std::vector<std::function<void(const BlueMessage&)>> blueSubscribers;
    std::vector<std::function<void(const OrangeMessage&)>> orangeSubscribers;
    std::mutex mutex_;
};

#endif // MESSAGE_DISPATCHER_HPP

