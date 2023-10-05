#ifndef SRC_LIB_INPUT_FORMULA_H_
#define SRC_LIB_INPUT_FORMULA_H_

#include <stdio.h>
#include <stdlib.h>

#include "code.h"
#include "stack.h"

int input(char **string);
int queue_input(struct queue *queue, char *s);
int isNumber(char sym);
int isOperatorOrParanth(char operator);

#endif  // SRC_LIB_INPUT_FORMULA_H_
