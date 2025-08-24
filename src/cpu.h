#ifndef CPU_H
#define CPU_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "memory.h"

typedef struct Registers {
  uint32_t ip;
  uint32_t sp;

  uint32_t ax;
  uint32_t bx;
  uint32_t cx;
  uint32_t dx;
  uint32_t cs;
  uint32_t ss;
  uint32_t bp;
  uint32_t si;
  uint32_t di;
  uint32_t ds;
  uint32_t es;

  uint32_t flags;
} registers_t;

void populateRegistersOnInit(registers_t registers);

// Functions to set various Flags in register.flags.
void setFlagsRegisterCarry(registers_t registers, bool value);
void setFlagsRegisterParity(registers_t registers, bool value);
void setFlagsRegistersAuxiliary(registers_t registers, bool value);
void setFlagsRegistersZero(registers_t registers, bool value);
void setFlagsRegistersSign(registers_t registers, bool value);
void setFlagsRegistersTrap(registers_t registers, bool value);
void setFlagsRegistersInterrupt(registers_t registers, bool value);
void setFlagsRegistersDirection(registers_t registers, bool value);
void setFlagsRegistersOverflow(registers_t registers, bool value);

void insertBinaryIntoMemory(const char* filename, memory_t memory);
void processOpcodes(memory_t memory);

#endif // CPU_H
