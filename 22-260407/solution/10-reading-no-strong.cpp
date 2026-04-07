#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>

void read_vector_to(std::istream &is, std::vector<int> &out) {
    int n;
    is >> n;
    // Providing strong exception guarantee.
    // Phase I: doing things which may throw, not touching the old data.
    std::vector<int> buffer(n);
    for (int &value : buffer) {
        is >> value;
    }
    // Phase II: update the new data.
    out = std::move(buffer);
    // TODO: can we roll back `is`? We can't. So not really a strong guarantee.
}

int main() {
    std::vector vec{5};
    
    std::stringstream str("3\n10 20 30\n4\n1 2");
    str.exceptions(std::ios_base::failbit | std::ios_base::badbit);
    read_vector_to(str, vec);
    assert((vec == std::vector{10, 20, 30}));

    try {
        read_vector_to(str, vec);
        assert(false);
    } catch (std::ios_base::failure &) {
        // As expected
    }
    std::cout << "vec after failure:";
    for (int value : vec) {
        std::cout << " " << value;
    }
    std::cout << "\n";
    assert((vec == std::vector{10, 20, 30}));
}
