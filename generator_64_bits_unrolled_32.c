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

uint32_t generator_64_bits_unrolled_32 (uint32_t crc, char* buf, size_t len) {
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

    for(; i + 256 < len; i += 256) {
        // 1110 1101 1011 1000 1000 0011 0010 0000
        uint64_t in1 = *((uint64_t*) (input + i + (0*8))) ^ next1;
        uint64_t in2 = *((uint64_t*) (input + i + (1*8))) ^ next2;
        uint64_t in3 = *((uint64_t*) (input + i + (2*8))) ^ next3;
        uint64_t in4 = *((uint64_t*) (input + i + (3*8))) ^ next4;
        uint64_t in5 = *((uint64_t*) (input + i + (4*8))) ^ next5;
        uint64_t in6 = *((uint64_t*) (input + i + (5*8))) ^ next6;
        uint64_t in7 = *((uint64_t*) (input + i + (6*8))) ^ next7 ^ in1;
        uint64_t in8 = *((uint64_t*) (input + i + (7*8))) ^ next8 ^ in2;
        uint64_t in9 = *((uint64_t*) (input + i + (8*8))) ^ next9 ^ in3;
        uint64_t in10 = *((uint64_t*) (input + i + (9*8))) ^ next10 ^ in1 ^ in4;
        uint64_t in11 = *((uint64_t*) (input + i + (10*8))) ^ next11 ^ in1 ^ in2 ^ in5;
        uint64_t in12 = *((uint64_t*) (input + i + (11*8))) ^ next12 ^ in2 ^ in3 ^ in6;
        uint64_t in13 = *((uint64_t*) (input + i + (12*8))) ^ next13 ^ in3 ^ in4 ^ in7;
        uint64_t in14 = *((uint64_t*) (input + i + (13*8))) ^ next14 ^ in4 ^ in5 ^ in8;
        uint64_t in15 = *((uint64_t*) (input + i + (14*8))) ^ next15 ^ in5 ^ in6 ^ in9;
        uint64_t in16 = *((uint64_t*) (input + i + (15*8))) ^ next16 ^ in6 ^ in7 ^ in10;
        uint64_t in17 = *((uint64_t*) (input + i + (16*8))) ^ next17 ^ in1 ^ in7 ^ in8 ^ in11;
        uint64_t in18 = *((uint64_t*) (input + i + (17*8))) ^ next18 ^ in2 ^ in8 ^ in9 ^ in12;
        uint64_t in19 = *((uint64_t*) (input + i + (18*8))) ^ next19 ^ in3 ^ in9 ^ in10 ^ in13;
        uint64_t in20 = *((uint64_t*) (input + i + (19*8))) ^ next20 ^ in4 ^ in10 ^ in11 ^ in14;
        uint64_t in21 = *((uint64_t*) (input + i + (20*8))) ^ next21 ^ in1 ^ in5 ^ in11 ^ in12 ^ in15;
        uint64_t in22 = *((uint64_t*) (input + i + (21*8))) ^ next22 ^ in1 ^ in2 ^ in6 ^ in12 ^ in13 ^ in16;
        uint64_t in23 = *((uint64_t*) (input + i + (22*8))) ^ next23 ^ in1 ^ in2 ^ in3 ^ in7 ^ in13 ^ in14 ^ in17;
        uint64_t in24 = *((uint64_t*) (input + i + (23*8))) ^ next24 ^ in2 ^ in3 ^ in4 ^ in8 ^ in14 ^ in15 ^ in18;
        uint64_t in25 = *((uint64_t*) (input + i + (24*8))) ^ next25 ^ in1 ^ in3 ^ in4 ^ in5 ^ in9 ^ in15 ^ in16 ^ in19;
        uint64_t in26 = *((uint64_t*) (input + i + (25*8))) ^ next26 ^ in1 ^ in2 ^ in4 ^ in5 ^ in6 ^ in10 ^ in16 ^ in17 ^ in20;
        uint64_t in27 = *((uint64_t*) (input + i + (26*8))) ^ next27 ^ in2 ^ in3 ^ in5 ^ in6 ^ in7 ^ in11 ^ in17 ^ in18 ^ in21;
        uint64_t in28 = *((uint64_t*) (input + i + (27*8))) ^ next28 ^ in1 ^ in3 ^ in4 ^ in6 ^ in7 ^ in8 ^ in12 ^ in18 ^ in19 ^ in22;
        uint64_t in29 = *((uint64_t*) (input + i + (28*8))) ^ next29 ^ in1 ^ in2 ^ in4 ^ in5 ^ in7 ^ in8 ^ in9 ^ in13 ^ in19 ^ in20 ^ in23;
        uint64_t in30 = *((uint64_t*) (input + i + (29*8))) ^ next30 ^ in2 ^ in3 ^ in5 ^ in6 ^ in8 ^ in9 ^ in10 ^ in14 ^ in20 ^ in21 ^ in24;
        uint64_t in31 = *((uint64_t*) (input + i + (30*8))) ^ next31 ^ in1 ^ in3 ^ in4 ^ in6 ^ in7 ^ in9 ^ in10 ^ in11 ^ in15 ^ in21 ^ in22 ^ in25;
        uint64_t in32 = *((uint64_t*) (input + i + (31*8))) ^ next32 ^ in1 ^ in2 ^ in4 ^ in5 ^ in7 ^ in8 ^ in10 ^ in11 ^ in12 ^ in16 ^ in22 ^ in23 ^ in26;

        next1 = in1 ^ in2 ^ in3 ^ in5 ^ in6 ^ in8 ^ in9 ^ in11 ^ in12 ^ in13 ^ in17 ^ in23 ^ in24 ^ in27;
        next2 = in2 ^ in3 ^ in4 ^ in6 ^ in7 ^ in9 ^ in10 ^ in12 ^ in13 ^ in14 ^ in18 ^ in24 ^ in25 ^ in28;
        next3 = in3 ^ in4 ^ in5 ^ in7 ^ in8 ^ in10 ^ in11 ^ in13 ^ in14 ^ in15 ^ in19 ^ in25 ^ in26 ^ in29;
        next4 = in4 ^ in5 ^ in6 ^ in8 ^ in9 ^ in11 ^ in12 ^ in14 ^ in15 ^ in16 ^ in20 ^ in26 ^ in27 ^ in30;
        next5 = in5 ^ in6 ^ in7 ^ in9 ^ in10 ^ in12 ^ in13 ^ in15 ^ in16 ^ in17 ^ in21 ^ in27 ^ in28 ^ in31;
        next6 = in6 ^ in7 ^ in8 ^ in10 ^ in11 ^ in13 ^ in14 ^ in16 ^ in17 ^ in18 ^ in22 ^ in28 ^ in29 ^ in32;
        next7 = in7 ^ in8 ^ in9 ^ in11 ^ in12 ^ in14 ^ in15 ^ in17 ^ in18 ^ in19 ^ in23 ^ in29 ^ in30;
        next8 = in8 ^ in9 ^ in10 ^ in12 ^ in13 ^ in15 ^ in16 ^ in18 ^ in19 ^ in20 ^ in24 ^ in30 ^ in31;
        next9 = in9 ^ in10 ^ in11 ^ in13 ^ in14 ^ in16 ^ in17 ^ in19 ^ in20 ^ in21 ^ in25 ^ in31 ^ in32;
        next10 = in10 ^ in11 ^ in12 ^ in14 ^ in15 ^ in17 ^ in18 ^ in20 ^ in21 ^ in22 ^ in26 ^ in32;
        next11 = in11 ^ in12 ^ in13 ^ in15 ^ in16 ^ in18 ^ in19 ^ in21 ^ in22 ^ in23 ^ in27;
        next12 = in12 ^ in13 ^ in14 ^ in16 ^ in17 ^ in19 ^ in20 ^ in22 ^ in23 ^ in24 ^ in28;
        next13 = in13 ^ in14 ^ in15 ^ in17 ^ in18 ^ in20 ^ in21 ^ in23 ^ in24 ^ in25 ^ in29;
        next14 = in14 ^ in15 ^ in16 ^ in18 ^ in19 ^ in21 ^ in22 ^ in24 ^ in25 ^ in26 ^ in30;
        next15 = in15 ^ in16 ^ in17 ^ in19 ^ in20 ^ in22 ^ in23 ^ in25 ^ in26 ^ in27 ^ in31;
        next16 = in16 ^ in17 ^ in18 ^ in20 ^ in21 ^ in23 ^ in24 ^ in26 ^ in27 ^ in28 ^ in32;
        next17 = in17 ^ in18 ^ in19 ^ in21 ^ in22 ^ in24 ^ in25 ^ in27 ^ in28 ^ in29;
        next18 = in18 ^ in19 ^ in20 ^ in22 ^ in23 ^ in25 ^ in26 ^ in28 ^ in29 ^ in30;
        next19 = in19 ^ in20 ^ in21 ^ in23 ^ in24 ^ in26 ^ in27 ^ in29 ^ in30 ^ in31;
        next20 = in20 ^ in21 ^ in22 ^ in24 ^ in25 ^ in27 ^ in28 ^ in30 ^ in31 ^ in32;
        next21 = in21 ^ in22 ^ in23 ^ in25 ^ in26 ^ in28 ^ in29 ^ in31 ^ in32;
        next22 = in22 ^ in23 ^ in24 ^ in26 ^ in27 ^ in29 ^ in30 ^ in32;
        next23 = in23 ^ in24 ^ in25 ^ in27 ^ in28 ^ in30 ^ in31;
        next24 = in24 ^ in25 ^ in26 ^ in28 ^ in29 ^ in31 ^ in32;
        next25 = in25 ^ in26 ^ in27 ^ in29 ^ in30 ^ in32;
        next26 = in26 ^ in27 ^ in28 ^ in30 ^ in31;
        next27 = in27 ^ in28 ^ in29 ^ in31 ^ in32;
        next28 = in28 ^ in29 ^ in30 ^ in32;
        next29 = in29 ^ in30 ^ in31;
        next30 = in30 ^ in31 ^ in32;
        next31 = in31 ^ in32;
        next32 = in32;
    }

    unsigned char final[256 + 256];

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
