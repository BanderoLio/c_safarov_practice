#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char name[20];
    int age;
    float average;
} Student;

int main() {
    int n;
    scanf("%d", &n);
    Student* students = (Student*) malloc(sizeof(Student) * n); // <- Только так с динамическими массивами
    for (int i = 0; i < n; ++i) {
        scanf("%s%d%f", students[i].name, &students[i].age, &students[i].average);
    }
    for (int i = 0; i < n; ++i) {
        printf("Name: %s\nAge: %d\nGPA: %f\n", students[i].name, students[i].age, students[i].average);
    }
    free(students);
}
