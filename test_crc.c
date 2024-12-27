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

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "test_crc.h"

void xorshift_populate(char* buffer, size_t len) {
    size_t i;
    unsigned int state = 0x123;

    for (i = 0; i < len; i++) {
        state ^= state << 13;
        state ^= state >> 17;
        state ^= state << 5;
        buffer[i] = (char) state;
    }
}

__inline uint64_t GetTicksMicroseconds() {
    struct timespec ts;

    clock_gettime(CLOCK_MONOTONIC, &ts);

    return (ts.tv_nsec / 1000 + ts.tv_sec * 1000000);
}

int main (int argc, char* argv[]) {
    uint32_t crc = 0;
    uint64_t start_time = 0;
    uint64_t end_time = 0;

    if(argc != 4){
        printf("Usage: %s algorithm length iterations\n", argv[0]);
        return -1;
    }

    char* algorithm = argv[1];
    uint32_t (*calc_crc) (uint32_t crc, char* buf, size_t len);

    if(!strcmp(algorithm, "chorba_46952_destructive")) {
        calc_crc = chorba_46952_destructive;
    }
    else if(!strcmp(algorithm, "chorba_46952_nondestructive")) {
        calc_crc = chorba_46952_nondestructive;
    }
    else if(!strcmp(algorithm, "chorba_352_nondestructive")) {
        calc_crc = chorba_352_nondestructive;
    }
    else if(!strcmp(algorithm, "chorba_118960_destructive")) {
        calc_crc = chorba_118960_destructive;
    }
    else if(!strcmp(algorithm, "chorba_118960_nondestructive")) {
        calc_crc = chorba_118960_nondestructive;
    }
    else if(!strcmp(algorithm, "chorba_733112_destructive")) {
        calc_crc = chorba_733112_destructive;
    }
    else if(!strcmp(algorithm, "chorba_733112_nondestructive")) {
        calc_crc = chorba_733112_nondestructive;
    }
    else if(!strcmp(algorithm, "chorba_small_nondestructive")) {
        calc_crc = chorba_small_nondestructive;
    }
    else if(!strcmp(algorithm, "chorba_small_nondestructive_generator")) {
        calc_crc = chorba_small_nondestructive_generator;
    }
    else if(!strcmp(algorithm, "chorba_standard")) {
        calc_crc = chorba_standard;
    }
    else if(!strcmp(algorithm, "chorba_end")) {
        calc_crc = chorba_end;
    }
    else if(!strcmp(algorithm, "generator_1_bit")) {
        calc_crc = generator_1_bit;
    }
    else if(!strcmp(algorithm, "generator_64_bits")) {
        calc_crc = generator_64_bits;
    }
    else if(!strcmp(algorithm, "generator_64_bits_unrolled_4")) {
        calc_crc = generator_64_bits_unrolled_4;
    }
    else if(!strcmp(algorithm, "generator_64_bits_unrolled_8")) {
        calc_crc = generator_64_bits_unrolled_8;
    }
    else if(!strcmp(algorithm, "generator_64_bits_unrolled_16")) {
        calc_crc = generator_64_bits_unrolled_16;
    }
    else if(!strcmp(algorithm, "generator_64_bits_unrolled_32")) {
        calc_crc = generator_64_bits_unrolled_32;
    }
    else if(!strcmp(algorithm, "sarwate")) {
        calc_crc = sarwate;
    }
    else if(!strcmp(algorithm, "slicing")) {
        calc_crc = slicing;
    }
    else if(!strcmp(algorithm, "braiding")) {
        calc_crc = braiding;
    }
    #ifdef AVX1_PCLMUL
    else if(!strcmp(algorithm, "pclmul")) {
        calc_crc = pclmul;
    }
    else if(!strcmp(algorithm, "chorba_pclmul")) {
        calc_crc = chorba_pclmul;
    }
    #endif
    else {
        printf("Algorithm %s not recognised\n", algorithm);
        return -1;
    }

    size_t len = atoi(argv[2]);
    size_t iterations = atoi(argv[3]);
    char* data = calloc(len, 1);
    xorshift_populate(data, len);
    start_time = GetTicksMicroseconds();
    for(int i = 0; i < iterations; i++){
        crc = calc_crc(crc, data, len);
    }
    end_time = GetTicksMicroseconds();
    printf("time: %.8f\n", (end_time - start_time) / 1000000.0);
    free(data);
    printf("CRC: %08x\n", (unsigned int) crc);
    return 0;
}
