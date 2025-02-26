#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main() {
    char original[201], copy[201];
    fgets(original, 201, stdin);
    original[strcspn(original, "\n")] = '\0';
    strncpy(copy, original, 200);
    printf("Оригинал: %s\nКопия: %s\n", original, copy);
}