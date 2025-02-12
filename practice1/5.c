#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	double calc, real;
	scanf("%lf%lf", &calc, &real);
	if ((float)(fabs(real - calc)) > 0.1) {
		puts("Wrong calculation");
		return 0;
	}
	puts("Normal calculation");
}
