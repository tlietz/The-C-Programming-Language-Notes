#include <stdio.h>

htoi(char s[]);

int main() {
  const char *data[] = {"0xF",  "0XF",        "0xFF", "0xf",  "0xA",
                        "asdf", "0x4324asdf", "0x12", "0x102"};
  int want[] = {15, 15, 255, 15, 10, -1, -1, 18, 258};

  // gets the size of the data array
  int size = sizeof(data) / sizeof(data[0]);

  int got;
  for (int i = 0; i < size; i++) {
    got = htoi(data[i]);
    if (got != want[i]) {
      printf("ERROR: got %d, want %d\n", got, want[i]);
    }
  }

  return 0;
}

// returns -1 if an invalid hexadecimal string is passed in
int htoi(char s[]) {
  int i;
  int dec = 0;
  for (i = 0; ('0' <= s[i] && s[i] <= '9') || ('a' <= s[i] && s[i] <= 'f') ||
              ('A' <= s[i] && s[i] <= 'F') || (s[i] == 'x' || s[i] == 'X');
       ++i) {

    if (i == 0) {
      if (s[i] != '0')
        return -1;
    } else if (i == 1) {
      if (s[i] != 'X' && s[i] != 'x')
        return -1;
    }
  }

  // there are invalid characters after a 0x or 0X string header
  if (s[i] != '\0') {
    return -1;
  }

  int multiplier = 1;
  for (int j = i - 1; j >= 2; j--) {
    if (s[j] >= 'a') {
      dec += (s[j] - 'a' + 10) * multiplier;
    } else if (s[j] >= 'A') {
      dec += (s[j] - 'A' + 10) * multiplier;
    } else if (s[j] >= '1') {
      dec += (s[j] - '0') * multiplier;
    }
    multiplier *= 16;
  }

  return dec;
}