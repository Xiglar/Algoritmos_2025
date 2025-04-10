#include <stdio.h>
#include <stdlib.h>


// Función para encontrar la mediana después de cada inserción
void find_median(int* arr, int n, double* medians) {
    // Completar implementación

        
}

// TESTS
void run_tests() {
    int arr1[] = {5, 2, 1, 7, 5, 3};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    double medians1[6];
    find_median(arr1, n1, medians1);
    printf("Test 1\n");
    for (int i = 0; i < n1; i++) {
        printf("Input: %d, Median: %.1f\n", arr1[i], medians1[i]);
    }
    printf("Expected Output: 5.0, 3.5, 2.0, 3.5, 5.0, 4.0\n");
    printf("\n");

    int arr2[] = {10, 20, 30, 40, 50};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    double medians2[5];
    find_median(arr2, n2, medians2);
    printf("Test 2\n");
    for (int i = 0; i < n2; i++) {
        printf("Input: %d, Median: %.1f\n", arr2[i], medians2[i]);
    }
    printf("Expected Output: 10.0, 15.0, 20.0, 25.0, 30.0\n");
    printf("\n");

    int arr3[] = {1, 3, 3, 6, 7, 8, 9};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    double medians3[7];
    find_median(arr3, n3, medians3);
    printf("Test 3\n");
    for (int i = 0; i < n3; i++) {
        printf("Input: %d, Median: %.1f\n", arr3[i], medians3[i]);
    }
    printf("Expected Output: 1.0, 2.0, 3.0, 3.0, 3.0, 4.5, 6.0\n");
    printf("\n");

    int arr4[] = {10, 5, 2, 3, 5, 6, 7};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    double medians4[7];
    find_median(arr4, n4, medians4);
    printf("Test 4\n");
    for (int i = 0; i < n4; i++) {
        printf("Input: %d, Median: %.1f\n", arr4[i], medians4[i]);
    }
    printf("Expected Output: 10.0, 7.5, 5.0, 4.0, 5.0, 5.0, 5.0\n");
    printf("\n");
}

int main() {
    run_tests();
    return 0;
}
