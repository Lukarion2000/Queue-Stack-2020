CC=gcc
LD=gcc
CFLAGS=-c -Wall -O3 -Iinclude

LDFLAGS=-lglfw -ldl

TARGET=QueuesAndStacks
OBJECTS=$(patsubst %.c, %.o, $(wildcard src/*.c))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LD) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(TARGET) $(OBJECTS)
