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
    std::vector<std::unique_ptr<Value>> values;
    // values{make_unique<IntValue>(12), make_unique<StringValue>(...), ....} does not work,
    // because initialization lists do not work with move-only values.
    values.push_back(std::make_unique<IntValue>(12));
    values.push_back(std::make_unique<StringValue>("hello"));
    values.push_back(std::make_unique<IntValue>(45));
    std::string result = "";
    for (const auto &v : values) {
        result += v->to_string();
    }
    assert(result == "12hello45");
    std::cout << "OK\n";
}
