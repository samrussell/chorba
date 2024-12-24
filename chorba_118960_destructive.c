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

extern uint32_t crc32_table[256];

uint32_t chorba_118960_destructive (uint32_t crc, char* buf, size_t len) {
    char* input = buf;
    *((uint32_t*) (input)) ^= crc;
    crc = 0;

    int i = 0;

    uint64_t next1 = 0;
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

    for(; i + 118960 + 176 < len; i += 176) {
        uint64_t in1, in2, in3, in4, in5, in6, in7, in8;
        uint64_t in9, in10, in11, in12, in13, in14, in15, in16;
        uint64_t in17, in18, in19, in20, in21, in22;

        in1 = *((uint64_t*) (input + i + (0*8))) ^ next1;
        in2 = *((uint64_t*) (input + i + (1*8))) ^ next2;
        in3 = *((uint64_t*) (input + i + (2*8))) ^ next3;
        in4 = *((uint64_t*) (input + i + (3*8))) ^ next4;
        in5 = *((uint64_t*) (input + i + (4*8))) ^ next5;
        in6 = *((uint64_t*) (input + i + (5*8))) ^ next6;
        in7 = *((uint64_t*) (input + i + (6*8))) ^ next7;
        in8 = *((uint64_t*) (input + i + (7*8))) ^ next8 ^ in1;
        in9 = *((uint64_t*) (input + i + (8*8))) ^ next9 ^ in2;
        in10 = *((uint64_t*) (input + i + (9*8))) ^ next10 ^ in3;
        in11 = *((uint64_t*) (input + i + (10*8))) ^ next11 ^ in4;
        in12 = *((uint64_t*) (input + i + (11*8))) ^ next12 ^ in1 ^ in5;
        in13 = *((uint64_t*) (input + i + (12*8))) ^ next13 ^ in2 ^ in6;
        in14 = *((uint64_t*) (input + i + (13*8))) ^ next14 ^ in3 ^ in7;
        in15 = *((uint64_t*) (input + i + (14*8))) ^ next15 ^ in4 ^ in8;
        in16 = *((uint64_t*) (input + i + (15*8))) ^ next16 ^ in5 ^ in9;
        in17 = *((uint64_t*) (input + i + (16*8))) ^ next17 ^ in6 ^ in10;
        in18 = *((uint64_t*) (input + i + (17*8))) ^ next18 ^ in7 ^ in11;
        in19 = *((uint64_t*) (input + i + (18*8))) ^ next19 ^ in8 ^ in12;
        in20 = *((uint64_t*) (input + i + (19*8))) ^ next20 ^ in9 ^ in13;
        in21 = *((uint64_t*) (input + i + (20*8))) ^ next21 ^ in10 ^ in14;
        in22 = *((uint64_t*) (input + i + (21*8))) ^ next22 ^ in11 ^ in15;

        next1 = in1 ^ in12 ^ in16;
        next2 = in2 ^ in13 ^ in17;
        next3 = in3 ^ in14 ^ in18;
        next4 = in4 ^ in15 ^ in19;
        next5 = in5 ^ in16 ^ in20;
        next6 = in6 ^ in17 ^ in21;
        next7 = in7 ^ in18 ^ in22;
        next8 = in8 ^ in19;
        next9 = in9 ^ in20;
        next10 = in10 ^ in21;
        next11 = in11 ^ in22;
        next12 = in12;
        next13 = in13;
        next14 = in14;
        next15 = in15;
        next16 = in16;
        next17 = in17;
        next18 = in18;
        next19 = in19;
        next20 = in20;
        next21 = in21;
        next22 = in22;

        *((uint64_t*) (input + 118960 + (0*8) + i)) ^= in1;
        *((uint64_t*) (input + 118960 + (1*8) + i)) ^= in2;
        *((uint64_t*) (input + 118960 + (2*8) + i)) ^= in3;
        *((uint64_t*) (input + 118960 + (3*8) + i)) ^= in4;
        *((uint64_t*) (input + 118960 + (4*8) + i)) ^= in5;
        *((uint64_t*) (input + 118960 + (5*8) + i)) ^= in6;
        *((uint64_t*) (input + 118960 + (6*8) + i)) ^= in7;
        *((uint64_t*) (input + 118960 + (7*8) + i)) ^= in8;
        *((uint64_t*) (input + 118960 + (8*8) + i)) ^= in9;
        *((uint64_t*) (input + 118960 + (9*8) + i)) ^= in10;
        *((uint64_t*) (input + 118960 + (10*8) + i)) ^= in11;
        *((uint64_t*) (input + 118960 + (11*8) + i)) ^= in12;
        *((uint64_t*) (input + 118960 + (12*8) + i)) ^= in13;
        *((uint64_t*) (input + 118960 + (13*8) + i)) ^= in14;
        *((uint64_t*) (input + 118960 + (14*8) + i)) ^= in15;
        *((uint64_t*) (input + 118960 + (15*8) + i)) ^= in16;
        *((uint64_t*) (input + 118960 + (16*8) + i)) ^= in17;
        *((uint64_t*) (input + 118960 + (17*8) + i)) ^= in18;
        *((uint64_t*) (input + 118960 + (18*8) + i)) ^= in19;
        *((uint64_t*) (input + 118960 + (19*8) + i)) ^= in20;
        *((uint64_t*) (input + 118960 + (20*8) + i)) ^= in21;
        *((uint64_t*) (input + 118960 + (21*8) + i)) ^= in22;
    }
    

    *((uint64_t*) (input + (0*8) + i)) ^= next1;
    *((uint64_t*) (input + (1*8) + i)) ^= next2;
    *((uint64_t*) (input + (2*8) + i)) ^= next3;
    *((uint64_t*) (input + (3*8) + i)) ^= next4;
    *((uint64_t*) (input + (4*8) + i)) ^= next5;
    *((uint64_t*) (input + (5*8) + i)) ^= next6;
    *((uint64_t*) (input + (6*8) + i)) ^= next7;
    *((uint64_t*) (input + (7*8) + i)) ^= next8;
    *((uint64_t*) (input + (8*8) + i)) ^= next9;
    *((uint64_t*) (input + (9*8) + i)) ^= next10;
    *((uint64_t*) (input + (10*8) + i)) ^= next11;
    *((uint64_t*) (input + (11*8) + i)) ^= next12;
    *((uint64_t*) (input + (12*8) + i)) ^= next13;
    *((uint64_t*) (input + (13*8) + i)) ^= next14;
    *((uint64_t*) (input + (14*8) + i)) ^= next15;
    *((uint64_t*) (input + (15*8) + i)) ^= next16;
    *((uint64_t*) (input + (16*8) + i)) ^= next17;
    *((uint64_t*) (input + (17*8) + i)) ^= next18;
    *((uint64_t*) (input + (18*8) + i)) ^= next19;
    *((uint64_t*) (input + (19*8) + i)) ^= next20;
    *((uint64_t*) (input + (20*8) + i)) ^= next21;
    *((uint64_t*) (input + (21*8) + i)) ^= next22;

    next1 = 0;
    next2 = 0;
    next3 = 0;
    next4 = 0;
    next5 = 0;
    next6 = 0;
    char final[200] = {0};

    for(; i < ((int) len) - 120; i += 32) {
        uint64_t in1;
        uint64_t in2;
        uint64_t in3;
        uint64_t in4;
        uint64_t in5;
        uint64_t in6;
        uint64_t in7;
        uint64_t in8;
        uint64_t a1, a2, a3, a4;
        uint64_t b1, b2, b3, b4;
        uint64_t c1, c2, c3, c4;
        uint64_t d1, d2, d3, d4;

        uint64_t out1;
        uint64_t out2;
        uint64_t out3;
        uint64_t out4;
        uint64_t out5;
        uint64_t out6;
        uint64_t out7;
        uint64_t out8;

        in1 = *((uint64_t*) (input + i)) ^ next1;
        in2 = *((uint64_t*) (input + i + (8*1))) ^ next2;

        a1 = (in1 << 17) ^ (in1 << 55);
        a2 = (in1 >> 47) ^ (in1 >> 9) ^ (in1 << 19);
        a3 = (in1 >> 45) ^ (in1 << 44);
        a4 = (in1 >> 20);
        
        b1 = (in2 << 17) ^ (in2 << 55);
        b2 = (in2 >> 47) ^ (in2 >> 9) ^ (in2 << 19);
        b3 = (in2 >> 45) ^ (in2 << 44);
        b4 = (in2 >> 20);

        in3 = *((uint64_t*) (input + i + (8*2))) ^ next3 ^ a1;
        in4 = *((uint64_t*) (input + i + (8*3))) ^ next4 ^ a2 ^ b1;

        c1 = (in3 << 17) ^ (in3 << 55);
        c2 = (in3 >> 47) ^ (in3 >> 9) ^ (in3 << 19);
        c3 = (in3 >> 45) ^ (in3 << 44);
        c4 = (in3 >> 20);
        
        d1 = (in4 << 17) ^ (in4 << 55);
        d2 = (in4 >> 47) ^ (in4 >> 9) ^ (in4 << 19);
        d3 = (in4 >> 45) ^ (in4 << 44);
        d4 = (in4 >> 20);

        out1 = a3 ^ b2 ^ c1;
        out2 = a4 ^ b3 ^ c2 ^ d1;
        out3 = b4 ^ c3 ^ d2;
        out4 = c4 ^ d3;
        out5 = d4;

        next1 = next5 ^ out1;
        next2 = out2;
        next3 = out3;
        next4 = out4;
        next5 = out5;

    }

    memcpy(final, input+i, len-i);
    *((uint64_t*) (final + (0*8))) ^= next1;
    *((uint64_t*) (final + (1*8))) ^= next2;
    *((uint64_t*) (final + (2*8))) ^= next3;
    *((uint64_t*) (final + (3*8))) ^= next4;
    *((uint64_t*) (final + (4*8))) ^= next5;

    // RFC 1952
    for(int j = 0; j<len-i; j++) {
        crc = crc32_table[(crc ^ final[j]) & 0xff] ^ (crc >> 8);
    }

    return crc;
}
