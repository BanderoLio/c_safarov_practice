#include <stdlib.h>
#include <stdio.h>


typedef struct {
    char name[128];
    int credits;
    char teacher[64];
} Course;


int main() {
    int n;
    scanf("%d", &n);
    Course courses[n];
    for (int i = 0; i < n; ++i) {
        scanf("%s%d%s", courses[i].name, &courses[i].credits, courses[i].teacher);
    }
    for (int i = 0; i < n; ++i) {
        printf("Course: %s\nCredits: %d\nProfessor: %s\n", courses[i].name, courses[i].credits, courses[i].teacher);
    }
}