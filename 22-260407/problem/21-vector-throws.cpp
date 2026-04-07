#include <vector>

void vector_throws_in_ctor() {
    // TODO: make this function provide basic exception safety
    int *data = new int[10];
    [[maybe_unused]] std::vector<int> tmp(10);
    delete[] data;
}

void vector_throws_in_assignment() {
    // TODO: make this function provide basic exception safety
    std::vector<int> tmp;
    int *data = new int[10];
    tmp = {1, 2, 3};
    delete[] data;
}

int main() {
    vector_throws_in_ctor();
    vector_throws_in_assignment();
}
