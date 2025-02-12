#include <stdio.h>
#include <stdlib.h>

int main() {
	char c;
	scanf("%c", &c);
	if (c < 'A' || c > 'Z') {
		puts("You loose");
		return 0;
	}
	puts("You pass");
}
