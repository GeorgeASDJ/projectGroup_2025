#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <stdexcept>

namespace my_vector {

template <typename T>
class vector {
private:
    T* data_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;

public:
    vector() = default;

    explicit vector(size_t count, const T& value = T()) {
        reserve(count);
        for (size_t i = 0; i < count; ++i) {
            data_[i] = value;
        }
        size_ = count;
    }

    vector(std::initializer_list<T> init) {
        reserve(init.size());
        for (const auto& item : init) {
            data_[size_++] = item;
        }
    }

    vector(const vector& other) {
        reserve(other.capacity_);
        for (size_t i = 0; i < other.size_; ++i) {
            data_[i] = other.data_[i];
        }
        size_ = other.size_;
    }

    vector(vector&& other) noexcept
        : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    ~vector() {
        delete[] data_;
    }

    vector& operator=(const vector& other) {
        if (this != &other) {
            delete[] data_;
            data_ = nullptr;
            capacity_ = 0;
            size_ = 0;

            reserve(other.capacity_);
            for (size_t i = 0; i < other.size_; ++i) {
                data_[i] = other.data_[i];
            }
            size_ = other.size_;
        }
        return *this;
    }

    vector& operator=(vector&& other) noexcept {
        if (this != &other) {
            delete[] data_;
            data_ = other.data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.data_ = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }
        return *this;
    }

    T& operator[](size_t index) {
        return data_[index];
    }

    const T& operator[](size_t index) const {
        return data_[index];
    }

    T& at(size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    const T& at(size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    T& front() {
        return data_[0];
    }

    const T& front() const {
        return data_[0];
    }

    T& back() {
        return data_[size_ - 1];
    }

    const T& back() const {
        return data_[size_ - 1];
    }

    T* data() noexcept {
        return data_;
    }

    const T* data() const noexcept {
        return data_;
    }

    T* begin() noexcept {
        return data_;
    }

    const T* begin() const noexcept {
        return data_;
    }

    T* end() noexcept {
        return data_ + size_;
    }

    const T* end() const noexcept {
        return data_ + size_;
    }

    bool empty() const noexcept {
        return size_ == 0;
    }

    size_t size() const noexcept {
        return size_;
    }

    size_t capacity() const noexcept {
        return capacity_;
    }

    void reserve(size_t new_capacity) {
        if (new_capacity <= capacity_) return;

        T* new_data = new T[new_capacity];

        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }

        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }

    void clear() noexcept {
        size_ = 0;
    }

    void push_back(const T& value) {
        if (size_ >= capacity_) {
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        data_[size_++] = value;
    }

    void pop_back() {
        if (size_ > 0) {
            --size_;
        }
    }

    void resize(size_t new_size, const T& value = T()) {
        if (new_size > size_) {
            reserve(new_size);
            for (size_t i = size_; i < new_size; ++i) {
                data_[i] = value;
            }
        }
        size_ = new_size;
    }
};

}

#endif