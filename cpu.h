#ifndef CPU_H
#define CPU_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "memory.h"

typedef struct Registers {
  uint16_t ip, sp;
  uint8_t ax, bx, cx, dx, bp, si, di; 
  uint32_t flags;
} registers_t;

typedef struct CPU {
  uint32_t totalCycles;
} cpu_t;


void populateRegistersOnInit(registers_t* registers);

// Functions to set various Flags in register.flags.
static inline void checkZSP(registers_t* registers, uint8_t result);
static inline uint8_t incrementRegister(registers_t* registers, uint8_t value); 
static inline uint8_t decrementRegister(registers_t*, uint8_t value);
void insertBinaryIntoMemory(const char* filename, memory_t *memory);
void processOpcodesAndRunCycles(memory_t* memory, registers_t* registers);

#endif // CPU_H
