
#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

#define MEMORY_SIZE 1024 * 1024

typedef struct Memory{
  uint8_t* ram;
  size_t ramSize;
} memory_t;

void allocateMemoryOnInit(memory_t* memory);
void freeMemoryOnShutdown(memory_t* memory);
uint16_t readMemoryAddress(memory_t* memory, uint8_t memoryAddress);
void writeMemoryAddress(memory_t* memory, uint8_t memoryAddress, uint16_t value);

#endif // MEMORY_H
