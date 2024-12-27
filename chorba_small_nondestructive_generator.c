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

uint32_t chorba_small_nondestructive_generator (uint32_t crc, char* buf, size_t len) {
    char* input = buf;
    char final[200] = {0};
    uint64_t next1 = crc;
    crc = 0;
    uint64_t next2 = 0;
    uint64_t next3 = 0;
    uint64_t next4 = 0;
    uint64_t next5 = 0;
    uint64_t next6 = 0;

    int i = 0;
    for(; (i + 256 + 32 + 32 + 40) < len; i += 32) {
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

        uint64_t chorba1 = *((uint64_t*) (input + i)) ^ next1;
        uint64_t chorba2 = *((uint64_t*) (input + i + (8*1))) ^ next2;
        uint64_t chorba3 = *((uint64_t*) (input + i + (8*2))) ^ next3;
        uint64_t chorba4 = *((uint64_t*) (input + i + (8*3))) ^ next4;
        uint64_t chorba5 = *((uint64_t*) (input + i + (8*4))) ^ next5;
        uint64_t chorba6 = *((uint64_t*) (input + i + (8*5)));
        uint64_t chorba7 = *((uint64_t*) (input + i + (8*6))) ^ chorba1;
        uint64_t chorba8 = *((uint64_t*) (input + i + (8*7))) ^ chorba2;
        i += 8*8;

        /* 0-3 */
        in1 = *((uint64_t*) (input + i)) ^ chorba3;
        in2 = *((uint64_t*) (input + i + (8*1))) ^ chorba4 ^ chorba1;

        a1 = (in1 << 17) ^ (in1 << 55);
        a2 = (in1 >> 47) ^ (in1 >> 9) ^ (in1 << 19);
        a3 = (in1 >> 45) ^ (in1 << 44);
        a4 = (in1 >> 20);
        
        b1 = (in2 << 17) ^ (in2 << 55);
        b2 = (in2 >> 47) ^ (in2 >> 9) ^ (in2 << 19);
        b3 = (in2 >> 45) ^ (in2 << 44);
        b4 = (in2 >> 20);

        in3 = *((uint64_t*) (input + i + (8*2))) ^ a1 ^ chorba5 ^ chorba2 ^ chorba1;
        in4 = *((uint64_t*) (input + i + (8*3))) ^ a2 ^ b1 ^ chorba6 ^ chorba3 ^ chorba2;

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

        next1 = out1;
        next2 = out2;
        next3 = out3;
        next4 = out4;
        next5 = out5;

        i += 32;

        /* 4-7 */
        in1 = *((uint64_t*) (input + i)) ^ next1 ^ chorba7 ^ chorba4 ^ chorba3;
        in2 = *((uint64_t*) (input + i + (8*1))) ^ next2 ^ chorba8 ^ chorba5 ^ chorba4;

        a1 = (in1 << 17) ^ (in1 << 55);
        a2 = (in1 >> 47) ^ (in1 >> 9) ^ (in1 << 19);
        a3 = (in1 >> 45) ^ (in1 << 44);
        a4 = (in1 >> 20);
        
        b1 = (in2 << 17) ^ (in2 << 55);
        b2 = (in2 >> 47) ^ (in2 >> 9) ^ (in2 << 19);
        b3 = (in2 >> 45) ^ (in2 << 44);
        b4 = (in2 >> 20);

        in3 = *((uint64_t*) (input + i + (8*2))) ^ next3 ^ a1 ^ chorba6 ^ chorba5;
        in4 = *((uint64_t*) (input + i + (8*3))) ^ next4 ^ a2 ^ b1 ^ chorba7 ^ chorba6;

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

        i += 32;

        /* 8-11 */
        in1 = *((uint64_t*) (input + i)) ^ next1 ^ chorba8 ^ chorba7 ^ chorba1;
        in2 = *((uint64_t*) (input + i + (8*1))) ^ next2 ^ chorba8 ^ chorba2;

        a1 = (in1 << 17) ^ (in1 << 55);
        a2 = (in1 >> 47) ^ (in1 >> 9) ^ (in1 << 19);
        a3 = (in1 >> 45) ^ (in1 << 44);
        a4 = (in1 >> 20);
        
        b1 = (in2 << 17) ^ (in2 << 55);
        b2 = (in2 >> 47) ^ (in2 >> 9) ^ (in2 << 19);
        b3 = (in2 >> 45) ^ (in2 << 44);
        b4 = (in2 >> 20);

        in3 = *((uint64_t*) (input + i + (8*2))) ^ next3 ^ a1 ^ chorba3;
        in4 = *((uint64_t*) (input + i + (8*3))) ^ next4 ^ a2 ^ b1 ^ chorba4;

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

        i += 32;

        /* 12-15 */
        in1 = *((uint64_t*) (input + i)) ^ next1 ^ chorba5 ^ chorba1;
        in2 = *((uint64_t*) (input + i + (8*1))) ^ next2 ^ chorba6 ^ chorba2 ^ chorba1;

        a1 = (in1 << 17) ^ (in1 << 55);
        a2 = (in1 >> 47) ^ (in1 >> 9) ^ (in1 << 19);
        a3 = (in1 >> 45) ^ (in1 << 44);
        a4 = (in1 >> 20);
        
        b1 = (in2 << 17) ^ (in2 << 55);
        b2 = (in2 >> 47) ^ (in2 >> 9) ^ (in2 << 19);
        b3 = (in2 >> 45) ^ (in2 << 44);
        b4 = (in2 >> 20);

        in3 = *((uint64_t*) (input + i + (8*2))) ^ next3 ^ a1 ^ chorba7 ^ chorba3 ^ chorba2 ^ chorba1;
        in4 = *((uint64_t*) (input + i + (8*3))) ^ next4 ^ a2 ^ b1 ^ chorba8 ^ chorba4 ^ chorba3 ^ chorba2;

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

        i += 32;

        /* 16-19 */
        in1 = *((uint64_t*) (input + i)) ^ next1 ^ chorba5 ^ chorba4 ^ chorba3 ^ chorba1;
        in2 = *((uint64_t*) (input + i + (8*1))) ^ next2 ^ chorba6 ^ chorba5 ^ chorba4 ^ chorba1 ^ chorba2;

        a1 = (in1 << 17) ^ (in1 << 55);
        a2 = (in1 >> 47) ^ (in1 >> 9) ^ (in1 << 19);
        a3 = (in1 >> 45) ^ (in1 << 44);
        a4 = (in1 >> 20);
        
        b1 = (in2 << 17) ^ (in2 << 55);
        b2 = (in2 >> 47) ^ (in2 >> 9) ^ (in2 << 19);
        b3 = (in2 >> 45) ^ (in2 << 44);
        b4 = (in2 >> 20);

        in3 = *((uint64_t*) (input + i + (8*2))) ^ next3 ^ a1 ^ chorba7 ^ chorba6 ^ chorba5 ^ chorba2 ^ chorba3;
        in4 = *((uint64_t*) (input + i + (8*3))) ^ next4 ^ a2 ^ b1 ^ chorba8 ^ chorba7 ^ chorba6 ^ chorba3 ^ chorba4 ^ chorba1;

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

        i += 32;

        /* 20-23 */
        in1 = *((uint64_t*) (input + i)) ^ next1 ^ chorba8 ^ chorba7 ^ chorba4 ^ chorba5 ^ chorba2 ^ chorba1;
        in2 = *((uint64_t*) (input + i + (8*1))) ^ next2 ^ chorba8 ^ chorba5 ^ chorba6 ^ chorba3 ^ chorba2;

        a1 = (in1 << 17) ^ (in1 << 55);
        a2 = (in1 >> 47) ^ (in1 >> 9) ^ (in1 << 19);
        a3 = (in1 >> 45) ^ (in1 << 44);
        a4 = (in1 >> 20);
        
        b1 = (in2 << 17) ^ (in2 << 55);
        b2 = (in2 >> 47) ^ (in2 >> 9) ^ (in2 << 19);
        b3 = (in2 >> 45) ^ (in2 << 44);
        b4 = (in2 >> 20);

        in3 = *((uint64_t*) (input + i + (8*2))) ^ next3 ^ a1 ^ chorba7 ^ chorba6 ^ chorba4 ^ chorba3 ^ chorba1;
        in4 = *((uint64_t*) (input + i + (8*3))) ^ next4 ^ a2 ^ b1 ^ chorba8 ^ chorba7 ^ chorba5 ^ chorba4 ^ chorba2 ^ chorba1;

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

        i += 32;

        /* 24-27 */
        in1 = *((uint64_t*) (input + i)) ^ next1 ^ chorba8 ^ chorba6 ^ chorba5 ^ chorba3 ^ chorba2 ^ chorba1;
        in2 = *((uint64_t*) (input + i + (8*1))) ^ next2 ^ chorba7 ^ chorba6 ^ chorba4 ^ chorba3 ^ chorba2;

        a1 = (in1 << 17) ^ (in1 << 55);
        a2 = (in1 >> 47) ^ (in1 >> 9) ^ (in1 << 19);
        a3 = (in1 >> 45) ^ (in1 << 44);
        a4 = (in1 >> 20);
        
        b1 = (in2 << 17) ^ (in2 << 55);
        b2 = (in2 >> 47) ^ (in2 >> 9) ^ (in2 << 19);
        b3 = (in2 >> 45) ^ (in2 << 44);
        b4 = (in2 >> 20);

        in3 = *((uint64_t*) (input + i + (8*2))) ^ next3 ^ a1 ^ chorba8 ^ chorba7 ^ chorba5 ^ chorba4 ^ chorba3;
        in4 = *((uint64_t*) (input + i + (8*3))) ^ next4 ^ a2 ^ b1 ^ chorba8 ^ chorba6 ^ chorba5 ^ chorba4;

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

        i += 32;

        /* 28-31 */
        in1 = *((uint64_t*) (input + i)) ^ next1 ^ chorba7 ^ chorba6 ^ chorba5;
        in2 = *((uint64_t*) (input + i + (8*1))) ^ next2 ^ chorba8 ^ chorba7 ^ chorba6;

        a1 = (in1 << 17) ^ (in1 << 55);
        a2 = (in1 >> 47) ^ (in1 >> 9) ^ (in1 << 19);
        a3 = (in1 >> 45) ^ (in1 << 44);
        a4 = (in1 >> 20);
        
        b1 = (in2 << 17) ^ (in2 << 55);
        b2 = (in2 >> 47) ^ (in2 >> 9) ^ (in2 << 19);
        b3 = (in2 >> 45) ^ (in2 << 44);
        b4 = (in2 >> 20);

        in3 = *((uint64_t*) (input + i + (8*2))) ^ next3 ^ a1 ^ chorba8 ^ chorba7;
        in4 = *((uint64_t*) (input + i + (8*3))) ^ next4 ^ a2 ^ b1 ^ chorba8;

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

    for(; i + 32 + 40 < len; i += 32) {
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
    
    // up to 72 bytes left

    // RFC 1952
    for(int j = 0; j<len-i; j++) {
        crc = crc32_table[(crc ^ final[j]) & 0xff] ^ (crc >> 8);
    }

    return crc;
}
