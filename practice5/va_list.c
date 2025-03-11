#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>


long long sum(int count, ...) {
    va_list args;
    va_start(args, count);
    long long res = 0;
    for (int i = 0; i < count; ++i) {
        res += va_arg(args, int); // И тут надо с типом угадать побайтово...
    }
    va_end(args);
    return res;
}


int main() {
    printf("%lld\n", sum(9,2,3,4,5,6,7,8,9,10));
}