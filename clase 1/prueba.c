#include<stdio.h>
#include<stdlib.h>

void printVector(int v[], int N){
    int i;
    for(i=0;i<N;i++) printf("%d ", v[i]);
    printf("\n");
}

int main(){
    int N = 10; // Cantidad de elementos de nuestro vector
    
    // Asignamos un espacio en el heap para un vector de N elementos empleando malloc
    int *ptr = (int *) malloc((N)*sizeof(int)); /* (int *) es el type-casting aunque no es obligatorio en c.
    Luego N es la cantidad de datos y la estamos multiplicando por el tamaño de un entero*/

    *ptr = 'H';
    ptr[1] = 'O';

    printf("El vector con malloc es: ");
    printVector(ptr, N);

    free(ptr); // Cuando termina el programa liberamos la memoria

    return 0;
}