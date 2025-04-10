#include "tp2.h"
#include <stdlib.h>
#include <stdbool.h>

struct node;
typedef struct node node_t;

struct node {
    void* value;
    node_t* next;
    node_t* prev;
};

struct list {
    node_t* head;
    node_t* tail;
    size_t size;
};

struct list_iter {
    list_t* list;
    node_t* curr;
};

list_t *list_new(){
    list_t* new_list = (list_t*)malloc(sizeof(list_t));
    if(new_list == NULL) return NULL;

    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->size = 0;
    return new_list;
}

size_t list_length(const list_t *list){
    return list->size;
}

bool list_is_empty(const list_t *list){
    if(list->size == 0) return true;
    return false;
}

bool list_insert_head(list_t *list, void *value){
    node_t* new_head = (node_t*)malloc(sizeof(node_t));
    if(new_head == NULL) return false;

    new_head->value = value;
    new_head->prev = NULL;
    new_head->next = list->head;

    if(list->head != NULL){
        list->head->prev = new_head;
    } else {
        list->tail = new_head;
    }

    list->head = new_head;
    list->size++;
    return true;
}

bool list_insert_tail(list_t *list, void *value){
    node_t* new_tail = (node_t*)malloc(sizeof(node_t));
    if(new_tail == NULL) return false;

    new_tail->value = value;
    new_tail->prev = list->tail;
    new_tail->next = NULL;

    if(list->tail != NULL){
        list->tail->next = new_tail;
    } else {
        list->head = new_tail;
    }

    list->tail = new_tail;
    list->size++;
    return true;
}

void *list_peek_head(const list_t *list){
    if(list_is_empty(list)) return NULL;
    if(list->head != NULL){
        return list->head->value;
    }
    return NULL;
}

void *list_peek_tail(const list_t *list){
    if(list_is_empty(list)) return NULL;
    if(list->tail != NULL){
        return list->tail->value;
    }
    return NULL;
}

void *list_pop_head(list_t *list){
    if(list->head == NULL) return NULL;
    void* head_value = list->head->value;
    node_t* old_head = list->head;

    list->head = old_head->next;

    if(list->head != NULL){
        list->head->prev = NULL;
    } else {
        list->tail = NULL;
    }
    
    free(old_head);
    list->size--;
    return head_value;
}

void *list_pop_tail(list_t *list){
    if(list->tail == NULL) return NULL;
    void* tail_value = list->tail->value;
    node_t* old_tail = list->tail;

    list->tail = old_tail->prev;

    if(list->tail != NULL){
        list->tail->next = NULL;
    } else {
        list->head = NULL;
    }
    
    free(old_tail);
    list->size--;
    return tail_value;
}

void list_destroy(list_t *list, void destroy_value(void *)){
    node_t* curr = list->head;
    while (curr != NULL) {
        node_t* next = curr->next;

        if (destroy_value != NULL) {
            destroy_value(curr->value);
        }

        free(curr);
        list->size--;
        curr = next;
    }

    free(list);
}

list_iter_t *list_iter_create_head(list_t *list){
    list_iter_t* iter = (list_iter_t*)malloc(sizeof(list_iter_t));
    if(iter == NULL) return NULL;

    iter->list = list;
    iter->curr = list->head;

    return iter;
}

list_iter_t *list_iter_create_tail(list_t *list){
    list_iter_t* iter = (list_iter_t*)malloc(sizeof(list_iter_t));
    if(iter == NULL) return NULL;

    iter->list = list;
    iter->curr = list->tail;

    return iter;
}

bool list_iter_forward(list_iter_t *iter){
    if(list_is_empty(iter->list)) return false;
    if(iter->curr->next == NULL) return false;
    iter->curr = iter->curr->next;
    return true;
}

bool list_iter_backward(list_iter_t *iter){
    if(list_is_empty(iter->list)) return false;
    if(iter->curr->prev == NULL) return false;
    iter->curr = iter->curr->prev;
    return true;
}

void *list_iter_peek_current(const list_iter_t *iter){
    if(list_is_empty(iter->list)) return NULL;
    return iter->curr->value;
}

bool list_iter_at_last(const list_iter_t *iter){
    if(list_is_empty(iter->list) || iter->curr == iter->list->tail) return true;
    return false;
}

bool list_iter_at_first(const list_iter_t *iter){
    if(list_is_empty(iter->list) || iter->curr == iter->list->head) return true;
    return false;
}

void list_iter_destroy(list_iter_t *iter){
    free(iter);
}

bool list_iter_insert_after(list_iter_t *iter, void *value){
    if(iter == NULL || iter->list == NULL) return false;

    if(iter->curr == NULL){
        bool insert_in_empty_list = list_insert_tail(iter->list, value);
        if(insert_in_empty_list)
            iter->curr = iter->list->tail;
        return insert_in_empty_list;
    }

    node_t *actual = iter->curr;
    node_t *new_node = malloc(sizeof(node_t));
    if(new_node == NULL) return false;

    new_node->value = value;
    new_node->prev = actual;
    new_node->next = actual->next;

    if(actual->next != NULL){
        actual->next->prev = new_node;
    } else {
        iter->list->tail = new_node; 
    }
    actual->next = new_node;
    iter->list->size++;

    if(actual == iter->list->tail) iter->curr = new_node;

    return true;
}

bool list_iter_insert_before(list_iter_t *iter, void *value){
    if(iter == NULL || iter->list == NULL) return false;

    if(iter->curr == NULL){
        bool insert_in_empty_list = list_insert_head(iter->list, value);
        if(insert_in_empty_list)
            iter->curr = iter->list->head;
        return insert_in_empty_list;
    }

    node_t *actual = iter->curr;
    node_t *new_node = malloc(sizeof(node_t));
    if(new_node == NULL) return false;

    new_node->value = value;
    new_node->prev = actual->prev;
    new_node->next = actual;

    if(actual->prev != NULL){
        actual->prev->next = new_node;
    } else {
        iter->list->head = new_node; 
    }
    actual->prev = new_node;
    iter->list->size++;

    if(actual == iter->list->head) iter->curr = new_node;

    return true;
}

void *list_iter_delete(list_iter_t *iter){
    if(iter == NULL || iter->list == NULL || iter->curr == NULL) return NULL;
    node_t *to_delete = iter->curr;
    void *value = to_delete->value;

    node_t *next = to_delete->next;
    node_t *prev = to_delete->prev;

    if(prev){
        prev->next = next;
    } else {
        iter->list->head = next;
    }

    if(next){
        next->prev = prev;
    } else {
        iter->list->tail = prev;
    }

    if(next){
        iter->curr = next;
    } else {
        iter->curr = prev;
    }

    free(to_delete);
    iter->list->size--;

    return value;
}