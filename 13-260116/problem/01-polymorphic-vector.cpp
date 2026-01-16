#include <cassert>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

struct Value {
    virtual ~Value() = default;

    virtual std::string to_string() = 0;
};

struct IntValue : Value {
private:
    int value;

public:
    IntValue(int value_) : value(value_) {}
    std::string to_string() override {
        return std::to_string(value);
    }
};

struct StringValue : Value {
private:
    std::string value;

public:
    StringValue(std::string value_) : value(std::move(value_)) {}
    std::string to_string() override {
        return value;  // no std::move: we need a copy
    }
};

int main() {
    std::vector<TODO> values;
    values.push_back(IntValue(12));  // TODO
    values.push_back(StringValue("hello"));  // TODO
    values.push_back(IntValue(45));  // TODO
    std::string result = "";
    for (const auto &v : values) {
        result += v.to_string();  // TODO
    }
    assert(result == "12hello45");
    std::cout << "OK\n";
}
