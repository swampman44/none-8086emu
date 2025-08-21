#ifndef MEMORY_H
#define MEMORY_H

#define MEMORY_SIZE 1024*1024

typedef struct Memory {
  uint32_t ram[MEMORY_SIZE];
} memory_t;

void populateMemoryOnInit(memory_t memory);
#endif // MEMORY_H
