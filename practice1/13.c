#include <stdio.h>
#include <stdlib.h>


int main() {
    int n;
    scanf("%d", &n);
    if (n % 2) {
        puts("Not possible");
        return 0;
    }
    puts("Possible");
}