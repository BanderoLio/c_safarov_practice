#include <stdio.h>
#include <stdlib.h>


int main() {
    double T;
    scanf("%lf", &T);
    printf("Time: %d mins %f seconds\n", (int) T / 60, T - ((int) T/60) * 60);
}