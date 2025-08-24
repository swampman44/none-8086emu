#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "cpu.h"
#include "memory.h"

#define SET_BIT(x, pos) x ^= (1U << pos)
#define CLEAR_BIT(x, pos) (x &= (~(1U<< pos)))
#define GET_BIT(x, pos) ((x & ( 1 << pos)) >> pos)

void populateRegistersOnInit(registers_t registers)
{
  /* https://en.wikipedia.org/wiki/Reset_vector#x86_family_(Intel) */
  registers.ip = 0xFFFF0;

  registers.ax = 0x00000;
  registers.bx = 0x00000;
  registers.cx = 0x00000;
  registers.dx = 0x00000;
  registers.cs = 0x00000; 
  registers.ss = 0x00000;
  registers.sp = 0x00000;
  registers.bp = 0x00000;
  registers.si = 0x00000;
  registers.di = 0x00000;
  registers.ds = 0x00000;
  registers.es = 0x00000;

  registers.flags = 0x00000;
}

// functions to set various flags in register.flags.
void setFlagsRegisterCarry(registers_t registers, bool value)
{
  if(value) { SET_BIT(registers.flags, 0); }
  if(!value) { CLEAR_BIT(registers.flags, 0); }
}
void setFlagsRegisterParity(registers_t registers, bool value)
{
  if(value) { SET_BIT(registers.flags, 2); }
  if(!value) { CLEAR_BIT(registers.flags, 2); }
}
void setFlagsRegistersAuxiliary(registers_t registers, bool value)
{
  if(value) { SET_BIT(registers.flags, 4); }
  if(!value) { CLEAR_BIT(registers.flags, 4); }
}
void setFlagsRegistersZero(registers_t registers, bool value)
{
  if(value) { SET_BIT(registers.flags, 6); }
  if(!value) { CLEAR_BIT(registers.flags, 6); }
}
void setFlagsRegistersSign(registers_t registers, bool value)
{
  if(value) { SET_BIT(registers.flags, 7); }
  if(!value) { CLEAR_BIT(registers.flags, 7); }
}
void setFlagsRegistersTrap(registers_t registers, bool value)
{
  if(value) { SET_BIT(registers.flags, 8); }
  if(!value) { CLEAR_BIT(registers.flags, 8); }
}
void setFlagsRegistersInterrupt(registers_t registers, bool value)
{
  if(value) { SET_BIT(registers.flags, 9); }
  if(!value) { CLEAR_BIT(registers.flags, 9); }
}
void setFlagsRegistersDirection(registers_t registers, bool value)
{
  if(value) { SET_BIT(registers.flags, 10); }
  if(!value) { CLEAR_BIT(registers.flags, 10); }
}
void setFlagsRegistersOverflow(registers_t registers, bool value)
{
  if(value) { SET_BIT(registers.flags, 11); }
  if(!value) { CLEAR_BIT(registers.flags, 11); }
}

void insertBinaryIntoMemory(const char* filename, memory_t memory)
{
  FILE* file = fopen(filename, "rb");
  if(file != NULL) {
    fseek(file, 0x100, SEEK_SET);
    size_t bytesRead = fread(memory.ram, 1, sizeof(memory.ram), file);
    fclose(file);
  } else {
    fprintf(stderr, "Error creating file pointer.");
    perror("Cannot open file.");
  }
}
