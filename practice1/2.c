#include <stdio.h>
#include <stdlib.h>

int main() {
	int dist;
	scanf("%d", &dist);
	if (dist > 500) {
		puts("You can't");
		return 0;
	}
	puts("You can");
}
