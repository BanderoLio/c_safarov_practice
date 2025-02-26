#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main() {
    int n;
    scanf("%d", &n);
    char ships[n][51];
    for (int i = 0; i < n; ++i) {
        scanf("%s", ships[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (!strncmp(ships[i], "SS", 2)) {
            printf("Found SS in ship: %s\n", ships[i]);
            return 0;
        }
    }
    puts("Not found");
}