#include <cassert>
#include <cstddef>
#include <iostream>
#include <string>

// There is literally no way to "index" the parameter pack. Recursion via specialization only:
template<typename... Ts>
struct tuple {};

template<typename Head, typename... Tail>
struct tuple<Head, Tail...> {  // For non-empty lists.
    Head head{};
    tuple<Tail...> tail;  // Some use inheritance instead so EBO (Empty Base Optimization) is enabled.
};

#ifdef __cpp_if_constexpr
#error Use C++14, disable if constexpr!
#endif

template<std::size_t I, typename ...Ts>
struct get_helper {};

template<typename T, typename ...Ts>
struct get_helper<0, T, Ts...> {
    static auto &get(tuple<T, Ts...> &t) {
        return t.head;
    }
};

template<std::size_t I, typename T, typename ...Ts>
struct get_helper<I, T, Ts...> {
    static auto &get(tuple<T, Ts...> &t) {
        return get_helper<I - 1, Ts...>::get(t.tail);
    }
};

template<std::size_t I, typename ...Ts>
auto &get(tuple<Ts...> &t) {
    return get_helper<I, Ts...>::get(t);
}

int main() {
    tuple<int, std::string> x;
    assert(get<0>(x) == 0);
    assert(get<1>(x) == "");
    get<0>(x) = 10;
    get<1>(x) = "hello";
    assert(get<0>(x) == 10);
    assert(get<1>(x) == "hello");
    std::cout << "OK\n";
}
