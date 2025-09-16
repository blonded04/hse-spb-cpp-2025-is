#include <assert.h>
#include <stdio.h>

#include "security.h"
#include "computations.h"

int main(void) {
    int err = obtain_secure_access();
    if (err != 0) {
        return 1;
    }

    int secret = calculate_secret();
    assert(secret == 2006);
    printf("OK\n");

    return 0;
}