// Direction of truncation on divide, /, and the sign of the result for modulo,
// %, are machine-dependent, as is the action taken on overflow or underflow.

// && and || are short-circuited as soon as the truth or falsehood of the result
// is known.

// When an operator has operands of different types, they are converted to a
// common type according to a small number of rules.
// In general, the only automatic conversions are those that convert a
// "narrower" operand to a "wider" one without losing information.

// char is just a small integer, so chars can be freely used in arithmetic
// expressions.
/* atoi: convert s to integer */
int atoi(char s[]) {
  int i, n;
  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    n = 10 * n + (s[i] - '0');
  return n;
}

// another example of char to int conversion is the function lower.
// It maps a single char to lower case for the ASCII character set.
/* lower: convert c to lower case; ASCII only */
int lower(int c) {
  if (c >= 'A' && c <= 'Z')
    return c + 'a' - 'A';
  else
    return c;
}

// When a char is converted to an int, it may produce a negative integer,
// depending on the architecture. On some machines, a char whose leftmost bit is
// 1 will be converted to a negative integer. On others, a char is promoted to
// an int by adding zeros at the left end, thus it's always positive.

// Definition of C gaurantees that any character in the machine's standard
// printing character set will never be negative, so these characters will
// always be positive quantities in expressions.
// However, bit patterns stored in character variables may appear to be negative
// on some machines, yet positive on others.
// For portability, specify signed or unsigned if non-character data is to be
// stored in char variables.

// d = c >= '0' && c <= '9';
// The assignment above sets `d` to 1 if c is a digit, and 0 if not because it
// uses relational expressions. However, functions like isdigit may return any
// non-zero value for true. In the test part of if, while, for, etc., "true"
// just means non-zero, so it makes no difference.

// floats in an expression are not automatically converted to double.
// In general, math functions from <math.h> will use double precision.
// Main reason to use float is to save storage in large arrays, or, less often,
// to save time on machines where double-precision arithmetic is expensive.

// Watch out for conversion rules when unsigned operands are involved.
// For example, -1L < 1U, because 1U, an unsigned int, is promoted to a signed
// long.
// But, -1L > 1UL because -1L is promoted to an unsigned long and appears to be
// a large positive number.

// Conversions take place across assignments, the value of the right side is
// converted to the type of the left, which is the type of the result.

// A char is converted to an int, either by sign extension or not, as described
// above.

// Longer integers are converted to shorter ones or to chars by dropping the
// excess high-order bits. This means that the value of c is unchanged in the
// following:
// int i;
// char c;
// i = c;
// c = i;
//
// Reversing the order of assignments might cause info loss.

// Since an argument of a function call is an expression, type conversion also
// takes place when arguments are passed to functions.
// In the absence of a function prototype, char and short become int, and float
// becomes double. This is why we declared function arguments to be int and
// double, even when the function is called with char and float.

// Explicit type conversions can be forced with a cast.
// (type name) expression