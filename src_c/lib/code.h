#ifndef SRC_LIB_CODE_H_
#define SRC_LIB_CODE_H_

#define OPERATORS_STR                                                       \
  "(", ")", "+", "-", "*", "/", "sin", "cos", "tan", "ctg", "acos", "asin", \
      "atan", "mod", "log", "ln", "sqrt", "~", "^"
#define OPERATORS_INT \
  0, 1, 10, 11, 20, 21, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62
#define OPERATORS_COUNT 19

int encode(char *s);

#endif  // SRC_LIB_CODE_H_
