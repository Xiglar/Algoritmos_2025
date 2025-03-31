#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "eventlist.h"

// Función principal para pruebas
int main() {
    EventList* list = create_event_list();
    time_t current_time = time(NULL);

    // Agregar eventos de prueba
    add_event(list, current_time, 5);
    add_event(list, current_time + 1, 3);
    add_event(list, current_time + 2, 7);
    add_event(list, current_time + 3, 2);
    add_event(list, current_time + 4, 10);

    // Simular paso del tiempo y eliminar eventos expirados
    printf("Tiempo actual: %ld\n", current_time);
    print_current_events(list, current_time);

    current_time += 3;
    printf("\nTiempo actual: %ld\n", current_time);
    remove_expired_events(list, current_time);
    print_current_events(list, current_time);

    current_time += 3;
    printf("\nTiempo actual: %ld\n", current_time);
    remove_expired_events(list, current_time);
    print_current_events(list, current_time);

    // Liberar memoria
    destroy_list(list);
    return 0;
}
