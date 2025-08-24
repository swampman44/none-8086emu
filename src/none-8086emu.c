#include <stdio.h>
#include <stdlib.h>

#include "cpu.h"
#include "memory.h"

registers_t registers;
memory_t memory;

void runOnInit()
{
  allocateMemoryOnInit(memory);
  populateRegistersOnInit(registers);
  freeMemoryOnShutdown(memory);
}

int main(int argc, char* argv[])
{
  runOnInit();
  return EXIT_SUCCESS;
}
