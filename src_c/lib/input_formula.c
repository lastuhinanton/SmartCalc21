#include "input_formula.h"

#include <math.h>

int queue_input(struct queue *queue, char *s) {
  char oper[5];
  char *ptr = s;
  int correct = 1;
  while (*ptr != '\0' && correct) {
    if (isNumber(*ptr)) {
      char *endptr = ptr;
      double d = strtod(ptr, &endptr);
      correct = isnormal(d);
      enqueue(d, 0, queue);
      ptr = endptr;
    } else if (isOperatorOrParanth(*ptr)) {
      if ((*ptr == '-') && (isEmpty(queue) || ((queue->last->is_oper == 1) &&
                                               (queue->last->number == 0.)))) {
        *ptr = '~';
      }
      oper[0] = *ptr++;
      oper[1] = '\0';
      enqueue(encode(oper), 1, queue);
      if (encode(oper) == -1) correct = 0;
    } else if (*ptr == 'l' && *(ptr + 1) == 'n') {
      oper[0] = *ptr++;
      oper[1] = *ptr++;
      oper[2] = '\0';
      enqueue(encode(oper), 1, queue);
      if (encode(oper) == -1) correct = 0;
    } else if (*ptr == 'l' && *(ptr + 1) == 'o') {
      oper[0] = *ptr++;
      oper[1] = *ptr++;
      oper[2] = *ptr++;
      oper[3] = '\0';
      enqueue(encode(oper), 1, queue);
      if (encode(oper) == -1) correct = 0;
    } else if (*ptr == 'm' && *(ptr + 1) == 'o') {
      oper[0] = *ptr++;
      oper[1] = *ptr++;
      oper[2] = *ptr++;
      oper[3] = '\0';
      enqueue(encode(oper), 1, queue);
      if (encode(oper) == -1) correct = 0;
    } else if (*ptr == 'x') {
      enqueue(0, 2, queue);
      ptr++;
    } else if (*ptr == 's' && *(ptr + 1) == 'q') {
      oper[0] = *ptr++;
      oper[1] = *ptr++;
      oper[2] = *ptr++;
      oper[3] = *ptr++;
      oper[4] = '\0';
      enqueue(encode(oper), 1, queue);
      if (encode(oper) == -1) correct = 0;
    } else if (*ptr == 'a' && *(ptr + 1) == 'c') {
      oper[0] = *ptr++;
      oper[1] = *ptr++;
      oper[2] = *ptr++;
      oper[3] = *ptr++;
      oper[4] = '\0';
      enqueue(encode(oper), 1, queue);
      if (encode(oper) == -1) correct = 0;
    } else if (*ptr == 'a' && *(ptr + 1) == 's') {
      oper[0] = *ptr++;
      oper[1] = *ptr++;
      oper[2] = *ptr++;
      oper[3] = *ptr++;
      oper[4] = '\0';
      enqueue(encode(oper), 1, queue);
      if (encode(oper) == -1) correct = 0;
    } else if (*ptr == 'a' && *(ptr + 1) == 't') {
      oper[0] = *ptr++;
      oper[1] = *ptr++;
      oper[2] = *ptr++;
      oper[3] = *ptr++;
      oper[4] = '\0';
      enqueue(encode(oper), 1, queue);
      if (encode(oper) == -1) correct = 0;
    } else {
      oper[0] = *ptr++;
      oper[1] = *ptr++;
      oper[2] = *ptr++;
      oper[3] = '\0';
      enqueue(encode(oper), 1, queue);
      if (encode(oper) == -1) correct = 0;
    }
  }
  return correct;
}

int isNumber(char c) {
  int res = ((c >= 0x30 && c <= 0x39) || c == 0x2c || c == 0x2e) ? 1 : 0;
  return res;
}

int isOperatorOrParanth(char c) {
  int res = (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' ||
             c == ')' || c == '^' || c == '~')
                ? 1
                : 0;
  return res;
}