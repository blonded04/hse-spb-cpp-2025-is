#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

struct Node {
    int data;
    std::unique_ptr<Node> next;  // nullptr by default.

    Node(int data_) : data(data_) {}
    Node(int data_, TODO next_) : data(data_), next(TODO) {}

    // No destructor needed, it's automatic.
};

std::unique_ptr<Node> cons(int data, TODO next) {
    return std::make_unique<Node>(data, TODO);
}

void print_all(Node *v) {
    std::cout << v->data;
    if (v->next) {
        std::cout << ", ";
        print_all(v->next.get());
    }
}

int main() {
    std::unique_ptr<Node> a = std::make_unique<Node>(10);
    std::unique_ptr<Node> b = TODO;

    assert(a->data == 10);
    assert(a->next == nullptr);

    assert(b->data == 20);
    assert(b->next->data == 30);
    assert(b->next->next->data == 40);
    assert(b->next->next->next == nullptr);

    print_all(TODO);  //  20, 30, 40
    std::cout << "\n";
    /*
    // TODO: 1. Uncomment and fix compilation error.
    // TODO: 2. Ensure there are no memory leaks with Valgrind and/or Address Sanitizer.
    // TODO: 3. Understand why there is no double free like in the previous exercise.
    std::unique_ptr<Node> c = std::make_unique<Node>(50, a);

    assert(c->data == 50);
    assert(c->next->data == 10);
    assert(c->next->next == nullptr);
    */
}
