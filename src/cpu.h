#ifndef CPU_H
#define CPU_H

#include <stdint.h>

typedef struct Registers{
  uint32_t ip;
  uint32_t sp;

  uint32_t ax;
  uint32_t bx;
  uint32_t dx;
  uint32_t cs;
  uint32_t ss;
  uint32_t sp;
  uint32_t bp;
  uint32_t si;
  uint32_t di;
  uint32_t ds;
  uint32_t es;  
} registers_t;

void populateRegistersOnInit(registers_t registers);

#endif // CPU_H
