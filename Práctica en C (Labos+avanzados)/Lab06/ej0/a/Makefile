CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g
SOURCES = queue.c queue_helpers.c main.c
OBJTS = $(SOURCES: .c = .o)
TARGET = readqueue

.PHONY = clean

all: $(TARGET)

$(TARGET): $(OBJTS)	
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJTS)

.c.o: 
	$(CC) $(CFLAGS) -c $< .o $@

clean:
	$(RM) $(OBJTS) $(TARGET)