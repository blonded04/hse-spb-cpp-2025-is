#include <vector>

void vector_throws_in_ctor() {
    std::vector<int> data(10);
    [[maybe_unused]] std::vector<int> tmp(10);
}

void vector_throws_in_assignment() {
    std::vector<int> tmp;
    std::vector<int> data(10);
    tmp = {1, 2, 3};
}

int main() {
    vector_throws_in_ctor();
    vector_throws_in_assignment();
}
