#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef float (*op_func_t) (float, float);


float plus(float a, float b) {
    return a + b;
} 

float minus(float a, float b) {
    return a - b;
}

float mult(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    return a / b;
}

int main() {
    char input[1024];
    fgets(input, 1024, stdin);
    op_func_t ops[] = {
        plus, minus, mult, divide
    };
    const char* operations = "+-*/";
    for (const char* op = operations; *op != '\0'; ++op) {
        const char* op_iter;
        if ((op_iter = strchr(input, *op))) {
            float a;
            if (!sscanf(input, "%f", &a)) {
                return puts("Wrong input: first number not correct");
            }
            float b;
            if (!sscanf(op_iter + 1, "%f", &b)) {
                return puts("Wrong input: second number not correct");
            }
            if (*op == '/' && fabs(b - 0.0f) < 0.0001f) {
                puts("Wrong input: Zero division");
                return -1;
            }
            printf("Result: %f\n", ops[op - operations](a, b));
            return 0;
        }
    }
    puts("Wrong input: no operation");
}