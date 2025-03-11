#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

char* invert_expression(const char* expression) {
    return expression;
}

// TEST
void run_tests() {
    char* expression1 = "3 + (2 * 5)";
    char* result1 = invert_expression(expression1);
    printf("Input: %s\n", expression1);
    printf("Output: %s\n", result1);
    printf("Expected Output: (5 * 2) + 3\n");
    printf("\n");
    free(result1);

    char* expression2 = "1 + (2 - (3 * 4))";
    char* result2 = invert_expression(expression2);
    printf("Input: %s\n", expression2);
    printf("Output: %s\n", result2);
    printf("Expected Output: ((4 * 3) - 2) + 1\n");
    printf("\n");
    free(result2);

    char* expression3 = "(3 + 2) * (5 - 4)";
    char* result3 = invert_expression(expression3);
    printf("Input: %s\n", expression3);
    printf("Output: %s\n", result3);
    printf("Expected Output: (4 - 5) * (2 + 3)\n");
    printf("\n");
    free(result3);
}

int main() {
    run_tests();
    return 0;
}
