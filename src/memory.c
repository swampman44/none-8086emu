#include <stdint.h>
#include <string.h>

#include "memory.h"

void allocateMemoryOnInit(memory_t memory)
{
  memory.ram = calloc(MEMORY_SIZE);
}

void populateMemoryOnInit(memory_t memory)
{
  memset(memory.ram, 0, sizeof(memory.ram));
}

void freeMemoryOnShutdown(memory_t memory)
{
  free(memory.ram);
}

uint32_t readMemoryAddress(memory_t memory, uint32_t memoryAddress)
{
  memory.ram[memoryAddress];  
}


void writeMemoryAddress(memory_t memory, uint32_t memoryAddress, uint8_t value)
{
  memory.ram[memoryAddress] = value;
}
