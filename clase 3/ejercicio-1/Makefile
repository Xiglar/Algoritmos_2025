CC = gcc
CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror
LDFLAGS = -lm
TARGET = process_events_in_real_time

# Comando por defecto para compilar y ejecutar localmente
local: $(TARGET)
	valgrind -s --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)
	rm -f $(TARGET)

# Regla para enlazar el archivo ejecutable
$(TARGET): eventlist.o process_events_in_real_time.o
	$(CC) $(CFLAGS) -o $(TARGET) eventlist.o process_events_in_real_time.o $(LDFLAGS)

# Regla para compilar los archivos fuente a objetos
eventlist.o: eventlist.c eventlist.h
	$(CC) $(CFLAGS) -c eventlist.c

process_events_in_real_time.o: process_events_in_real_time.c eventlist.h
	$(CC) $(CFLAGS) -c process_events_in_real_time.c

# Regla para construir y ejecutar en Docker
docker:
	docker build --tag example .
	docker run -v "$(CURDIR)":/ejercicio-1 example
	docker rmi example
