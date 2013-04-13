#ifndef NES_CPU_6502_H
#define NES_CPU_6502_H

#include "defines.h"

typedef struct {
    U16 PC;
    U16 SP;
    U8 A,X,Y,SR;
}CPU;

#endif

