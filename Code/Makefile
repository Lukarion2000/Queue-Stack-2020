CC=gcc
LD=gcc
CFLAGS=-c -Wall -O3 -Iinclude

# TODO: Insert your OS-specific libs for GLFW!
LDFLAGS=-lglfw -ldl

TARGET=hello-triangle
OBJECTS=$(patsubst %.c, %.o, $(wildcard src/*.c))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LD) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(TARGET) $(OBJECTS)
