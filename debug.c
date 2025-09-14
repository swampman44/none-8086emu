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
  PR("CS", registers->cs);
  PR("SS", registers->ss);
  PR("BP", registers->bp);
  PR("SI", registers->si);
  PR("DI", registers->di);
  PR("DS", registers->ds);
  PR("ES", registers->es);

  PR("FLAGS", registers->flags);
} 
