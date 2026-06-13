#include <cassert>
#include <iostream>
#include <memory>
#include <tuple>

template <typename T>
class optional {
    alignas(alignof(T)) unsigned char storage[sizeof(T)];
    bool created = false;

public:
    optional() = default;

    [[nodiscard]] T &value() & {
        return reinterpret_cast<T &>(storage);
    }

    optional(const optional &other) = delete;
    optional(optional &&other) = delete;
    optional &operator=(optional other) = delete;

    ~optional() {
        reset();
    }

    void reset() {
        if (created) {
            value().~T();
            created = false;
        }
    }

    template<typename T1, typename T2, typename T3>
    void emplace(T1 &&v1, T2 &&v2, T3 &&v3) {
        reset();
        new (&storage) T(std::forward<T1>(v1), std::forward<T2>(v2), std::forward<T3>(v3));
        created = true;
    }
};

int main() {
    {
        optional<std::tuple<int, std::string&, std::unique_ptr<int>>> opt;
        int x = 10;
        std::string y = "hello";
        opt.emplace(x, y, std::make_unique<int>(20));
        assert(std::get<0>(opt.value()) == 10);
        assert(&std::get<1>(opt.value()) == &y);
        assert(*std::get<2>(opt.value()) == 20);
    }
    {
        optional<std::tuple<int&, std::unique_ptr<int>, std::string>> opt;
        int x = 10;
        std::string y(1000, 'x');
        opt.emplace(x, std::make_unique<int>(20), y);
        assert(&std::get<0>(opt.value()) == &x);
        assert(*std::get<1>(opt.value()) == 20);
        assert(std::get<2>(opt.value()) == std::string(1000, 'x'));
        assert(y == std::string(1000, 'x'));
    }
    std::cout << "OK\n";
}
