#include <stdio.h>
#include <stdlib.h>

#include "cpu.h"
#include "memory.h"

int main(int argc, char* argv)
{
  registers_t registers;
  memory_t memory;
  populateRegistersOnInit(registers);
  return EXIT_SUCCESS;
}
