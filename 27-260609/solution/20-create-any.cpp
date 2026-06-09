#include <cassert>
#include <memory>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

struct any {
    template<typename T>
    any(T other) : data(std::make_unique<any_data<T>>(std::move(other))) {}

    std::string to_string() const {
        return data->to_string();
    };

private:
    struct any_base {
        virtual std::string to_string() const = 0;
        virtual ~any_base() = default;
    };

    template<typename T>
    struct any_data : any_base {
        T data;
        any_data(T data_) : data(std::move(data_)) {}
        virtual std::string to_string() const {
            std::stringstream s;
            s << data;
            return s.str();
        }
    };

    std::unique_ptr<any_base> data;
};

any generate() {
    static int x = 0;
    switch (x++) {
    case 0: return std::string("hello");
    case 1: return std::string(100, 'x');
    case 2: return 239017;
    default: assert(false);
    }
}

int main() {
    {
        any a = generate();
        assert(a.to_string() == "hello");
    }
    {
        any a = generate();
        assert(a.to_string() == std::string(100, 'x'));
    }
    {
        any a = generate();
        assert(a.to_string() == "239017");
    }
    std::cout << "OK\n";
}
