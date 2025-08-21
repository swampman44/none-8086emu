#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>
#include <string.h>

#include "memory.h"

void populateMemoryOnInit(memory_t memory);
{
  memset(memory.ram, 0, sizeof(memory.ram));
}
#endif // MEMORY_H
