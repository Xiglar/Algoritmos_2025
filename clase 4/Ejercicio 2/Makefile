CC = gcc
CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror
TARGET = find_median
SRCS = find_median_tests.c heap.c
OBJS = $(SRCS:.c=.o)
DEPS = heap.h

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $<

run: $(TARGET)
	valgrind -s --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

docker:
	docker build --tag $(TARGET) .
	docker run -v "$(CURDIR)":/app $(TARGET)
	docker rmi $(TARGET)

.PHONY: all run clean docker
