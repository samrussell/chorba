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

uint32_t chorba_352_nondestructive (uint32_t crc, char* buf, size_t len) {
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
    uint64_t next33 = 0;
    uint64_t next34 = 0;
    uint64_t next35 = 0;
    uint64_t next36 = 0;
    uint64_t next37 = 0;
    uint64_t next38 = 0;
    uint64_t next39 = 0;
    uint64_t next40 = 0;
    uint64_t next41 = 0;
    uint64_t next42 = 0;
    uint64_t next43 = 0;
    uint64_t next44 = 0;
    int i = 0;

    for(; i + 352 < len; i += 64) {
        // 1110 1101 1011 1000 1000 0011 0010 0000
        uint64_t in1 = *((uint64_t*) (input + i + (0*8))) ^ next1;
        uint64_t in2 = *((uint64_t*) (input + i + (1*8))) ^ next2 ^ in1;
        uint64_t in3 = *((uint64_t*) (input + i + (2*8))) ^ next3 ^ in2;
        uint64_t in4 = *((uint64_t*) (input + i + (3*8))) ^ next4 ^ in1 ^ in3;
        uint64_t in5 = *((uint64_t*) (input + i + (4*8))) ^ next5 ^ in2 ^ in4;
        uint64_t in6 = *((uint64_t*) (input + i + (5*8))) ^ next6 ^ in3 ^ in5;
        uint64_t in7 = *((uint64_t*) (input + i + (6*8))) ^ next7 ^ in4 ^ in6;
        uint64_t in8 = *((uint64_t*) (input + i + (7*8))) ^ next8 ^ in1 ^ in5 ^ in7;
        next1 = next9 ^ in2 ^ in6 ^ in8;
        next2 = next10 ^ in1 ^ in3 ^ in7;
        next3 = next11 ^ in2 ^ in4 ^ in8;
        next4 = next12 ^ in3 ^ in5;
        next5 = next13 ^ in1 ^ in4 ^ in6;
        next6 = next14 ^ in1 ^ in2 ^ in5 ^ in7;
        next7 = next15 ^ in2 ^ in3 ^ in6 ^ in8;
        next8 = next16 ^ in3 ^ in4 ^ in7;
        next9 = next17 ^ in4 ^ in5 ^ in8;
        next10 = next18 ^ in5 ^ in6;
        next11 = next19 ^ in6 ^ in7;
        next12 = next20 ^ in7 ^ in8;
        next13 = next21 ^ in8;
        next14 = next22;
        next15 = next23;
        next16 = next24;
        next17 = next25;
        next18 = next26;
        next19 = next27;
        next20 = next28;
        next21 = next29 ^ in1;
        next22 = next30 ^ in2;
        next23 = next31 ^ in3;
        next24 = next32 ^ in4;
        next25 = next33 ^ in5;
        next26 = next34 ^ in6;
        next27 = next35 ^ in7;
        next28 = next36 ^ in8;
        next29 = next37;
        next30 = next38 ^ in1;
        next31 = next39 ^ in2;
        next32 = next40 ^ in1 ^ in3;
        next33 = next41 ^ in2 ^ in4;
        next34 = next42 ^ in3 ^ in5;
        next35 = next43 ^ in4 ^ in6;
        next36 = next44 ^ in5 ^ in7;
        next37 = in1 ^ in6 ^ in8;
        next38 = in2 ^ in7;
        next39 = in3 ^ in8;
        next40 = in4;
        next41 = in5;
        next42 = in6;
        next43 = in7;
        next44 = in8;
    }

    unsigned char final[352 + 64];

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
    *((uint64_t*) (final + 8*(33-1))) ^= next33;
    *((uint64_t*) (final + 8*(34-1))) ^= next34;
    *((uint64_t*) (final + 8*(35-1))) ^= next35;
    *((uint64_t*) (final + 8*(36-1))) ^= next36;
    *((uint64_t*) (final + 8*(37-1))) ^= next37;
    *((uint64_t*) (final + 8*(38-1))) ^= next38;
    *((uint64_t*) (final + 8*(39-1))) ^= next39;
    *((uint64_t*) (final + 8*(40-1))) ^= next40;
    *((uint64_t*) (final + 8*(41-1))) ^= next41;
    *((uint64_t*) (final + 8*(42-1))) ^= next42;
    *((uint64_t*) (final + 8*(43-1))) ^= next43;
    *((uint64_t*) (final + 8*(44-1))) ^= next44;

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
