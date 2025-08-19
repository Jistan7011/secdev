CC=gcc
CFLAGS=-O2 -Wall
TARGET=sum-nbo

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) -o $@ main.c

clean:
	rm -f $(TARGET)

