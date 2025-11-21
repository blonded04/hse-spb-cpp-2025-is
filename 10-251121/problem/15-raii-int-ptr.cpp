#include <cassert>
#include <iostream>

class RaiiIntPtr {
private:
    int* m_value;

public:
    int& getValue() {
        return *m_value;
    }

    RaiiIntPtr()
        : m_value{nullptr}
    {}

    RaiiIntPtr(int value) {
        // TODO
    }

    ~RaiiIntPtr() {
        // TODO
    }
};

int main() {
    RaiiIntPtr ptr(4);

    assert(ptr.getValue() == 4);
    ptr.getValue() = 5;
    assert(ptr.getValue() == 5);
}
