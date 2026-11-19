#include <stdio.h>

extern int shared;

int value(void);

int main(void) {
    printf("%d\n", value());
    return 0;
}
