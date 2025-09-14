#include <stdio.h>
#include <stdlib.h>

#include "cpu.h"
#include "memory.h"

registers_t registers;
memory_t memory;

int main(int argc, char* argv[])
{
  allocateMemoryOnInit(&memory);
  populateRegistersOnInit(&registers);
  if(argc <= 1) {
    perror("No arguments supplied.");
    return EXIT_FAILURE;
  }
  insertBinaryIntoMemory(argv[1], &memory);
  processOpcodesAndRunCycles(&memory, &registers);
  freeMemoryOnShutdown(&memory);
  return EXIT_SUCCESS;
}
