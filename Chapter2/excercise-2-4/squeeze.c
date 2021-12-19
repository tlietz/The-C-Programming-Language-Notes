#include <stdio.h>

typedef enum { false, true } bool;

void squeeze(char[], char[]);

int main() {
  char s1[] = "abcdefghia";
  squeeze(s1, "ai");
  printf("%s\n", s1);
  return 0;
}

bool contains(char s[], int c) {
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == c)
      return true;
  }
  return false;
}

void squeeze(char s1[], char s2[]) {
  int i, j;
  for (i = j = 0; s1[i] != '\0'; i++) {
    if (!contains(s2, s1[i])) {
      s1[j++] = s1[i];
    }
  }
  s1[j] = '\0';
}
