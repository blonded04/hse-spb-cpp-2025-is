#ifndef SECURITY_H_INCLUDED_
#define SECURITY_H_INCLUDED_

#include "util.h"

#define MY_SECURE_KEY 239

// returns 0 on success, and non-zero number on failure
int obtain_secure_access(void) {
    if (get_secure_key() == MY_SECURE_KEY) {
        return 0;
    }

    return 1;
}

#endif  // SECURITY_H_INCLUDED_
