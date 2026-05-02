#include "Kalkulator.h"
#include "boolean.h"
#include <stdio.h>

int main() {
    Kalkulator K;
    BuatKalkulator(&K);
    printf("Test 1: Empty calculator\n");
    CetakHasil(K);

    printf("\nTest 2: Valid expression 4+2*5-7\n");
    int oprn1[] = {4, 2, 5, 7};
    char oprtor1[] = {'+', '*', '-'};
    InputOperasi(&K, oprn1, 4, oprtor1, 3);
    CetakHasil(K);

    printf("\nTest 3: Invalid expression 4+2*5-\n");
    int oprn2[] = {4, 2, 5};
    char oprtor2[] = {'+', '*', '-'};
    InputOperasi(&K, oprn2, 3, oprtor2, 3);
    CetakHasil(K);

    printf("\nTest 4: Division by zero 4/0\n");
    int oprn3[] = {4, 0};
    char oprtor3[] = {'/'};
    InputOperasi(&K, oprn3, 2, oprtor3, 1);
    CetakHasil(K);

    printf("\nTest 5: Simple addition 2+3\n");
    int oprn4[] = {2, 3};
    char oprtor4[] = {'+'};
    InputOperasi(&K, oprn4, 2, oprtor4, 1);
    CetakHasil(K);

    return 0;
}