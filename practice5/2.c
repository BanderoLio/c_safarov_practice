#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


int main() {
	fork();
	fork();
	puts("Bebra");
	sleep(15);
}
