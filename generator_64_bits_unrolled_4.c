/*
  Copyright (C) 2024 Sam Russell

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  Sam Russell
  sam.h.russell@gmail.com
*/

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

uint32_t generator_64_bits_unrolled_4 (uint32_t crc, char* buf, size_t len) {
    unsigned char* input = buf;

    uint64_t next1 = crc;
    crc = 0;
    uint64_t next2 = 0;
    uint64_t next3 = 0;
    uint64_t next4 = 0;
    uint64_t next5 = 0;
    uint64_t next6 = 0;
    uint64_t next7 = 0;
    uint64_t next8 = 0;
    uint64_t next9 = 0;
    uint64_t next10 = 0;
    uint64_t next11 = 0;
    uint64_t next12 = 0;
    uint64_t next13 = 0;
    uint64_t next14 = 0;
    uint64_t next15 = 0;
    uint64_t next16 = 0;
    uint64_t next17 = 0;
    uint64_t next18 = 0;
    uint64_t next19 = 0;
    uint64_t next20 = 0;
    uint64_t next21 = 0;
    uint64_t next22 = 0;
    uint64_t next23 = 0;
    uint64_t next24 = 0;
    uint64_t next25 = 0;
    uint64_t next26 = 0;
    uint64_t next27 = 0;
    uint64_t next28 = 0;
    uint64_t next29 = 0;
    uint64_t next30 = 0;
    uint64_t next31 = 0;
    uint64_t next32 = 0;
    int i = 0;

    for(; i + 256 < len; i += 32) {
        // 1110 1101 1011 1000 1000 0011 0010 0000
        uint64_t in1 = *((uint64_t*) (input + i + (0*8))) ^ next1;
        uint64_t in2 = *((uint64_t*) (input + i + (1*8))) ^ next2;
        uint64_t in3 = *((uint64_t*) (input + i + (2*8))) ^ next3;
        uint64_t in4 = *((uint64_t*) (input + i + (3*8))) ^ next4;
        next1 = next5;
        next2 = next6;
        next3 = next7 ^ in1;
        next4 = next8 ^ in2;
        next5 = next9 ^ in3;
        next6 = next10 ^ in1 ^ in4;
        next7 = next11 ^ in1 ^ in2;
        next8 = next12 ^ in2 ^ in3;
        next9 = next13 ^ in3 ^ in4;
        next10 = next14 ^ in4;
        next11 = next15;
        next12 = next16;
        next13 = next17 ^ in1;
        next14 = next18 ^ in2;
        next15 = next19 ^ in3;
        next16 = next20 ^ in4;
        next17 = next21 ^ in1;
        next18 = next22 ^ in1 ^ in2;
        next19 = next23 ^ in1 ^ in2 ^ in3;
        next20 = next24 ^ in2 ^ in3 ^ in4;
        next21 = next25 ^ in1 ^ in3 ^ in4;
        next22 = next26 ^ in1 ^ in2 ^ in4;
        next23 = next27 ^ in2 ^ in3;
        next24 = next28 ^ in1 ^ in3 ^ in4;
        next25 = next29 ^ in1 ^ in2 ^ in4;
        next26 = next30 ^ in2 ^ in3;
        next27 = next31 ^ in1 ^ in3 ^ in4;
        next28 = next32 ^ in1 ^ in2 ^ in4;
        next29 = in1 ^ in2 ^ in3;
        next30 = in2 ^ in3 ^ in4;
        next31 = in3 ^ in4;
        next32 = in4;
    }

    unsigned char final[256 + 32];

    memcpy(final, input + i, len - i);
    *((uint64_t*) (final + 8*(1-1))) ^= next1;
    *((uint64_t*) (final + 8*(2-1))) ^= next2;
    *((uint64_t*) (final + 8*(3-1))) ^= next3;
    *((uint64_t*) (final + 8*(4-1))) ^= next4;
    *((uint64_t*) (final + 8*(5-1))) ^= next5;
    *((uint64_t*) (final + 8*(6-1))) ^= next6;
    *((uint64_t*) (final + 8*(7-1))) ^= next7;
    *((uint64_t*) (final + 8*(8-1))) ^= next8;
    *((uint64_t*) (final + 8*(9-1))) ^= next9;
    *((uint64_t*) (final + 8*(10-1))) ^= next10;
    *((uint64_t*) (final + 8*(11-1))) ^= next11;
    *((uint64_t*) (final + 8*(12-1))) ^= next12;
    *((uint64_t*) (final + 8*(13-1))) ^= next13;
    *((uint64_t*) (final + 8*(14-1))) ^= next14;
    *((uint64_t*) (final + 8*(15-1))) ^= next15;
    *((uint64_t*) (final + 8*(16-1))) ^= next16;
    *((uint64_t*) (final + 8*(17-1))) ^= next17;
    *((uint64_t*) (final + 8*(18-1))) ^= next18;
    *((uint64_t*) (final + 8*(19-1))) ^= next19;
    *((uint64_t*) (final + 8*(20-1))) ^= next20;
    *((uint64_t*) (final + 8*(21-1))) ^= next21;
    *((uint64_t*) (final + 8*(22-1))) ^= next22;
    *((uint64_t*) (final + 8*(23-1))) ^= next23;
    *((uint64_t*) (final + 8*(24-1))) ^= next24;
    *((uint64_t*) (final + 8*(25-1))) ^= next25;
    *((uint64_t*) (final + 8*(26-1))) ^= next26;
    *((uint64_t*) (final + 8*(27-1))) ^= next27;
    *((uint64_t*) (final + 8*(28-1))) ^= next28;
    *((uint64_t*) (final + 8*(29-1))) ^= next29;
    *((uint64_t*) (final + 8*(30-1))) ^= next30;
    *((uint64_t*) (final + 8*(31-1))) ^= next31;
    *((uint64_t*) (final + 8*(32-1))) ^= next32;

    for(int j = 0; i + j < len; j++) {
        crc ^= final[j];

        for (int k = 0; k < 8; k++) {
            if (crc & 1)
                crc = (crc >> 1) ^ 0xEDB88320;
            else
                crc = (crc >> 1);
        }
    }

    return crc;
}
