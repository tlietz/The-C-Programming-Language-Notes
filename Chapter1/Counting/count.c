#include <stdio.h>
#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */
/* count lines, words, and characters in input */
main() {
  int c, nl, nw, nc, state;
  state = OUT;
  // This is no a special case, it is a consequence of the fact that an
  // assignment is an expression with the value and assignments associated from
  // right to left.
  // It is as if we had written:
  // nl = (nw = (nc = 0));
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("%d %d %d\n", nl, nw, nc);
}