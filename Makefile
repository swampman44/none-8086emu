.POSIX:
.OBJDIR: build

CC = cc
CFLAGS = -Wall -Wextra -pedantic -std=c99 -O3

all: none-8086emu

none-8086emu: build/none-8086emu.o build/cpu.o build/memory.o build/debug.o
	$(CC) $(CFLAGS) build/none-8086emu.o build/cpu.o build/memory.o \
			build/debug.o -o none-8086emu

build/none-8086emu.o: none-8086emu.c
	$(CC) $(CFLAGS) -c none-8086emu.c -o build/none-8086emu.o

build/memory.o: memory.h memory.c
	$(CC) $(CFLAGS) -c memory.c -o build/memory.o

build/cpu.o: cpu.h cpu.c
	$(CC) $(CFLAGS) -c cpu.c -o build/cpu.o

build/debug.o: debug.h debug.c
	$(CC) $(CFLAGS) -c debug.c -o build/debug.o

clean:
	rm -f build/* none-8086emu 

.PHONY: all clean
