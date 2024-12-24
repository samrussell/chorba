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

// This is a WIP, the idea is to write a table-less function for the final ~40 bytes
// It is slower than the Sarwate table lookup method but it is interesting for completeness
// The Barrett Reduction is actually not too far off performance-wise.
uint32_t chorba_end (uint32_t crc, char* buf, size_t len) {
    char* input = buf;
    unsigned char final[16] = {0};

    int i = 0;
    uint64_t next = crc;
    crc = 0;

    for(; i + 16 < len; i += 8) {
        uint64_t in = *((uint64_t*) (input + i)) ^ next;
        uint64_t in1 = in & 0xffffffff;
        uint64_t in2 = in >> 32;
        uint64_t in1_10001 = (in1 << 4) ^ in1;
        uint64_t out1 = in1 << 1;
        uint64_t out2 = in1 << 2;
        uint64_t out3 = in1_10001 << 3;
        uint64_t out4 = in1 << 4;
        uint64_t out6 = in1_10001 << 17;
        uint64_t out7 = in1_10001 << 19;
        uint64_t out10 = in1_10001 << 26;
        uint64_t out11 = in1_10001 << 27;
        uint64_t in2_101 = (in2 << 2) ^ in2;
        uint64_t in2_1001 = (in2 << 3) ^ in2;
        uint64_t out14 = in2_101;
        uint64_t out15 = in2_1001 << 5;
        uint64_t out16 = in2_1001 << 6;
        uint64_t out17 = in2_1001 << 10;
        uint64_t out18 = in2 << 14;
        uint64_t out19 = in2_1001 << 18;
        uint64_t out20 = in2 << 19;
        uint64_t out21 = in2_1001 << 20;
        uint64_t out22 = in2_101 << 27;
        uint64_t out23 = in2_1001 << 28;

        next = out1
             ^ out2
             ^ out3
             ^ out4
             ^ out6
             ^ out7
             ^ out10
             ^ out11
             ^ out14
             ^ out15
             ^ out16
             ^ out17
             ^ out18
             ^ out19
             ^ out20
             ^ out21
             ^ out22
             ^ out23;
    }

    memcpy(final, input+i, len-i);
    *((uint64_t*) (final + (0*8))) ^= next;
    
    // up to 24 bytes left
    // fold down to 16 and then barrett reduction

    // RFC 1952
    for(int j = 0; j<len-i; j++) {
        crc = crc32_table[(crc ^ final[j]) & 0xff] ^ (crc >> 8);
    }

    return crc;
}
