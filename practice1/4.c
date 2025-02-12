#include <stdio.h>
#include <stdlib.h>

int main() {
	int date;
	scanf("%d", &date);
	if (date > 20250210) {
		puts("You are in future");
		return 0;
	}
	if (date == 20250210) {
		puts("You are in today");
	}
	else {
		puts("You are in past");
	}
}
