#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

struct Node {
    int data;
    std::unique_ptr<Node> next;  // nullptr by default.

    Node(int data_) : data(data_) {}
    Node(int data_, std::unique_ptr<Node> next_) : data(data_), next(std::move(next_)) {}

    // No destructor needed, it's automatic.
};

std::unique_ptr<Node> cons(int data, std::unique_ptr<Node> next) {
    return std::make_unique<Node>(data, std::move(next));
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
    std::unique_ptr<Node> b = std::make_unique<Node>(20, std::make_unique<Node>(30, std::make_unique<Node>(40)));

    assert(a->data == 10);
    assert(a->next == nullptr);

    assert(b->data == 20);
    assert(b->next->data == 30);
    assert(b->next->next->data == 40);
    assert(b->next->next->next == nullptr);

    print_all(b.get());  // 20, 30, 40
    std::cout << "\n";
    b.reset();

    std::unique_ptr<Node> c = std::make_unique<Node>(50, std::move(a));

    assert(c->data == 50);
    assert(c->next->data == 10);
    assert(c->next->next == nullptr);
}
