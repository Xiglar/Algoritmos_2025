#include <stdio.h>
#include <stdbool.h>

int find_min_distance(int* nums, int nums_size) {
    return -1;
}

// TESTS
typedef struct {
  int *array;
  int size;
  int expected;
} TestCase;
void run_tests() {
  int test_1[] = {1, 2, 3, 5, 6};
  int test_2[] = {1, 1, 1, 1, 1};
  int test_3[] = {3, 2, 1, 2, 3};
  int test_4[] = {};
  int test_5[] = {1, 2, 3, 1, 2, 3};

  TestCase tests[] = {
      {test_1, sizeof(test_1) / sizeof(test_1[0]), -1},
      {test_2, sizeof(test_2) / sizeof(test_2[0]), 1},
      {test_3, sizeof(test_3) / sizeof(test_3[0]), 2},
      {test_4, sizeof(test_4) / sizeof(test_4[0]), -1},
      {test_5, sizeof(test_5) / sizeof(test_5[0]), 3}
  };

  int num_tests = sizeof(tests) / sizeof(tests[0]);

  for (int i = 0; i < num_tests; i++) {
      printf("Prueba %d: Distancia mínima obtenida = %d (Esperado: %d) \n", 
             i + 1, find_min_distance(tests[i].array, tests[i].size), tests[i].expected);
  }
}

int main() {
    run_tests();
    return 0;
}
