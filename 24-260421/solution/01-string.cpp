#include <algorithm>
#include <cassert>
#include <cstring>
#include <cstddef>

struct string {
private:
    char *data;

public:
    string() : data(nullptr) {}
    string(const char *s) {
        if (!s) {
            data = nullptr;
            return;
        }
        std::size_t len = std::strlen(s);
        data = new char[len + 1];
        std::copy(s, s + len + 1, data);
    }

    // Can be one-liner.
    string(const string &other) : string() {
        *this = other;
    }

    string(string &&other) : data(std::exchange(other.data, nullptr)) {
    }

    string &operator=(const string &other) {
        if (this != &other) {
            // Can be one-liner.
            delete[] data;
            data = nullptr;
            if (other.data) {
                std::size_t len = std::strlen(other.data);
                data = new char[len + 1];
                std::copy(other.data, other.data + len + 1, data);
            }
        }
        return *this;
    }

    string &operator=(string &&other) {
        std::swap(data, other.data);
        return *this;
    }

    ~string() {
        delete[] data;
    }

    const char *c_str() const {
        return data;
    }
};

void expect_hello(string s) {
    assert(!std::strcmp(s.c_str(), "hello"));
}

int main() {
    assert(string().c_str() == nullptr);
    string s1 = "hello", s2 = "world2", s3 = "wow";
    assert(!std::strcmp(s1.c_str(), "hello"));
    assert(!std::strcmp(s2.c_str(), "world2"));
    assert(!std::strcmp(s3.c_str(), "wow"));
    expect_hello(s1);
    
    s1 = s2;
    assert(!std::strcmp(s1.c_str(), "world2"));
    assert(!std::strcmp(s2.c_str(), "world2"));
    assert(!std::strcmp(s3.c_str(), "wow"));

    s1 = std::move(s3);
    assert(!std::strcmp(s1.c_str(), "wow"));
    assert(!std::strcmp(s2.c_str(), "world2"));

    s1 = s1;
    // Spoilers: https://isocpp.org/wiki/faq/assignment-operators#self-assignment-what
    assert(!std::strcmp(s1.c_str(), "wow"));
    assert(!std::strcmp(s2.c_str(), "world2"));

    s1 = std::move(s1);  // Valid but unspecified state: https://stackoverflow.com/questions/13127455/what-does-the-standard-library-guarantee-about-self-move-assignment
    assert(!std::strcmp(s2.c_str(), "world2"));

    string s4 = "hello";
    expect_hello(std::move(s4));

    string s5 = s2, s6 = "botva";
    s6 = s2;
}
