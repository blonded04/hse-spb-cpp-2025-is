#include "storage.hpp"

namespace exercise {
std::vector<int> &get_numbers() {
    static std::vector<int> numbers;
    return numbers;
}
}  // namespace exercise
