// Integer constant: 1234
// long constant: 123456789L or 123456789l (integers that are too big will also
// be made into long)
// unsigned constants: u or U, ul or UL
// floating-point constants: 123.4 or 1e-2
// floating-point type is double, unless suffixed.
// f or F indicate a float constant; l or L indicate a long double

// Leading 0 on an integer means octal, a leading 0x or 0X means hexadecimal.
// Octal and hexadecimal can also be followed by L to make them long or U for
// unsigned:
// 0XFUL is an unsigned long with the value of 15 decimal.

// an arbitrary byte-sized bit pattern can be specified by:
// '\ooo'
// where ooo is one to three octal digits or by:
// '\xhh'
// where hh is one or more hexadecimal digits
//
// So we might write:
#define BELL '\007' /* ASCII bell character */
#define BELL '\x7'

// a `constant expression` is an expression that involves only constants.
// They can be evaluated at compile-time and can be used in any place that a
// constant can occur, as in:
#define MAXLINE 1000
char line[MAXLINE + 1];

// A `string constant` or `string literal` is a sequence of zero or more
// characters surrounded by double quotes. The quotes delimit the string. They
// can be concatenated at compile-time, so:
// "hello, " "world" is equivalent to:
// "hello, world"
//
// a string constant is an array of characters.
// The internal representation is a string has a null character '\0' at the end,
// so the physical storage required is one more than the number of characters
// written between the quotes.
//
// This means that there is no limit to how long a string can be, but programs
// must scan a string completely to determine its length.
// standard lib function strlen(s) returns length of argument `s`, excluding the
// '\0'.

// There is a difference between 'x' and "x".
// 'x' is an integer that is used to produce the numeric value of the letter x//
// in the machine's character set.
// "x is an array of characters that contains one character and a '\0'.

// Another kind of constant is the enum
// it is a list of constant integer values, as in
enum boolean { NO, YES };
// The first name in an enum has value 0, the next 1, etc. Unless explicit
// values are specified. Unspecified values continue the progression from the
// last specified value:
enum escapes {
  BACKSPACE = '\b',
  TAB = '\t',
  NEWLINE = '\n',
  VTAB = '\v',
  RETURN = '\r'
};
enum months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
/* FEB = 2, MAR = 3, etc. */

// Names in different enumerations must be distinct. Values do not need to be
// distinct in the same enumeration.
// Although enum types may be declared, compilers need not check the validity of
// the value stored. enums are often better than #defines because they offer the
// chance of checking. Additionally, a debugger may be able to print values of
// enumeration variables in their symbolic form.

// A declaration specifies a type, and contains a list of one or more variables
// of that type, as in:
int lower, upper, step;
char c, line[1000];

// variables can also be initialized in its declaration.
char esc = '\\';

// If the variable in question is not automatic (a local variable), the
// initialization is done once only, conceptually before the program starts
// executing, and the initializer must be a constant expression.
//
// An initialized automatic variable is initialized each time the function or
// block it is in is entered; the initializer may be any expression.
// External and static variables are initialized to zero by default.
// Automatic variables with no explicit initializer have undefined (garbage)
// values.

// const qualifier can be applied to the declaration of any variable to specify
// that its value will not be changed.
// For an array, const means the elements will not be altered.
const double e = 2.71828182845905;
const char msg[] = "warning: ";

// const declaration can also be used with array arguments to indicate that the
// function does not change that array:
int strlen(const char[]);