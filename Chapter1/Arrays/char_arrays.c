// When the name of an array is used as an argument, the value passed to the
// function is the location or address of the beginning of the array - there is
// no copying of array elements.
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */
// Declaration refers to places where the nature of the external variable is
// stated but no storage is allocated.
// Definition refers to the place where the
// variable is created or assigned storage.
int max;               /* maximum length seen so far */
char line[MAXLINE];    /* current input line */
char longest[MAXLINE]; /* longest line saved here */
int getline(void);
void copy(void);
/* print longest input line; specialized version */
main() {
  int len;
  // `extern` is redundant here because the external variables are declared at
  // the top of this file.
  // Usually, extern declarations of variables and functions are in a header
  // file, with suffix .h
  //   extern int max;
  //   extern char longest[];
  max = 0;
  while ((len = getline()) > 0)
    if (len > max) {
      max = len;
      copy();
    }
  if (max > 0) /* there was a line */
    printf("%s", longest);
  return 0;
}
/* getline: specialized version */
int getline(void) {
  int c, i;
  extern char line[];
  for (i = 0; i < MAXLINE - 1 && (c = getchar) != EOF && c != '\n'; ++i)
    line[i] = c;
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  // the null character \0, whose value is 0, is put at the end of the array to
  // mark the end of the string of characters.
  // This can be seen in how the string constant "hello\n" would be stored as an
  // array of characters: [h,e,l,l,o,\n,\0]
  line[i] = '\0';
  return i;
}
/* copy: specialized version */
void copy(void) {
  int i;
  extern char line[], longest[];
  i = 0;
  while ((longest[i] = line[i]) != '\0')
    ++i;
}
