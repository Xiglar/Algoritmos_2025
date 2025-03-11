
#include <stdio.h>
#include <limits.h>

int get_max_sub_array_sum(int* nums, int numsSize) {
    return 0;
}

// TESTS
void run_tests() {
    int test1[] = {-6, -1, 1, 2, 3, 1, -5, 4};
    int size1 = sizeof(test1) / sizeof(test1[0]);
    printf("Prueba 1: Suma máxima = %d (Esperado: 6)\n", get_max_sub_array_sum(test1, size1));
    
    int test2[] = {-6, -6, -6, -6};
    int size2 = sizeof(test2) / sizeof(test2[0]);
    printf("Prueba 2: Suma máxima = %d (Esperado: 15)\n", get_max_sub_array_sum(test2, size2));
    
    int test3[] = {-1, -2, -3, -4};
    int size3 = sizeof(test3) / sizeof(test3[0]);
    printf("Prueba 3: Suma máxima = %d (Esperado: -1)\n", get_max_sub_array_sum(test3, size3));
    
    int test4[] = {5, -1, 2, -1, 3, -2, 4};
    int size4 = sizeof(test4) / sizeof(test4[0]);
    printf("Prueba 4: Suma máxima = %d (Esperado: 10)\n", get_max_sub_array_sum(test4, size4));
}

int main() {
    run_tests();
    return 0;
}
