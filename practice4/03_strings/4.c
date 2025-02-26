#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main() {
    char code[255];
    fgets(code, 255, stdin);
    code[strcspn(code, "\n")] = '\0';
    if (!strcasecmp(code, "LAUNCH-2025"))
        puts("Код принят");
    else
        puts("Ошибка: неверный код!");
}