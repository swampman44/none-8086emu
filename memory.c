#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "memory.h"

void allocateMemoryOnInit(memory_t* memory)
{
  memory->ram = NULL;
  memory->ramSize = MEMORY_SIZE;
  memory->ram = calloc(memory->ramSize, sizeof(uint32_t));
  if(memory->ram == NULL) {
    perror("memory->ram is a NULL pointer. Exiting.");
    exit(EXIT_FAILURE);
  }
}

void freeMemoryOnShutdown(memory_t* memory)
{
  free(memory->ram);
}

uint16_t readMemoryAddress(memory_t* memory, uint8_t memoryAddress)
{
  return memory->ram[memoryAddress];
}

void writeMemoryAddress(memory_t* memory, uint8_t memoryAddress, uint16_t value)
{
  memory->ram[memoryAddress] = value;
}
