#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

#define MEMORY_SIZE 1024 * 1024

typedef struct Memory{
  int ram;
} memory_t;

void allocateMemoryOnInit(memory_t memory);
void populateMemoryOnInit(memory_t memory);
void freeMemoryOnShutdown(memory_t memory);
uint32_t readMemoryAddress(memory_t memory, uint32_t memoryAddress);
void writeMemoryAddress(memory_t memory, uint32_t memoryAddress, uint8_t value);

#endif // MEMORY_H
