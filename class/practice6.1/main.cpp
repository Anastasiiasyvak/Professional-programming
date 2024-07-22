#include <iostream>
#include <thread>
#include <random>
#include <chrono>
#include <print>
#include "MessageDispatcher.hpp"

void generateMessages(MessageDispatcher& dispatcher, int threadId) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> msgTypeDist(0, 2);

    for (int i = 0; i < 10; ++i) {
        int msgType = msgTypeDist(gen);
        if (msgType == 0) {
            GreenMessage msg{"Hello from thread " + std::to_string(threadId), i};
            dispatcher.publish(msg);
        } else if (msgType == 1) {
            BlueMessage msg{static_cast<double>(i), static_cast<double>(i + 0.5)};
            dispatcher.publish(msg);
        } else {
            OrangeMessage msg{"Thread " + std::to_string(threadId) + " says", "Hi there!", i, static_cast<double>(i * 1.1)};
            dispatcher.publish(msg);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    MessageDispatcher dispatcher;

    dispatcher.subscribeGreen([](const GreenMessage& msg) {
        std::println("GreenMessage received: {}, counter: {}", msg.message, msg.counter);
    });

    dispatcher.subscribeBlue([](const BlueMessage& msg) {
        std::println("BlueMessage received: {}, {}", msg.value1, msg.value2);
    });

    dispatcher.subscribeOrange([](const OrangeMessage& msg) {
        std::println("OrangeMessage received: {}, {}, {}, {}", msg.message1, msg.message2, msg.number, msg.value);
    });

    std::thread thread1(generateMessages, std::ref(dispatcher), 1);
    std::thread thread2(generateMessages, std::ref(dispatcher), 2);

    thread1.join();
    thread2.join();

    return 0;
}

