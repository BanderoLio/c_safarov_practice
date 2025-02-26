#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main() {
    char message[101];
    fgets(message, 100, stdin);
    const char* c = message;
    for (; *c == '#' || *c == '*'; ++c) {}
    const char* end = message + strlen(message) - 1 - 1;
    for (; *end == '#' || *end == '*'; --end) {}
    char buff[101];
    strncpy(buff, c, end - c + 1);
    printf("Message: %s\nlen: %ld", buff, end - c + 1);
}