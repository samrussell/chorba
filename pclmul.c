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

#include "x86intrin.h"

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#pragma GCC push_options
#pragma GCC target("pclmul,avx")
uint32_t
pclmul (uint32_t crc, char* buf, size_t len)
  {
    const __m128i* data = (__m128i*) buf;
    __m128i* datarw;
    size_t bytes_remaining = len;
    __m128i in256[4] = {0};
    __m128i xor_crc;
    __m128i in1 = _mm_setzero_si128();
    __m128i in2 = _mm_setzero_si128();
    __m128i in3 = _mm_setzero_si128();
    __m128i in4 = _mm_setzero_si128();
    __m128i in5 = _mm_setzero_si128();
    __m128i in6 = _mm_setzero_si128();
    __m128i in7 = _mm_setzero_si128();
    __m128i in8 = _mm_setzero_si128();
    __m128i final_buf[12] = {0};
    __m128i fold_high;
    __m128i fold_low;

    /* These constants are calculated as T-1 mod P
       0x8F352D95 = (544 - 1) mod P etc
       This method is described in Fast CRC Computation for Generic Polynomials
       Using PCLMULQDQ Instruction (Gopal et al.) */
    __m128i shift544_shift480 = _mm_set_epi64x(0x1D9513D7, 0x8F352D95);
    __m128i shift160_shift96 = _mm_set_epi64x(0xCCAA009E, 0xAE689191);
    __m128i shift96_shift64 = _mm_set_epi64x(0xB8BC6765, 0xCCAA009E);
    /* Mu is defined as x^64 / P(x)
       P(x) is the generator polynomial for this CRC32 implementation */
    __m128i mu_poly = _mm_set_epi64x(0x1DB710641, 0x1F7011641);

    if (bytes_remaining >= 128)
      {
        /* Here we fold 4x 128bit words forward by 512 bits */
        /* First load up our initial state */
        in1 = _mm_loadu_si128(data);
        in2 = _mm_loadu_si128(data + 1);
        in3 = _mm_loadu_si128(data + 2);
        in4 = _mm_loadu_si128(data + 3);

        /* Initialise with incoming CRC */
        xor_crc = _mm_set_epi32 (0, 0, 0, crc);
        in1 = _mm_xor_si128 (in1, xor_crc);

        while (bytes_remaining >= 128)
          {
            /* Load up second set of 512 bits*/
            in5 = _mm_loadu_si128(data + 4);
            in6 = _mm_loadu_si128(data + 5);
            in7 = _mm_loadu_si128(data + 6);
            in8 = _mm_loadu_si128(data + 7);

            /* We shift the high QWORD forward 544 bits and the
               low QWORD 480 bits */
            fold_high = _mm_clmulepi64_si128(in1, shift544_shift480, 0x11);
            fold_low = _mm_clmulepi64_si128(in1, shift544_shift480, 0x00);
            in1 = _mm_xor_si128(in5, fold_high);
            in1 = _mm_xor_si128(in1, fold_low);
            fold_high = _mm_clmulepi64_si128(in2, shift544_shift480, 0x11);
            fold_low = _mm_clmulepi64_si128(in2, shift544_shift480, 0x00);
            in2 = _mm_xor_si128(in6, fold_high);
            in2 = _mm_xor_si128(in2, fold_low);
            fold_high = _mm_clmulepi64_si128(in3, shift544_shift480, 0x11);
            fold_low = _mm_clmulepi64_si128(in3, shift544_shift480, 0x00);
            in3 = _mm_xor_si128(in7, fold_high);
            in3 = _mm_xor_si128(in3, fold_low);
            fold_high = _mm_clmulepi64_si128(in4, shift544_shift480, 0x11);
            fold_low = _mm_clmulepi64_si128(in4, shift544_shift480, 0x00);
            in4 = _mm_xor_si128(in8, fold_high);
            in4 = _mm_xor_si128(in4, fold_low);

            bytes_remaining -= 64;
            data += 4;
          }

        _mm_storeu_si128(final_buf, in1);
        _mm_storeu_si128(final_buf + 1, in2);
        _mm_storeu_si128(final_buf + 2, in3);
        _mm_storeu_si128(final_buf + 3, in4);

        /* Move everything to final_buf because it is RW */
        memcpy (final_buf + 4, data + 4, bytes_remaining - 64);
        datarw = final_buf;
      }
    else
      {
        /* Move everything to final_buf because it is RW */
        /* XOR in previous CRC value */
        memcpy (final_buf, data, bytes_remaining);
        in1 = _mm_loadu_si128(final_buf);
        xor_crc = _mm_set_epi32 (0, 0, 0, crc);
        in1 = _mm_xor_si128 (in1, xor_crc);
        _mm_storeu_si128(final_buf, in1);
        datarw = final_buf;
      }

    while (bytes_remaining >= 32) {
        /* Do 128-bit folds as above */
        in1 = _mm_loadu_si128(datarw);
        in2 = _mm_loadu_si128(datarw + 1);

        /* We shift the high QWORD forward 160 bits and the
           low QWORD 96 bits */
        fold_high = _mm_clmulepi64_si128(in1, shift160_shift96, 0x11);
        fold_low = _mm_clmulepi64_si128(in1, shift160_shift96, 0x00);
        in2 = _mm_xor_si128(in2, fold_high);
        in2 = _mm_xor_si128(in2, fold_low);

        _mm_storeu_si128(datarw + 1, in2);
        bytes_remaining -= 16;
        datarw += 1;
    }

    /* We have 16-31 bytes here
       If we have 17-31 then we do another special case 128-bit fold
       the padding trick works because we're effectively padding 0s on the front
       which means with little endian we're shifting the number higher
       we'll also use this step to pick the <16 byte case */

    if (bytes_remaining != 16){
        /* Pad remainder and fold 128-bits
           We're reading in up to 32 bytes here = 256 bits
           This is inefficient so we only actually want to hit this on the actual end of data
           If we're reading a multiple of 32 bytes in the loop then this will never get hit */

        /* Read in at an offset so we get the shift for free */
        memcpy(((char*) in256) + (32 - bytes_remaining), datarw, bytes_remaining);
        in1 = _mm_loadu_si128(in256);
        in2 = _mm_loadu_si128(in256 + 1);

        /* Now we fold in1 onto in2 */
        shift160_shift96 = _mm_set_epi64x(0x0ccaa009e, 0x1751997d0);
        fold_high = _mm_clmulepi64_si128(in1, shift160_shift96, 0x11);
        fold_low = _mm_clmulepi64_si128(in1, shift160_shift96, 0x00);
        in2 = _mm_xor_si128(in2, fold_high);
        in1 = _mm_xor_si128(in2, fold_low);
    }
    else {
        in1 = _mm_loadu_si128(datarw);
    }

    /* We now have 16 bytes and fold as normal */

    in2 = _mm_and_si128(_mm_srli_si128(in1, 8), _mm_set_epi64x(0, 0xffffffff));
    in3 = _mm_and_si128(_mm_srli_si128(in1, 12), _mm_set_epi64x(0, 0xffffffff));
    in1 = _mm_and_si128(in1, _mm_set_epi64x(0, 0xffffffffffffffff));
    /* Multiply first 64 bits against shift96 */
    in1 = _mm_clmulepi64_si128(shift96_shift64, in1, 0x00);
    /* First 32 bits go on in2 */
    in2 = _mm_xor_si128(in2, _mm_and_si128(in1, _mm_set_epi64x(0, 0xffffffff)));
    /* Next 64 bits go on in3 */
    in3 = _mm_xor_si128(in3, _mm_srli_si128(in1, 4));
    /* Then shift 64 bits from here */
    in1 = _mm_clmulepi64_si128(shift96_shift64, in2, 0x01);
    in1 = _mm_xor_si128(in1, in3);

    /* This is the Barrett reduction */
    /* Take the bottom 32 bits */
    in2 = _mm_and_si128(in1, _mm_set_epi64x(0, 0xffffffff));
    /* Multiply by mu */
    in2 = _mm_clmulepi64_si128(mu_poly, in2, 0x00);
    /* Take the bottom 32 bits of the result */
    in2 = _mm_and_si128(in2, _mm_set_epi64x(0, 0xffffffff));
    /* Multiply by P(x) */
    in2 = _mm_clmulepi64_si128(mu_poly, in2, 0x01);
    /* XOR against input */
    in1 = _mm_xor_si128(in1, in2);
    /* Take bits 32-63 as the CRC*/
    in1 = _mm_srli_si128(in1, 4);
    crc = _mm_cvtsi128_si32(in1);

    return crc;
  }
#pragma GCC pop_options
