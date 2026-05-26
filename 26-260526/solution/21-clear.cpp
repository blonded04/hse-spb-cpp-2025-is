#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

template<typename T>
void clear(T &) {
    // Do nothing
}

template<typename T>
void clear(T *&ptr) {
    delete ptr;
    ptr = nullptr;
}

template<typename T>
void clear(std::unique_ptr<T> &ptr) {
    ptr.reset();
}

template<typename T>
void clear(std::shared_ptr<T> &ptr) {
    ptr.reset();
}

template<typename T>
void clear(std::vector<T> &v) {
    v.clear();
}

int main() {
    {
        std::string *x = new std::string("hello world this is a very long string");
        clear(x);
        assert(x == nullptr);
    }
    {
        std::unique_ptr<int> x(new int(10));
        clear(x);
        assert(x == nullptr);
    }
    {
        std::shared_ptr<int> x(new int(10));
        clear(x);
        assert(x == nullptr);
    }
    {
        std::vector<int> x(10);
        clear(x);
        assert(x.empty());
    }
    std::cout << "OK\n";
}
