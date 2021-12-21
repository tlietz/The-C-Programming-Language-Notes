#include <stdio.h>

void escape(char[], char[]);
void reverse_escape(char[], char[]);
int main() {
  char s[] = "hello\tworld\n!";
  // size includes the null character that terminates the string;
  int size = sizeof(s) / sizeof(s[0]);
  char t[size * 2];
  escape(s, t);

  printf("escape: %s\n", t);

  char a[] = "hello\\tworld\\n!";
  char u[sizeof(t) / sizeof(t[0])];
  reverse_escape(t, u);
  printf("reverse: %s\n", u);
  return 0;
}

void escape(char s[], char t[]) {
  int i, j = 0;
  for (i; s[i] != '\0'; i++) {
    int c = s[i];
    switch (c) {
    case '\t':
      t[j++] = '\\';
      t[j] = 't';
      break;
    case '\n':
      t[j++] = '\\';
      t[j] = 'n';
      break;
    default:
      t[j] = c;
      break;
    }
    j++;
  }
  t[j] = '\0';
}

void reverse_escape(char s[], char t[]) {
  int i, j = 0;
  for (i; s[i] != '\0'; i++) {
    switch (s[i]) {
    case '\\':
      i++;
      switch (s[i]) {
      case 't':
        t[j] = '\t';
        break;
      case 'n':
        t[j] = '\n';
        break;
      default:
        t[j] = s[i];
        i--;
        break;
      }
      break;
    default:
      t[j] = s[i];
      break;
    }
    j++;
  }
  t[j] = '\0';
}