#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char mark[50];
    char model[50];
    int year;
    enum Type {
        Gasoline, Diesel, Electric
    } type;
} Vehicle;


const char* type_to_str(enum Type type) {
    if (type == Gasoline)
        return "Gasoline";
    if (type == Diesel)
        return "Diesel";
    if (type == Electric)
        return "Electric";
    return "None";
}

int main() {
    int n;
    scanf("%d", &n);
    Vehicle vehicles[n];
    char cur_type[50];
    for (int i = 0; i < n; ++i) {
        scanf("%s%s%d%s", vehicles[i].mark, vehicles[i].model, &vehicles[i].year, cur_type);
        if (!strcmp(cur_type, "Electric")) {
            vehicles[i].type = Electric;
        }
        else if (!strcmp(cur_type, "Gasoline")) {
            vehicles[i].type = Gasoline;
        }
        else if (!strcmp(cur_type, "Diesel")) {
            vehicles[i].type = Diesel;
        }
        else puts("segfault of brain");
    }
    for (int i = 0; i < n; ++i) {
        printf("Vehicle: %s %s\nYear: %d\nEngine Type: %s\n", vehicles[i].mark, vehicles[i].model, vehicles[i].year, type_to_str(vehicles[i].type));
    }
}