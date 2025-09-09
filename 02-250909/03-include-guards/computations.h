#ifndef COMPUTATIONS_H_INCLUDED_
#define COMPUTATIONS_H_INCLUDED_

#include "util.h"

int calculate_secret(void) {
    return get_secure_key() * 9 - 145;
}

#endif  // COMPUTATIONS_H_INCLUDED_
