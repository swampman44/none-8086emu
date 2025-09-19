#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "cpu.h"
#include "memory.h"
#include "debug.h"

#define IP_OFFSET 0x100

#define SET_BIT(x, pos) x ^= (1U << pos)
#define CLEAR_BIT(x, pos) (x &= (~(1U << pos)))
#define GET_BIT(x, pos) ((x & ( 1 << pos)) >> pos)

#define CLC(regname) CLEAR_BIT(regname, 0) 
#define CLD(regname) CLEAR_BIT(regname, 10)
#define CLI(regname) CLEAR_BIT(regname, 9)

#define DEC(regname) regname--
#define INC(regname) regname++

void populateRegistersOnInit(registers_t *registers)
{
  /* https://en.wikipedia.org/wiki/Reset_vector#x86_family_(Intel) */
  registers->ip = IP_OFFSET;

  registers->ax = 0x00000;
  registers->bx = 0x00000;
  registers->cx = 0x00000;
  registers->dx = 0x00000;
  registers->cs = 0x00000;
  registers->ss = 0x00000;
  registers->sp = 0x00000;
  registers->bp = 0x00000;
  registers->si = 0x00000;
  registers->di = 0x00000;
  registers->ds = 0x00000;
  registers->es = 0x00000;

  registers->flags = 0x00000;
}

void insertBinaryIntoMemory(const char* filename, memory_t *memory)
{
  FILE* file = fopen(filename, "rb");
  if(file != NULL) {
    //fseek(file, IP_OFFSET, SEEK_SET);
    //fread(memory->ram, 1, sizeof(memory->ram), file);
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
    case 0x90: continue;
    case 0xF4: break;
    case 0xF8: CLC(registers->flags); break;
    case 0xFC: CLD(registers->flags); break;
    case 0xFA: CLI(registers->flags); break;
    case 0x40: INC(registers->ax); break;
    case 0x41: INC(registers->cx); break;
    case 0x42: INC(registers->dx); break;
    case 0x43: INC(registers->bx); break;
    case 0x44: INC(registers->sp); break;
    case 0x45: INC(registers->bp); break;
    case 0x46: INC(registers->si); break;
    case 0x47: INC(registers->di); break;
    default: break;
    }
  }
}
