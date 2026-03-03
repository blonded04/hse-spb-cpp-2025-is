#include <cassert>
#include <iostream>
#include <optional>

template<typename T>
struct call_result_storage {
    std::optional<T> last_result;

    template<typename F>
    void call(F f) {
        last_result = f();
    }
};

template<>
struct call_result_storage<void> {
    template<typename F>
    void call(F f) {
        f();
    }
};

int main() {
    {
        call_result_storage<int> s;
        assert(!s.last_result);

        int calls = 0;

        s.call([&]() { calls++; return 10; });
        assert(s.last_result);
        assert(*s.last_result == 10);
        assert(calls == 1);

        s.call([&]() { calls++; return 20; });
        assert(s.last_result);
        assert(*s.last_result == 20);
        assert(calls == 2);
    }
    {
        call_result_storage<void> s;
        int calls = 0;
        s.call([&]() { calls++; });
        assert(calls == 1);
        s.call([&]() { calls++; });
        assert(calls == 2);
    }
    std::cout << "OK\n";
}
