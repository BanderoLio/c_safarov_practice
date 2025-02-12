#include <stdlib.h>
#include <stdio.h>


int main() {
    float oxygen;
    scanf("%f", &oxygen);
    if (oxygen < 15) {
        puts("Wrong oxygen percentage: we are dying");
        return 0;
    }
    puts("Correct oxygen");
}