#include "stack.h"

#ifndef SRC_LIB_POLISH_NOTATION_H_
#define SRC_LIB_POLISH_NOTATION_H_

int infixToPostfix(struct queue *q_infix, struct queue *q_postfix);
int insertValue(double x, struct queue *queue, struct queue *queue_x);

#endif  // SRC_LIB_POLISH_NOTATION_H_
