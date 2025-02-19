#include <stdio.h>
#include <stdlib.h>
#include "ship.h"

int main() {
	float speed, time;
	puts("Enter speed, time:");
	scanf("%f%f", &speed, &time);
	puts("Enter fuel_level: ");
	int fuel_level;
	scanf("%d", &fuel_level);
	printf("Calculated distance: %f\n", calculate_distance(speed, time));
	printf("Fuel level: %s", check_fuel(fuel_level)); 
}
