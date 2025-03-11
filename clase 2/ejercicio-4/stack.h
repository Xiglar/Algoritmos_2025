#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>

// Estructura de nodo para la pila
typedef struct StackNode {
    void* data;
    struct StackNode* next;
    struct StackNode* prev;
} StackNode;

// Estructura para la pila
typedef struct {
    StackNode* top;
} Stack;

// Funciones para manejar la pila
Stack* create_stack();
void push(Stack* stack, void* data);
void* pop(Stack* stack);
void* peek(Stack* stack);
int is_stack_empty(Stack* stack);
void free_stack(Stack* stack);

#endif // STACK_H
