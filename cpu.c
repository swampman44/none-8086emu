#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "cpu.h"
#include "memory.h"
#include "debug.h"

#define IP_OFFSET 0x100
/* Positions of various flags in the flags register */
#define FLAG_POS_CARRY 0
#define FLAG_POS_PARITY 2 
#define FLAG_POS_AUXILIARY 4
#define FLAG_POS_ZERO 6
#define FLAG_POS_SIGN 7
#define FLAG_POS_TRAP 8
#define FLAG_POS_INTERRUPT 9
#define FLAG_POS_DIRECTION 10
#define FLAG_POS_OVERFLOW  11

#define SET_BIT(x, pos) (x ^= (1U << pos))
#define CLEAR_BIT(x, pos) (x &= (~(1U << pos)))
#define GET_BIT(x, pos) ((x & ( 1 << pos)) >> pos)


void populateRegistersOnInit(registers_t* registers)
{
  /* https://en.wikipedia.org/wiki/Reset_vector#x86_family_(Intel) */
  registers->ip = IP_OFFSET;
  registers->sp = 0;
 
  registers->ax = 0;
  registers->bx = 0;
  registers->cx = 0;
  registers->bp = 0;
  registers->si = 0;
  registers->di = 0;
  registers->dx = 0;
  registers->flags = 0;
}

static inline void checkZSP(registers_t* registers, uint8_t result)
{ 
  /* Zero */
  if(result == 0) SET_BIT(registers->flags, FLAG_POS_ZERO); 
  /* Sign */ 
  if(result == 0) {
    SET_BIT(registers->flags, FLAG_POS_ZERO);
  } else {
    CLEAR_BIT(registers->flags, FLAG_POS_ZERO);
  }
  if(result & 0x80) {
     SET_BIT(registers->flags, FLAG_POS_SIGN);
  } else {
     CLEAR_BIT(registers->flags, FLAG_POS_SIGN);
  }
  /* Parity */
  uint8_t countOnes = 0;
  for(uint8_t iter = 0; iter < 8; iter++) { countOnes += ((result >> iter) & 1); }
  if((countOnes % 2) != 0) SET_BIT(registers->flags, FLAG_POS_PARITY);
  else CLEAR_BIT(registers->flags, FLAG_POS_PARITY);
}
 
static inline uint8_t incrementRegister(registers_t* registers,
uint8_t value)
{
  uint8_t result = value + 1;
  if((result & 0xF) != 0) SET_BIT(registers->flags, FLAG_POS_AUXILIARY);
  else CLEAR_BIT(registers->flags, FLAG_POS_AUXILIARY);
  checkZSP(registers, result); 
  return result; 
}

void insertBinaryIntoMemory(const char* filename, memory_t* memory)
{
  FILE* file = fopen(filename, "rb");
  if(file != NULL) {
   fread(memory->ram + IP_OFFSET, 1, sizeof(memory->ram), file);
    fclose(file);
  } else {
    fprintf(stderr, "Error creating file pointer.");
    perror("Cannot open file.");
  }
}
void processOpcodesAndRunCycles(memory_t* memory, registers_t* registers)
{
  registers->ip = IP_OFFSET;
  for(uint32_t iter = registers->ip; iter <= memory->ramSize - 1; iter++) {
    uint32_t currentOpcode = memory->ram[registers->ip];
    registers->ip += 1;
    switch(currentOpcode) {
     case 0x40: 
       registers->ax = incrementRegister(registers, registers->ax); 
       break;
     case 0x41: 
       registers->cx = incrementRegister(registers, registers->cx); 
       break;
     case 0x42: 
       registers->dx = incrementRegister(registers, registers->dx);
       break;
     case 0x43: 
       registers->bx = incrementRegister(registers, registers->bx); 
       break;
     case 0x44: 
       registers->sp = incrementRegister(registers, registers->sp); 
       break;
     case 0x45: 
       registers->bp = incrementRegister(registers, registers->bp); 
       break;
     case 0x46: 
       registers->si = incrementRegister(registers, registers->si); 
       break;
     case 0x47: 
       registers->di = incrementRegister(registers, registers->di); 
      break; 
     default: break;
    }
  }
}
