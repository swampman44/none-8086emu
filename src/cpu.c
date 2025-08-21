#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "cpu.h"

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
