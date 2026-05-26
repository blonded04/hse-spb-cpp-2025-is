#include <cassert>
#include <iostream>
#include <tuple>
#include <type_traits>

template<typename, typename>
struct my_tuple_cat {
};

template<typename ...As, typename ...Bs>
struct my_tuple_cat<std::tuple<As...>, std::tuple<Bs...>> {
    using type = std::tuple<As..., Bs...>;
};

int main() {
    static_assert(std::is_same_v<
        std::tuple<int, char, void, int>,
        typename my_tuple_cat<
            std::tuple<int, char>,
            std::tuple<void, int>
        >::type
    >);
    std::cout << "OK\n";
}
