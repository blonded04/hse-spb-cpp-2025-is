#include "storage.hpp"

struct IniterA {
    IniterA() {
        exercise::get_numbers().push_back(10);
        exercise::get_numbers().push_back(20);
        exercise::get_numbers().push_back(30);
    }
} initer_a;
