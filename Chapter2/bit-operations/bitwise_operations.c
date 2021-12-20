#include <stdio.h>
unsigned setbits(unsigned, int, int, unsigned);
unsigned invert(unsigned, int, int);
unsigned rightrot(unsigned, int);

int main() {
  unsigned x = 240; // 11110000
  unsigned y = 194; // 11000010

  unsigned set = setbits(x, 2, 2, y);
  printf("%u\n", set);

  unsigned z = 177; // 10110001
  unsigned inverted = invert(z, 5, 4);
  printf("%u\n", inverted);

  unsigned rot = rightrot(z, 5);
  printf("%u\n", rot);

  return 0;
}

// returns x with the n bits that begin at index p set to the rightmost n
// bits of y, leaving the other bits unchanged.
unsigned setbits(unsigned x, int p, int n, unsigned y) {
  // x = 11110000
  // y = 11000010
  // p = 2
  // n = 2
  // return should be 11110100 = 244

  unsigned zeroMask = ~(~0 << n); // 00...01... with n ones.
  zeroMask = zeroMask << (p + 1 - n);
  unsigned oneMask = ~zeroMask;

  unsigned andMask = (y << (p + 1 - n)) | oneMask;
  unsigned orMask = (y << (p + 1 - n)) & zeroMask;

  return ((x | orMask) & (andMask));
}

// Return x with the n bits that begin at index p inverted, leaving the
// others unchanged.
unsigned invert(unsigned x, int p, int n) {
  // x = 10110001
  // p = 5
  // n = 4
  // return should be 10001101 = 141

  return x ^ ((~(~0 << n)) << (p + 1 - n));
}

// returns the value x rotated to the right by n positions.
unsigned rightrot(unsigned x, int n) {
  // x = 10110001
  // n = 5

  unsigned orMask = 2147483648;

  for (int i = 0; i < n; i++) {
    unsigned xRightBit = x & (~(~0 << 1));
    x >>= 1;
    if (xRightBit == 1)
      x = x | orMask;
  }
  return x;
}