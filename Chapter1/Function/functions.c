// In C, all function arguments are passed by value. This means that the called
// function is given the values of its arguments in temp variables rather than
// the originals.

#include <stdio.h>
// int power(int m, int n) is the `function prototype` and it has to agree with
// the definition and uses of power().
// The parameter names are optional, so it could be written as:
// int power(int, int);
int power(int m, int n);
/* test power function */
main() {
  int i;
  for (i = 0; i < 10; ++i)
    printf("%d %d %d\n", i, power(2, i), power(-3, i));

  // this returns a status to the environment.
  // 0 means normal termination
  // non-zero values signal erroneous termination conditions
  return 0;
}
/* power: raise base to n-th power; n >= 0 */
int power(int base, int n) {
  int p;
  p = 1;
  for (int i = 1; i <= n; ++i)
    p = p * base;
  return p;
}