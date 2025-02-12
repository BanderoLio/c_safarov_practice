#include <stdlib.h>
#include <stdio.h>


int main() {
    int n;
    scanf("%d", n);
    if (!(n % 4)) {
        printf("Possible with size of %d\n", n / 4);
    }
    else {
        puts("Not possible");
    }
}