#include "tp1.h"
#include <stdio.h>
#include <stdlib.h>

bool are_friends_numbers(int x, int y){
    int sum_x = 0;
    int sum_y = 0;

    if(x != y){
        for(int num = 1; sum_x < y && num < x; num++){
            if(x % num == 0){
                sum_x += num;
            }
        }

        for(int num = 1; sum_y < x && num < y; num++){
            if(y % num == 0){
                sum_y += num;
            }
        }
        if(sum_x == y && sum_y == x){
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int calculate_time_in_seconds(float di, float df, float v) {
    float total_distance = df - di;
    if(total_distance < 0){
        total_distance = total_distance*(-1);
    }
    if(total_distance > 0 && v == 0){
        return -1;
    } else if (total_distance == 0 && v == 0){
        return 0;
    }
    float time = total_distance/v;
    return (int)time;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
    return;
}

int array_min_index(const int *array, int length) {
    if(length != 0 && array != NULL){
        int min = array[0];
        int min_inx = 0;
        for(int index = 1; index < length; index++){
            if(array[index] < min){
                min = array[index];
                min_inx = index;
            }
        }
        return min_inx;
    } else {
        return -1;
    }
}

int *copy_array(const int *array, int length) {
    if(array == NULL || length == 0){
        return NULL;
    }

    int *mem = (int *)malloc(length * sizeof(int));
    if(!mem) return NULL;

    int pos = 0;
    for(int elem = 0; elem < length; elem++){
        mem[pos++] = array[elem];
    }

    return mem;
}

void selection_sort(int *array, int length){
    if(array == NULL || length == 0){
        return;
    }

    for(int pos = 0; pos < length-1; pos++){
        int min_index = pos;
        for(int elem = pos+1; elem < length; elem++){
            if(array[elem] < array[min_index]){
                min_index = elem;
            }
        }
        int temp = array[min_index];
        array[min_index] = array[pos];
        array[pos] = temp;
    }
    return;
}

int* array_union(const int *array1, int length1, const int *array2, int length2) {
    int total_length = length1 + length2;

    if(total_length == 0 || (array1 == 0 && array2 == 0)) {
        return NULL;
    }

    int *temp = (int *)malloc(total_length * sizeof(int));
    if(!temp) return NULL;

    int pos = 0;
    for(int elem = 0; elem < length1; elem++){
        temp[pos++] = array1[elem];
    }
    for(int elem = 0; elem < length2; elem++){
        temp[pos++] = array2[elem];
    }

    selection_sort(temp, total_length);

    int *unique = (int *)malloc(total_length * sizeof(int));
    if(!unique) {
        free(temp);
        return NULL;
    }

    pos = 0;
    unique[pos++] = temp[0];
    for(int i = 1; i < total_length; i++) {
        if(temp[i] != temp[i - 1]) {
            unique[pos++] = temp[i];
        }
    }

    free(temp);

    int *final_array = (int *)realloc(unique, pos * sizeof(int));
    if(!final_array) {
        free(unique);
        return NULL;
    }

    return final_array;
}

void matrix_map(Matriz matrix, int row_size, int col_size, int f(int)) {
    if(f == NULL){
        return;
    } else {
        for(int x = 0; x < row_size; x++){
            for(int y = 0; y < col_size; y++){
                matrix[x][y] = f(matrix[x][y]);
            }
        }
        return;
    }
}

Matriz copy_matrix(const Matriz matrix, int row_size, int col_size) {
    if(matrix == NULL) {
        return NULL;
    }
    int **copy = (int **)malloc(row_size * sizeof(int*));
    if(!copy) return NULL;
    
    for(int i = 0; i < row_size; i++){
        copy[i] = (int *)malloc(col_size * sizeof(int));
        if(!copy[i]){
            free(copy);
            return NULL;
        }
    }

    for(int x = 0; x < row_size; x++){
        for(int y = 0; y < col_size; y++){
            copy[x][y] = matrix[x][y];
        }
    }

    return copy;
}

bool matrix_equal(const Matriz matrix1, int row_size1, int col_size1, const Matriz matrix2, int row_size2, int col_size2) {
    if(matrix1 == NULL && matrix2 == NULL){
        return true;
    }
    if(matrix1 == NULL || matrix2 == NULL) {
        return false;
    }
    if(row_size1 != row_size2 || col_size1 != col_size2){
        return false;
    }
    
    for(int x = 0; x < row_size1; x++){
        for(int y = 0; y < col_size1; y++){
            if(matrix1[x][y] != matrix2[x][y]){
                return false;
            }
        }
    }
    return true;
}

Matriz* copy_array_of_matrices(const Matriz *array_of_matrices, const Matriz matrix_dimensions, int array_lenght) {
    if(array_of_matrices == NULL) {
        return NULL;
    }

    Matriz* copied_array = (Matriz*)malloc(array_lenght * sizeof(Matriz));
    if(copied_array == NULL) {
        return NULL;
    }

    for(int i = 0; i < array_lenght; i++) {
        int rows = matrix_dimensions[i][0];
        int cols = matrix_dimensions[i][1];

        if(array_of_matrices[i] != NULL) {
            copied_array[i] = copy_matrix(array_of_matrices[i], rows, cols);
        } else {
            copied_array[i] = NULL;
        }
    }
    return copied_array;
}

void free_array_of_matrices(Matriz* array_of_matrices, Matriz matrix_dimensions, int array_lenght) {
    if(array_of_matrices == NULL || array_lenght == 0) return;

    for(int i = 0; i < array_lenght; i++){
        for(int j = 0; j < matrix_dimensions[i][0]; j++){
            free(array_of_matrices[i][j]);
        }

        free(array_of_matrices[i]);
        free(matrix_dimensions[i]);
    }
    free(array_of_matrices);
    free(matrix_dimensions);
}

