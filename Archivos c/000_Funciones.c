#include<stdio.h>

int printVector(int array[]) {
    int *vector = &array;
    printf("%p ", vector);
    int len_vector = sizeof(&array)/sizeof(vector);
    printf("%d ", len_vector);

    typeof(array[0]) type;
    typeof(int) integer;
    typeof(char) character;
    for (int elem = 0; elem < len_vector; elem++) {
        if (type == integer) {
            printf("%d ", array[elem]);
        }
        else if ((type == character)) {
            printf("%c ", array[elem]);
        }
    }
}

int main() {
    int array[5] = {1, 2, 3, 4, 5};

    printVector(array);
    return 0;
}