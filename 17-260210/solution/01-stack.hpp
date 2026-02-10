#ifndef STACK_H_
#define STACK_H_

#include <vector>
#include <utility>

// templates are always in headers
template<typename T>
struct stack {
private:
    std::vector<T> data;

public:
    // Alternative: make two versions: push(const T&) and push(T &&): one less dtor call, one less move. But more code.
    void push(T value) {
        data.push_back(value);
    }

    T pop() {
        T value = std::move(data.back());
        data.pop_back();
        return value;
    }
};

#endif  // STACK_H_