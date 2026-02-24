#include "storage.hpp"

namespace exercise {
// TODO: edit the whole file

namespace {
std::vector<int> numbers;
}  // namespace

std::vector<int> &get_numbers() {
    return numbers;
}
}  // namespace exercise
