#include<stdio.h>

int main() {
    int a; printf("La cantidad de bytes de un int es: %d\n", sizeof(int));
    a = 5;
    printf("El valor de 'a' es: %d\n", a);
    printf("La dirección de 'a' es: %p\n", &a);

    int *p; // Defino un puntero p que va a apuntar a variables de tipo int
    p = &a; // p apunta a 'a'
    printf("El valor de p es: %p\n", p);

    *p = 10; // Modifico el valor de la variable a la que apunta p
    printf("El valor de 'a' es: %d\n", a);

    int array[6] = {12, 06, 57, 90, 23, 74}; // Arreglo/Vector
    int tam = sizeof(array)/sizeof(array[0]); // Obtiene la cantidad de elementos del vector
    printf("El vector tiene: %d elementos\n", tam);

    for(int i = 0; i < tam; i++) {
        printf("array[%d] está en %p y tiene el valor: %d\n", i, array + i, *(array + i)); // a+i <--> &a[i]
    }

    return 0;
}