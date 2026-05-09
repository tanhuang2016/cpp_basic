//
// Created by Administrator on 2026/5/9.
//
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <thread>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;
std::mutex cout_mtx;  // 专门用于保护 cout 的互斥锁
void workerThread(int id) {
    {
        std::lock_guard<std::mutex> lock(cout_mtx);
        std::cout << "Worker " << id << ": Waiting for data..." << std::endl;
    }
    std::unique_lock<std::mutex> lk(mtx);
    cv.wait(lk, []{ return ready; }); // 等待条件
    // 当条件满足时执行工作
    {
        std::lock_guard<std::mutex> lock(cout_mtx);
        std::cout << "Worker " << id << ": Condition met! Working..." << std::endl;
    }

}

void mainThread() {
    {
        std::lock_guard<std::mutex> lk(mtx);
        // 准备数据
        ready = true;
    } // 离开作用域时解锁
    cv.notify_all(); // 通知一个等待的线程
}

int main() {
    // 创建多个工作线程
    std::thread t1(workerThread,1);
    std::thread t2(workerThread,2);
    std::thread t3(workerThread,3);

    std::this_thread::sleep_for(std::chrono::seconds(3));

    // 主线程准备数据
    mainThread();
    // 等待所有工作线程完成
    t1.join();
    t2.join();
    t3.join();


    std::cout << "All done!" << std::endl;
    return 0;
}