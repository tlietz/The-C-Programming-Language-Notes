// Text input or output, no matter where it orginates or goes to, is dealt with
// as streams of characters.
// A `text stream` is a sequence of characters divided into lines; each line has
// zero or more characters followed by a newline character.
// It is the responsibility of the library to make each input or output stream
// confirm this model.

#include <stdio.h>
/* copy input to output */
main() {
  // must use `int` here instead of char because char is not big enough to hold
  // EOF symbolic constant, which is an integer defined in <stdio.h>
  int c;

  // any assignment is an expression and has a value; which is the value of the
  // left hand side after the assignment.
  // This means that an assignment can be used as part of a larger expression.
  //   while ((c = getchar()) != EOF) {
  //     putchar(c);
  //   }

  // while and for loops test at the top of the loop, before proceeding with the
  // body.
  printf("%d\n", EOF);

  // a character written between single quotes represents an integer value equal
  // to the numerical value of the character in the machine's character set.
  // Called a `character constant`.
  // For example, 'A' is the ASCII value of 65.
  // Also, '\n' is the newline character, which is 10 in ASCII.
  // '\n' is a single character, and in expressions is just an integer.
  // '\n' is a string constant that contains only one character.
}