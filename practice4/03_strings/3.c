#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main() {
    char names[2048];
    fgets(names, 2048, stdin);
    names[strcspn(names, "\n")] = '\0';
    char* token;
    token = strtok(names, ";");
    while (token) {
        printf("%s\n", token);
        token = strtok(NULL, ";");
    }
    // Own solution
    // const char* prev = names;
    // char surname[128];
    // for (const char* c = names; *c != '\0'; ++c) {
    //     if (*c == ';' && c != prev) {
    //         strncpy(surname, prev, c - prev);
    //         surname[c - prev] = '\0';
    //         printf("%s\n", surname);
    //         prev = c + 1;
    //     }
    // }
    // if (*prev != '\0' && *prev != '\n')
    //     printf("%s", prev);
 
}