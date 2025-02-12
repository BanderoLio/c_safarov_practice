#include <stdio.h>
#include <stdlib.h>
#include "math.h"


int main(int argc, char** argv) {
	if (argc < 3) {
		return -1;
	}
	printf("%lf", pow(atof(argv[1]), atof(argv[2])));
}
