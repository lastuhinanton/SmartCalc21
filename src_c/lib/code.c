#include "code.h"

#include <stdio.h>
#include <string.h>

int encode(char *s) {
  const int operator_int[] = {OPERATORS_INT};
  char *operator_str[] = {OPERATORS_STR};
  int i = 0;
  int code = -1;
  while (i < OPERATORS_COUNT && code == -1) {
    if (!strcmp(s, operator_str[i])) {
      code = operator_int[i];
    }
    i++;
  }
  return code;
}
