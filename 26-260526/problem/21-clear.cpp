#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

// TODO: make sure 'clear' works as follows:
// 1. clear(unique_ptr &ptr) calls `reset()`
// 2. Same for `shared_ptr`
// 3. For `vector` it calls `clear()`
// 4. For raw pointer it calls `delete` (not `delete[]`) and sets the pointer to `nullptr`
// 5. For all other types it does nothing
template<typename T>
void clear(T &) {
    // Do nothing
}

int main() {
    {
        std::string *x = new std::string("hello world this is a very long string");
        clear(x);
        assert(x == nullptr);
    }
    {
        std::unique_ptr<int> x(new int(10));
        clear(x);
        assert(x == nullptr);
    }
    {
        std::shared_ptr<int> x(new int(10));
        clear(x);
        assert(x == nullptr);
    }
    {
        std::vector<int> x(10);
        clear(x);
        assert(x.empty());
    }
    std::cout << "OK\n";
}
