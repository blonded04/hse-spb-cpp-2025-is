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

    // TODO: implement emplace() which accepts arbitrary number of arguments.
    template<typename ...Args>
    void emplace(Args&&... args) {
        reset();
        new(storage) T(std::forward<Args>(args)...);
        created = true;
    }
};


int main() {
    optional<std::tuple<int, std::string&, std::unique_ptr<int>>> opt;
    const int x = 10;
    std::string y = "hello";
    opt.emplace(x, y, std::make_unique<int>(20));
    assert(std::get<0>(opt.value()) == 10);
    assert(&std::get<1>(opt.value()) == &y);
    assert(*std::get<2>(opt.value()) == 20);
    std::cout << "OK\n";
}
