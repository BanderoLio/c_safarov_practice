#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union {
    int num;
    char str[64];
} Grade;

int main() {
    int n;
    scanf("%d", &n);
    char mark[64];
    int num;
    Grade grades[n];
    char types[n];
    
    for (int i = 0; i < n; ++i) {
        scanf("%s", mark);
        if (sscanf(mark, "%d", &num)) {
            grades[i].num = num;
            types[i] = 'i';
        }
        else {
            strcpy(grades[i].str, mark);
            types[i] = 's';
        }
    }
    for (int i = 0; i < n; ++i) {
        if (types[i] == 's') {
            printf("Grade: %s\n", grades[i].str);
        }
        else 
            printf("Grade: %d\n", grades[i].num);
    }
}