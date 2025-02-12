#include <stdio.h>
#include <stdlib.h>


int main() {
    int M, speed;
    puts("Enter speed in kbit/s");
    scanf("%d", &speed);
    scanf("%d", &M);
    printf("Minutes to transfer: %d", (int) (M / ((float)speed / 8 / 1000)));
}