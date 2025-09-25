#include "cpu.h"

#define PR(NAME, REG) printf("\n %s: %d ", NAME, REG)

void dumpCurrentRegisters(registers_t* registers)
{
  PR("IP", registers->ip);
  PR("SP", registers->sp);
  PR("AX", registers->ax);
  PR("BX", registers->bx);
  PR("CX", registers->cx);
  PR("DX", registers->dx);
  PR("CS", registers->bp);
  PR("SS", registers->si);
  PR("BP", registers->di);

  PR("FLAGS", registers->flags);
} 

