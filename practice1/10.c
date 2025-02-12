#include <stdio.h>
#include <stdlib.h>


int main() {
    int t;
    scanf("%d", &t);
    if (t < -150 || t > 120) {
        puts("Wrong temperature");
        return 0;
    }
    puts("Correct temperature");
} 