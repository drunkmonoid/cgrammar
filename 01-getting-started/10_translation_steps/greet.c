// greet.c - a function defined in its own translation unit.

#include <stdio.h>

#include "greet.h"

void greet(const char *name) {
    printf(GREETING ", %s!\n", name);
}
