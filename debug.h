#ifndef DEBUG_H
#define DEBUG_H

#include "cpu.h"

void dumpCurrentRegisters(registers_t* registers);
void dumpCurrentMemory(memory_t* memory);

#endif // DEBUG_H
