#include <cassert>
#include <numeric>

struct ratio {
private:
    // The following ensures that there is only a single representation:
    // 1. denom > 0
    // 2. gcd(num, denom) == 1.
    int num;
    int denom;

public:
    ratio(int num_ = 0, int denom_ = 1) {
        num = num_;
        denom = denom_;

        // Normalization
        int d = std::gcd(num, denom);
        num /= d;
        denom /= d;
        if (denom < 0) {
            num = -num;
            denom = -denom;
        }
        assert(denom > 0);
    }

    int numerator() const {
        return num;
    }

    int denominator() const {
        return denom;
    }
};

ratio operator*(const ratio &a, const ratio &b) {
    return ratio(a.numerator() * b.numerator(),
                 a.denominator() * b.denominator());
}

ratio &operator*=(ratio &a, const ratio &b) {
    return a = a * b;
}
