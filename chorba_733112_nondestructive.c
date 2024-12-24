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

#define bitbuffersizebytes (2 * 1024 * 1024)
#define bitbuffersizeqwords (bitbuffersizebytes / sizeof(uint64_t))

uint32_t chorba_733112_nondestructive (uint32_t crc, char* buf, size_t len) {
    char* input = buf;
    uint64_t* bitbuffer = calloc(bitbuffersizeqwords, sizeof(uint64_t));
    char* bitbufferbytes = (char*) bitbuffer;

    bitbuffer[0] = crc;
    crc = 0;

    int i = 0;

    for(; i + 733112+64 < len; i += 64) {
        uint64_t in1;
        uint64_t in2;
        uint64_t in3;
        uint64_t in4;
        uint64_t in5;
        uint64_t in6;
        uint64_t in7;
        uint64_t in8;

        uint64_t out1;
        uint64_t out2;
        uint64_t out3;
        uint64_t out4;
        uint64_t out5;
        uint64_t out6;
        uint64_t out7;
        uint64_t out8;

        in1 = *((uint64_t*) (input + i + (8*0))) ^ bitbuffer[(0 + (i / sizeof(uint64_t))) % bitbuffersizeqwords];
        in2 = *((uint64_t*) (input + i + (8*1))) ^ bitbuffer[(1 + (i / sizeof(uint64_t))) % bitbuffersizeqwords];
        in3 = *((uint64_t*) (input + i + (8*2))) ^ bitbuffer[(2 + (i / sizeof(uint64_t))) % bitbuffersizeqwords];
        in4 = *((uint64_t*) (input + i + (8*3))) ^ bitbuffer[(3 + (i / sizeof(uint64_t))) % bitbuffersizeqwords];
        in5 = *((uint64_t*) (input + i + (8*4))) ^ bitbuffer[(4 + (i / sizeof(uint64_t))) % bitbuffersizeqwords];
        in6 = *((uint64_t*) (input + i + (8*5))) ^ bitbuffer[(5 + (i / sizeof(uint64_t))) % bitbuffersizeqwords];
        in7 = *((uint64_t*) (input + i + (8*6))) ^ bitbuffer[(6 + (i / sizeof(uint64_t))) % bitbuffersizeqwords];
        in8 = *((uint64_t*) (input + i + (8*7))) ^ bitbuffer[(7 + (i / sizeof(uint64_t))) % bitbuffersizeqwords];


        out1 = in1;
        out2 = in2;
        out3 = in3;
        out4 = in4;
        out5 = in5;
        out6 = in6;
        out7 = in7;
        out8 = in8;


        int offset1 = (733112 - 333424) / 8;
        int offset2 = 733112 / 8;
        bitbuffer[(offset1 + 0 + (i / sizeof(uint64_t))) % bitbuffersizeqwords] ^= out1;
        bitbuffer[(offset1 + 1 + (i / sizeof(uint64_t))) % bitbuffersizeqwords] ^= out2;
        bitbuffer[(offset1 + 2 + (i / sizeof(uint64_t))) % bitbuffersizeqwords] ^= out3;
        bitbuffer[(offset1 + 3 + (i / sizeof(uint64_t))) % bitbuffersizeqwords] ^= out4;
        bitbuffer[(offset1 + 4 + (i / sizeof(uint64_t))) % bitbuffersizeqwords] ^= out5;
        bitbuffer[(offset1 + 5 + (i / sizeof(uint64_t))) % bitbuffersizeqwords] ^= out6;
        bitbuffer[(offset1 + 6 + (i / sizeof(uint64_t))) % bitbuffersizeqwords] ^= out7;
        bitbuffer[(offset1 + 7 + (i / sizeof(uint64_t))) % bitbuffersizeqwords] ^= out8;
        bitbuffer[(offset2 + 0 + (i / sizeof(uint64_t))) % bitbuffersizeqwords] = out1;
        bitbuffer[(offset2 + 1 + (i / sizeof(uint64_t))) % bitbuffersizeqwords] = out2;
        bitbuffer[(offset2 + 2 + (i / sizeof(uint64_t))) % bitbuffersizeqwords] = out3;
        bitbuffer[(offset2 + 3 + (i / sizeof(uint64_t))) % bitbuffersizeqwords] = out4;
        bitbuffer[(offset2 + 4 + (i / sizeof(uint64_t))) % bitbuffersizeqwords] = out5;
        bitbuffer[(offset2 + 5 + (i / sizeof(uint64_t))) % bitbuffersizeqwords] = out6;
        bitbuffer[(offset2 + 6 + (i / sizeof(uint64_t))) % bitbuffersizeqwords] = out7;
        bitbuffer[(offset2 + 7 + (i / sizeof(uint64_t))) % bitbuffersizeqwords] = out8;
    }

    // clear end of bitbuffer
    for (int j = 733112 / 8; j < (733112 / 8) + 100; j++) {
        bitbuffer[(j + (i / sizeof(uint64_t))) % bitbuffersizeqwords] = 0;
    }

    uint64_t next1 = 0;
    uint64_t next2 = 0;
    uint64_t next3 = 0;
    uint64_t next4 = 0;
    uint64_t next5 = 0;
    uint64_t next6 = 0;
    char final[200] = {0};

    for(; i < ((int) len) - 120; i += 32) {
        uint64_t in1;
        uint64_t in2;
        uint64_t in3;
        uint64_t in4;
        uint64_t a1, a2, a3, a4;
        uint64_t b1, b2, b3, b4;
        uint64_t c1, c2, c3, c4;
        uint64_t d1, d2, d3, d4;

        uint64_t out1;
        uint64_t out2;
        uint64_t out3;
        uint64_t out4;
        uint64_t out5;

        in1 = *((uint64_t*) (input + i)) ^ next1 ^ bitbuffer[(i/8) % bitbuffersizeqwords];
        in2 = *((uint64_t*) (input + i + (8*1))) ^ next2 ^ bitbuffer[(i/8 + 1) % bitbuffersizeqwords];

        a1 = (in1 << 17) ^ (in1 << 55);
        a2 = (in1 >> 47) ^ (in1 >> 9) ^ (in1 << 19);
        a3 = (in1 >> 45) ^ (in1 << 44);
        a4 = (in1 >> 20);
        
        b1 = (in2 << 17) ^ (in2 << 55);
        b2 = (in2 >> 47) ^ (in2 >> 9) ^ (in2 << 19);
        b3 = (in2 >> 45) ^ (in2 << 44);
        b4 = (in2 >> 20);

        in3 = *((uint64_t*) (input + i + (8*2))) ^ next3 ^ a1 ^ bitbuffer[(i/8 + 2) % bitbuffersizeqwords];
        in4 = *((uint64_t*) (input + i + (8*3))) ^ next4 ^ a2 ^ b1 ^ bitbuffer[(i/8 + 3) % bitbuffersizeqwords];

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
        crc = crc32_table[(crc ^ final[j] ^ bitbufferbytes[(j+i) % bitbuffersizebytes]) & 0xff] ^ (crc >> 8);
    }

    free(bitbuffer);
    return crc;
}
