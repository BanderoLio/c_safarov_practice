#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char name[50];
    struct {
        int day;
        int month;
        int year;
    } date;
    char description[256];
} Event;

int main() {
    int n;
    scanf("%d", &n);
    Event* events = (Event*) malloc(sizeof(Event) * n);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d%d%d%255s", events[i].name, &events[i].date.day, &events[i].date.month, // теперь мы знаем, что лучше указывать число символов между % и s
         &events[i].date.year, events[i].description);
    }
    for (int i = 0; i < n; ++i) {
        printf("Event: %s\nDate: %d/%d/%d\nDescription: %s\n", events[i].name, events[i].date.day,
         events[i].date.month, events[i].date.year, events[i].description);
    }
    free(events);
}
