#include <iostream>
#include <thread>
#include "CopyOnWriteVector.h"

CopyOnWriteVector<int> cowVec;

void writer(int id) {
    for (int i = 0; i < 10; ++i) {
        cowVec.push_back(id * 10 + i);
    }
    std::cout << "Writer " << id << " done\n";
}

void reader() {
    auto snap = cowVec.snapshot();  // 获取一致性快照
    std::cout << "Snapshot size: " << snap.size() << "\n";
    for (int val : snap) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

int main() {
    std::thread w1(writer, 1);
    std::thread w2(writer, 2);
    std::thread r1(reader);
    std::thread r2(reader);

    w1.join();
    w2.join();
    r1.join();
    r2.join();

    return 0;
}
//
// Created by Administrator on 2026/5/7.
//
