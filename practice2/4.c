#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char name[50];
    char position[50];
    double salary;
} Employee;

int main() {
    int n;
    scanf("%d", &n);
    Employee employees[n];
    for (int i = 0; i < n; ++i) {
        scanf("%s%s%lf", employees[i].name, employees[i].position, &employees[i].salary);
    }
    for (int i = 0; i < n; ++i) {
        printf("Name: %s\nPosition: %s\nSalary: %.2f\n", employees[i].name, employees[i].position, employees[i].salary);
    }
}