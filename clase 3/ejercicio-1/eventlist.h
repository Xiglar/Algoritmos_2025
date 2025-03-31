#ifndef EVENT_LIST_H
#define EVENT_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estructura para un evento
typedef struct Event {
    time_t timestamp;
    int duration;
    struct Event* prev;
    struct Event* next;
} Event;

// Estructura para la lista de eventos
typedef struct EventList {
    Event* head;
    Event* tail;
} EventList;

// Función para crear un nuevo evento
Event* create_event(time_t timestamp, int duration);

// Función para crear una lista de eventos
EventList* create_event_list();

// Función para agregar un nuevo evento a la lista
void add_event(EventList* list, time_t timestamp, int duration);

// Función para eliminar eventos expirados
void remove_expired_events(EventList* list, time_t current_time);

// Función para mostrar los eventos actuales
void print_current_events(EventList* list, time_t current_time);

// Función para destruir la lista de eventos y liberar la memoria
void destroy_list(EventList* list);

#endif // EVENT_LIST_H
