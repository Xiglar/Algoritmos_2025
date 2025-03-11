#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Función para crear un nuevo nodo
StackNode* create_node(void* data) {
    StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
    if (new_node == NULL) {
        fprintf(stderr, "Error: no se pudo asignar memoria para el nodo\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// Función para crear una pila
Stack* create_stack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        fprintf(stderr, "Error: no se pudo asignar memoria para la pila\n");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    return stack;
}

// Función para verificar si la pila está vacía
int is_stack_empty(Stack* stack) {
    return stack->top == NULL;
}

// Función para empujar un elemento a la pila
void push(Stack* stack, void* data) {
    StackNode* new_node = create_node(data);
    if (is_stack_empty(stack)) {
        stack->top = new_node;
    } else {
        new_node->next = stack->top;
        stack->top->prev = new_node;
        stack->top = new_node;
    }
}

// Función para sacar un elemento de la pila
void* pop(Stack* stack) {
    if (is_stack_empty(stack)) {
        return NULL; // Indicador de que la pila está vacía
    }

    StackNode* temp = stack->top;
    void* data = temp->data;

    stack->top = stack->top->next;
    if (stack->top != NULL) {
        stack->top->prev = NULL;
    }

    free(temp);
    return data;
}

// Función para ver el elemento en la cima de la pila sin eliminarlo
void* peek(Stack* stack) {
    if (is_stack_empty(stack)) {
        return NULL; // Indicador de que la pila está vacía
    }
    return stack->top->data;
}

// Función para liberar toda la memoria de la pila
void free_stack(Stack* stack) {
    while (!is_stack_empty(stack)) {
        pop(stack);
    }
    free(stack);
}