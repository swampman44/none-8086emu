#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "memory.h"

void allocateMemoryOnInit(memory_t memory)
{
    memory.ramSize = MEMORY_SIZE;
    memory.ram = calloc(memory.ramSize, memory.ramSize);
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
