#include <stdio.h>
#include <stdlib.h>

int main() {
	int weight;
	scanf("%d", &weight);
	if (weight < 60 || weight > 90) {
		puts("You loose");
		return 0;
	}
	puts("You pass");
}
