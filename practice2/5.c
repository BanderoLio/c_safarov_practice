#include <stdio.h>
#include <stdlib.h>


union Data {
    int n;
    char str[255];
    double n_d;
};


typedef enum {
    INT=1, DOUBLE, STR   
} Type;

int main() {
    int type;
    scanf("%d", &type);
    Type t = INT;
    if (type >= 1 && type <= 3)
        t = (Type) type;
    union Data data;
    if (t == INT) {
        scanf("%d", &data.n);
        printf("Integer: %d", data.n);
    }
    else if (t == DOUBLE) {
        scanf("%lf", &data.n_d);
        printf("Float: %lf", data.n_d);
    }
    else if (t == STR) {
        scanf("%s", data.str);
        printf("String: %s\n", data.str);
    }
}