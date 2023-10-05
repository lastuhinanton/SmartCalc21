#include "calculate.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define MAX 1000

int fromRPNtoValues(struct queue *q_postfix, double *result) {
  double number = 0, stack[MAX];
  int is_oper = 0, count = 0, flag = 0;
  while (!isEmpty(q_postfix)) {
    dequeue(&number, &is_oper, q_postfix);
    if (is_oper == 0) {
      stack[count++] = number;
    } else if (is_oper == 1) {
      if (number == 10.0) {
        if (count >= 2) {
          count -= 1;
          stack[count - 1] += stack[count];
        } else {
          flag = 1;
        }
      } else if (number == 11.0) {
        if (count >= 2) {
          count -= 1;
          stack[count - 1] = stack[count] - stack[count - 1];
        } else {
          flag = 1;
        }
      } else if (number == 20.0) {
        if (count >= 2) {
          count -= 1;
          stack[count - 1] *= stack[count];
        } else {
          flag = 1;
        }
      } else if (number == 21.0) {
        if (count >= 2) {
          if (stack[count] != 0) {
            count -= 1;
            stack[count - 1] = stack[count] / stack[count - 1];
          } else {
            flag = 2;
          }
        } else {
          flag = 1;
        }
      } else if (number == 50.0) {
        if (count >= 1) {
          stack[count - 1] = sin(stack[count - 1]);
        } else {
          flag = 1;
        }
      } else if (number == 51.0) {
        if (count >= 1) {
          stack[count - 1] = cos(stack[count - 1]);
        } else {
          flag = 1;
        }
      } else if (number == 52.0) {
        if (count >= 1) {
          stack[count - 1] = tan(stack[count - 1]);
        } else {
          flag = 1;
        }
      } else if (number == 53.0) {
        if (count >= 1) {
          stack[count - 1] = 1 / (tan(stack[count - 1]));
        } else {
          flag = 1;
        }
      } else if (number == 54.0) {
        if (count >= 1) {
          stack[count - 1] = acos(stack[count - 1]);
        } else {
          flag = 1;
        }
      } else if (number == 55.0) {
        if (count >= 1) {
          stack[count - 1] = asin(stack[count - 1]);
        } else {
          flag = 1;
        }
      } else if (number == 56.0) {
        if (count >= 1) {
          stack[count - 1] = atan(stack[count - 1]);
        } else {
          flag = 1;
        }
      } else if (number == 57.0) {
        if (count >= 2) {
          if (stack[count] != 0) {
            count -= 1;
            stack[count - 1] = fmod(stack[count], stack[count - 1]);
          } else {
            flag = 2;
          }
        } else {
          flag = 1;
        }
      } else if (number == 58.0) {
        if (count >= 1) {
          stack[count - 1] = log10(stack[count - 1]);
        } else {
          flag = 1;
        }
      } else if (number == 59.0) {
        if (count >= 1) {
          stack[count - 1] = log(stack[count - 1]);
        } else {
          flag = 1;
        }
      } else if (number == 60.0) {
        if (count >= 1) {
          if (stack[count - 1] < 0.0) {
            flag = 3;
          } else {
            stack[count - 1] = sqrt(stack[count - 1]);
          }
        } else {
          flag = 1;
        }
      } else if (number == 61.0) {
        if (count >= 1) {
          stack[count - 1] = -1 * (stack[count - 1]);
        } else {
          flag = 1;
        }
      } else if (number == 62.0) {
        if (count >= 2) {
          count -= 1;
          stack[count - 1] = pow(stack[count - 1], stack[count]);
        } else {
          flag = 1;
        }
      }
    }
  }
  if (flag != 0) {
  } else if (count > 1) {
    flag = 4;
  } else {
    *result = stack[0];
  }
  return flag;
}
