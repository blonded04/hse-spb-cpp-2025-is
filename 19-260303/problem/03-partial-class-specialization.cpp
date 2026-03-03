#include <cassert>
#include <functional>
#include <iostream>
#include <vector>
#include <utility>

template<typename F>
struct caller {
    F f;
    caller(F f) : f(std::move(f)) {}
    void operator()() const {
        f();
    }
};

// TODO: specialize for F=std::vector<F>, operator() should call all elements in success

int main() {
    {
        int calls = 0;
        caller c([&]() {
            calls++;
        });
        assert(calls == 0);
        c();
        assert(calls == 1);
        c();
        assert(calls == 2);
    }
    {
        int calls = 0;
        caller c(std::vector<std::function<void()>>{
            [&]() { calls++; },
            [&]() { calls += 10; },
        });
        assert(calls == 0);
        c();
        assert(calls == 11);
        c();
        assert(calls == 22);
    }
    std::cout << "OK\n";
}
