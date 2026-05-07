//
// Created by Administrator on 2026/5/7.
//

#ifndef CPP_BASIC_COPYONWRITEVECTOR_H
#define CPP_BASIC_COPYONWRITEVECTOR_H

#endif //CPP_BASIC_COPYONWRITEVECTOR_H
#pragma once
#include <vector>
#include <memory>
#include <mutex>
#include <cstddef>

template<typename T>
class CopyOnWriteVector {
private:
    std::shared_ptr<std::vector<T>> data_;
    mutable std::mutex mutex_;

public:
    CopyOnWriteVector()
        : data_(std::make_shared<std::vector<T>>()) {}

    // 禁止拷贝构造和赋值（避免意外复制）
    CopyOnWriteVector(const CopyOnWriteVector&) = delete;
    CopyOnWriteVector& operator=(const CopyOnWriteVector&) = delete;

    // 允许移动语义
    CopyOnWriteVector(CopyOnWriteVector&&) = default;
    CopyOnWriteVector& operator=(CopyOnWriteVector&&) = default;

    // 写操作 - Copy-On-Write
    void push_back(const T& value) {
        std::lock_guard<std::mutex> lock(mutex_);
        auto new_data = std::make_shared<std::vector<T>>(*data_);
        new_data->push_back(value);
        data_ = new_data;
    } // ← 函数结束时，lock 对象被销毁，析构函数自动解锁！

    void clear() {
        std::lock_guard<std::mutex> lock(mutex_);
        data_ = std::make_shared<std::vector<T>>();
    }

    // 读操作 - 无锁快照
    std::vector<T> snapshot() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return *data_;
    }

    size_t size() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return data_->size();
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return data_->empty();
    }
};
