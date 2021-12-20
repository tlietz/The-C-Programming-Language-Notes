// The following can be used to set z to the max of a and b
// z = (a > b) ? a : b;

#include <stdio.h>
void lower(char s[]);
int main() {
  char s[] = "HELLO, world!";
  lower(s);
  printf("%s\n", s);
  return 0;
}

void lower(char s[]) {
  for (int i = 0; s[i] != '\0'; i++) {
    s[i] = ('A' <= s[i] && s[i] <= 'Z') ? (s[i] + 'a' - 'A') : s[i];
  }
}