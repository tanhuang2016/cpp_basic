//
// Created by Administrator on 2026/5/7.
//
#include <iostream>
#include <mutex>
#include <thread>

std::mutex coutMutex;
thread_local int threadSpecificVar = 0; // 每个线程都有自己的 threadSpecificVar

void threadFunction(int id) {
    threadSpecificVar = id; // 设置线程特有的变量
    std::lock_guard<std::mutex> lock(coutMutex);
    std::cout << "Thread " << id << ": threadSpecificVar = " << threadSpecificVar << std::endl;
}

int main() {
    std::thread t1(threadFunction, 1);
    std::thread t2(threadFunction, 2);

    t1.join();
    t2.join();
    // std::cout << "ok " << std::endl;

    return 0;
}