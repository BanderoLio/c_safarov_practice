#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char name[50];
    int amount;
    float cost;
} Item;

int main() {
    int n;
    scanf("%d", &n);
    Item* items = (Item*) malloc(sizeof(Item) * n);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d%f", items[i].name, &items[i].amount, &items[i].cost);
    }
    for (int i = 0; i < n; ++i) {
        printf("Item: %s\nQuantity: %d\nPrice: %f\n", items[i].name, items[i].amount, items[i].cost);
    }
    free(items);
}