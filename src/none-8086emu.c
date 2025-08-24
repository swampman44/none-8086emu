#include <stdio.h>
#include <stdlib.h>

#include "cpu.h"
#include "memory.h"

registers_t registers;
memory_t memory;

void runOnInit()
{
  allocateMemoryOnInit(memory_t memory);
  populateRegistersOnInit(registers);
  populateMemoryOnInit(memory);
  freeMemoryOnShutdown(memory_t memory)
}

int main(int argc, char* argv[])
{
  runOnInit();
  return EXIT_SUCCESS;
}
