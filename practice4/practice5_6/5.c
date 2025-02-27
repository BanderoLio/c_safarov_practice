#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main() {
    char command[1024];
    char* memory = NULL;
    unsigned long n;
    
    while (1) {
        fgets(command, 1024, stdin);
        command[strcspn(command, "\n")] = '\0';
        if (!strcmp(command, "free")) {
            free(memory);
            n = 0;
        }
        else if (!strcmp(command, "print")) {
            printf("%s\n", memory);
        }
        else if (!strcmp(command, "exit")) {
            if (n) {
                puts("Error: Memory not free");
                free(memory);
                return -1;
            }
            return 0;
        }
        else {
            char* space = strchr(command, ' ');
            if (!space) {
                puts("Wrong input: invalid syntax");
                if (n) free(memory);
                return -1;
            }
            if (!strncmp(command, "alloc", space - command)) {
                unsigned long size = 0;
                if (!sscanf(space + 1, "%lu", &size)) {
                    puts("Wrong input: size not recognized");
                    if (n) free(memory);
                    return -1;
                }
                memory = malloc(sizeof(char) * size);
                n = size;
            }
            else if (!strncmp(command, "write", space - command)) {
                unsigned long inp_size = strlen(space + 1);
                if (inp_size > n) {
                    printf("Wrong input: allocated %lu, but required %lu\n", n, inp_size);
                }
                strcpy(memory, space + 1);
            }
        }
    }
}