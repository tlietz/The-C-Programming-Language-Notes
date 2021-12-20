#include <stdio.h>
int bitcount(unsigned);
int main() {
  int bits = bitcount(10); // 1010
  printf("%u\n", bits);
  return 0;
}

// in a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
// in x. For example, take the decimal number 10, in binary it is 1010. If we do
// x &= (x-1), it will be equivalent to 1010 & 1001, which gives us 1000. More
// generally, subtracting 1 garauntees that the right-most 1-bit is moved to the
// right by 1. Therefore, the & takes it away.
int bitcount(unsigned x) {
  int b = 0;

  while (x != 0) {
    x &= (x - 1);
    b++;
  }
  return b;
}
