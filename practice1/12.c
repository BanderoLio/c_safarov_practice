#include <stdio.h>
#include <stdlib.h>


int main() {
    int n;
    scanf("%d", &n);
    if (n < -180 || n > 180) {
        puts("Wrong angle");
        return 0;
    }
    puts("Correct angle");
}