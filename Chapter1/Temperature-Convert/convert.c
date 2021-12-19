#include <stdio.h>
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300 */

// these are symbolic constants, not variables.
#define LOWER 0
#define UPPER 300
#define STEP 20

main() {
  printf("%3c %6c\n", 'F', 'C');
  float fahr, celcius;

  fahr = LOWER;
  while (fahr <= UPPER) {
    celcius = (5.0 / 9.0) * (fahr - 32.0);
    // %3.0f means that fahr is to be printed at least three characters wide,
    // with no decimal point and no fraction digits. %6.1f means that celcius is
    // to be printed at least 6 characters wide, with 1 digit after the decimal
    // point.
    printf("%3.0f %6.1f\n", fahr, celcius);
    fahr = fahr + STEP;
  }
}