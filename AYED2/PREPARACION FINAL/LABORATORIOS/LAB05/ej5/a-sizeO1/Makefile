CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 
SOURCES = queue.c queue_helpers.c main.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = readqueue

.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(TARGET)
