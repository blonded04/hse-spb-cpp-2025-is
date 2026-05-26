#include <cassert>
#include <iostream>
#include <tuple>
#include <type_traits>

// TODO: implement my_tuple_cat<X, Y> which concatenates two tuples `A` and `B` and stores the result in `type`.
// Hint: implement all logic in a template specialization.

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
