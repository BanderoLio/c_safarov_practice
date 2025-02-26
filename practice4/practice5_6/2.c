#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef char* (*func_t)(char*);

typedef struct {
    const char* name;
    func_t func;    
} Command;


// Returns first *space occurance
char* removeSpaces(char* s) {
    char* not_null = s;
    for (char* iter = s; *iter != '\0'; ++iter) {
        if (*iter != ' ') {
            char temp = *iter;
            *iter = *not_null;
            *not_null = temp;
            ++not_null;
        } 
    }
    *not_null = '\0';
    return not_null;
}

char* replaceVowels(char* s) {
    for (char* iter = s; *iter != '\0'; ++iter) {
        if (strchr("aiuoe", tolower(*iter))) {
            *iter = '*';
        }
    }
    return s;
}

char* invertRegister(char* s) {
    for (char* iter = s; *iter != '\0'; ++iter) {
        if (islower(*iter)) {
            *iter = toupper(*iter);
        }
        else if (isupper(*iter)) {
            *iter = tolower(*iter);
        }
    }
    return s;
}

int main() {   
    Command commands[] = {
        {"removeSpaces", removeSpaces},
        {"replaceVowels", replaceVowels},
        {"invertRegister", invertRegister}
    };
    char str[2048];
    printf("Enter string to modify: ");
    fgets(str, 2048, stdin); 
    char command[256];
    while (1) {
        printf("Enter your command:\nto remove spaces: removeSpaces\nto replace vowels: replaceVowels\nto invert register: invertRegister\nto get result: apply\nInput: ");
        scanf("%s", command);
        if (!strcmp(command, "apply")) {
            printf("Result: %s", str);
            return 0;
        }
        for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); ++i) {
            if (!strcmp(command, commands[i].name)) {
                commands[i].func(str);
                break;
            }
        }

    }
}