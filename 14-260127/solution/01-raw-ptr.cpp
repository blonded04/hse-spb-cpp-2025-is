#include <cassert>
#include <iostream>

struct Node {
    int data;
    Node *next = nullptr;

    Node(int data_) : data(data_) {}
    Node(int data_, Node *next_) : data(data_), next(next_) {}

    ~Node() {
        delete next;  // nullptr is ok.
    }
};

Node *cons(int data, Node *next) {
    return new Node(data, next);
}

void print_all(Node *v) {
    std::cout << v->data;
    if (v->next) {
        std::cout << ", ";
        print_all(v->next);
    }
}

int main() {
    Node *a = new Node(10);
    Node *b = new Node(20, new Node(30, new Node(40)));

    assert(a->data == 10);
    assert(a->next == nullptr);

    assert(b->data == 20);
    assert(b->next->data == 30);
    assert(b->next->next->data == 40);
    assert(b->next->next->next == nullptr);

    print_all(b);  // 20, 30, 40
    std::cout << "\n";
    delete b;

    Node *c = cons(50, a);
    a = nullptr;

    assert(c->data == 50);
    assert(c->next->data == 10);
    assert(c->next->next == nullptr);

    delete c;
    delete a;
}
