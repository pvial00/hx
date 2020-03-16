CC=gcc
CFLAGS=-O3 -std=c99 -w -msse4.2
TARGET=hxsum
all: $(TARGET)

$(TARGET): hx_sum.c
	$(CC) hx_sum.c $(CFLAGS) -o $(TARGET)

clean:
	$(RM) $(TARGET)
