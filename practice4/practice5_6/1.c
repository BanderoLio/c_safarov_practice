#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef char* (*func_t)(char*);

typedef struct {
    const char* name;
    func_t func;    
} Command;


char* upper(char* s) {
    char* iter = s;
    for (; iter != NULL && *iter != '\0'; ++iter) {
        *iter = toupper(*iter);
    }
    return s;
}

char* lower(char* s) {
    char* iter = s;
    for (; iter != NULL && *iter != '\0'; ++iter) {
        *iter = tolower(*iter);
    }
    return s;
}


char* reverse(char* s) {
    int n = strlen(s);
    for (int i = 0; i < n / 2; ++i)
    {
        char temp = s[i];
        s[i] = s[n - 1 - i];
        s[n - 1 - i] = temp;
    }
    return s;
}


char* exit_str(char* s) {
    return "exit";
}


int main() {   
    Command commands[] = {
        {"upper", upper},
        {"lower", lower},
        {"reverse", reverse},
        {"exit", exit_str}
    };
    char user_input[1024];
    while (1) {
        printf("Enter command: ");
        fgets(user_input, 1024, stdin);
        user_input[strcspn(user_input, "\n")] = '\0';
        if (!strncmp(user_input, "exit", 4)) {
            return 0;
        }
        char* space = strchr(user_input, ' '); 
        char* res = NULL;
        for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); ++i) {
            if (!strncmp(user_input, commands[i].name, space - user_input)) {
                res = commands[i].func(space + 1);
                break;
            }
        }
        if (!res) {
            puts("Command not found");
            continue;
        }
        printf("Result: %s\n", res);   
    }
}