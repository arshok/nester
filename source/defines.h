#ifndef NES_DEFINES_6502_H
#define NES_DEFINES_6502_H

#include <utility>
#include <assert.h>
#include <stdint.h>

typedef uint8_t U8;   typedef int8_t S8;
typedef uint16_t U16; typedef int16_t S16;
typedef uint32_t U32; typedef int32_t S32;
typedef uint64_t U64; typedef int64_t S64;

enum AddressMode {
    IMM,
    ZP,
    ZPX,
    ABS,
    ABSX,
    ABSY,
    INDX,
    INDY
};

class REG8 {
    inline REG8():_r{0} {
    }
    REG8(U8&& v):
        _r{std::move(v)} {
    }
    explicit REG8(const U8& v):
        _r{v} {
    }
    ~REG8(){ 
        _r = 0; 
    }
    const U8 hi() const {
        return static_cast<U8>((_r & 0xF0)) >> 8u;
    }
    const U8 lo() const {
        return static_cast<U8>((_r & 0x0F));
    }
    operator const U8& () {
        return _r;
    }
    operator U8 () {
        return _r;
    }
    U8 operator[](const U8 bitIndex) {
        assert (bitIndex < 7u && "invalid byte index.");
        return (_r & (1u << bitIndex)) == 0u ? 0u : 1u;
    }
    REG8& operator=(const U8& rhs) {
        _r = rhs.r;
        return (*this);
    }
    bool operator==(REG8&& rhs) {
        return _r == std::move(rhs)._r;
    }
    bool operator==(const REG8& rhs) {
        return _r == rhs._r;
    }
    bool operator!=(const REG8& rhs) {
        return !((*this)==rhs);
    }
};

#endif
