# Chorba
Chorba: A novel table-less CRC32 implementation

## Building the tests
Pull both zlib_slicing and zlib_braiding submodules and build them as per their
README files (`./configure && make`) and then build this repo
`./configure && make`

## How it works

Paper is at https://arxiv.org/abs/2412.16398

## Usage

For non-accelerated platforms (AVX, NEON etc), chorba_standard should be the most reliable, for small messages (&lt;256 bytes) the standard braiding algorithm is faster, from 256-238432 bytes the chorba_small algorithm is used, and for &gt;238432 bytes the chorba_118960_nondestructive algorithm will be used.

For accelerated platforms, chorba_pclmul is an example of how to improve the speed of carry-less multiplication, it ranges from 5-20% depending on the message length.

### Performance

![AMD Ryzen 5 5600](/figures/amdryzen.png)

![AWS Neoverse-N1 T4g.micro](/figures/t4g.png)

![Raspberry Pi 4](/figures/rpi4.png)

## Dedication

This implementation is named after the Serbian singer Bora Đorđević (also known
as Bora Čorba) who was born in 1952 and died in 2024. His birth year matches
the number of the GZIP standard RFC 1952 that describes a common CRC32
implementation, and the original proof of concept for this method used the
polynomial $x^{21} + x^{15} + x^{14} + x^{11} + x^{10} + x^7 + x^3$ which is
$x^{1952 \times 8}\ mod\ G(x)$.

## Copyright notice

 (C) 2024 Sam Russell

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

