#include <algorithm>
#include <cassert>
#include <vector>

int main() {
    std::vector v{1, 2, 2, 3};
    std::vector<std::vector<int>> answer;

    // TODO: few lines of code populating answer with all permutations of v.

    assert((answer == std::vector<std::vector<int>>{
                          {1, 2, 2, 3},
                          {1, 2, 3, 2},
                          {1, 3, 2, 2},
                          {2, 1, 2, 3},
                          {2, 1, 3, 2},
                          {2, 2, 1, 3},
                          {2, 2, 3, 1},
                          {2, 3, 1, 2},
                          {2, 3, 2, 1},
                          {3, 1, 2, 2},
                          {3, 2, 1, 2},
                          {3, 2, 2, 1},
                      }));
}
