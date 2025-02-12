#include <stdio.h>
#include <stdlib.h>


int main()
{
    float x;
    scanf("%f", &x);
    if (x < 2.5 || x > 3.5)
        puts("not in range");
        return 0;
    puts("in range");
}