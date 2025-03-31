#include "eventlist.h"

Event* create_event(time_t timestamp, int duration) {
    Event* new_event = (Event*)malloc(sizeof(Event));
    if (new_event == NULL) {
        fprintf(stderr, "Error: no se pudo asignar memoria para el evento\n");
        exit(EXIT_FAILURE);
    }
    new_event->timestamp = timestamp;
    new_event->duration = duration;
    new_event->prev = NULL;
    new_event->next = NULL;
    return new_event;
}

EventList* create_event_list() {
    EventList* list = (EventList*)malloc(sizeof(EventList));
    if (list == NULL) {
        fprintf(stderr, "Error: no se pudo asignar memoria para la lista de eventos\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void add_event(EventList* list, time_t timestamp, int duration) {
   // TODO
}

void remove_expired_events(EventList* list, time_t current_time) {
   // TODO
}

void print_current_events(EventList* list, time_t current_time) {
    Event* current = list->head;
    printf("Eventos actuales (después de eliminar expirados):\n");
    while (current != NULL) {
        printf("Evento en %ld con duración %d\n", current->timestamp, current->duration);
        current = current->next;
    }
}

void destroy_list(EventList* list) {
    // TODO
}
