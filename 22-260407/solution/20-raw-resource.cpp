#include <cstddef>
#include <exception>
#include <iostream>
#include <memory>
#include <vector>

// All code below (except print()) already provides strong exception safety.
struct data_holder {
    virtual void print(std::ostream &os) const = 0;
    virtual ~data_holder() = default;
};

struct int_holder : data_holder{
    int data;

    int_holder(std::istream &is) {
        is >> data;
    }

    void print(std::ostream &os) const override {
        os << data;
    }
};

struct vector_int_holder : data_holder {
    std::vector<int> data;

    vector_int_holder(std::istream &is) {
        int n;
        is >> n;
        data.resize(n);
        for (int &value : data)
            is >> value;
    }

    void print(std::ostream &os) const override {
        os << data.size();
        for (const int &value : data)
            os << ' ' << value;
    }
};

void read_print() {
    auto d1 = std::make_unique<int_holder>(std::cin);
    auto d2 = std::make_unique<vector_int_holder>(std::cin);
    d1->print(std::cout);
    std::cout << "\n";
    d2->print(std::cout);
    std::cout << "\n";
}

int main() {
    std::cin.exceptions(std::ios_base::failbit | std::ios_base::badbit);
    try {
        read_print();
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << "\n";
    }
}
