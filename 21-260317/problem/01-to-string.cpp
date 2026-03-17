#include <cassert>
#include <vector>
#include <string>
#include <sstream>

using Container = std::vector<int>;
using ContainerIterator = Container::iterator;

std::string to_string(ContainerIterator begin, ContainerIterator end) {
    // TODO: implement the function without changing its signature (arguments and return type)
    // The implementation may only use Container/ContainerIterator types, do not
    // rely on iterators being vector's iterators.
}

int main() {
    Container data = {1, 2, 3, 4, 5};

    assert(to_string(data.begin(), data.end()) == "{1, 2, 3, 4, 5}");
    assert(to_string(data.begin() + 2, data.end() - 1) == "{3, 4}");
    assert(to_string(data.end(), data.end()) == "{}");
    assert(to_string(data.begin() + 2, data.begin() + 2) == "{}");
}
