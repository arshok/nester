#include <stdint.h>

typedef uint8_t U8;   typedef int8_t S8;
typedef uint16_t U16; typedef int16_t S16;
typedef uint32_t U32; typedef int32_t S32;
typedef uint64_t U64; typedef int64_t S64;

typedef struct {
    U16 PC;
    U16 SP;
    U8 A,X,Y,SR;
}CPU;

#endif

