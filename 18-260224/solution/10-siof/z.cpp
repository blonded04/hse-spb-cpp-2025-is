#include "storage.hpp"

struct IniterZ {
    IniterZ() {
        exercise::get_numbers().push_back(100);
        exercise::get_numbers().push_back(200);
        exercise::get_numbers().push_back(300);
    }
} initer_z;
