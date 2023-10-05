#include "graph.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/calculate.h"
#include "lib/code.h"
#include "lib/input_formula.h"
#include "lib/polish_notation.h"
#include "lib/stack.h"

int getValueFromExpressionForGraphWithX(char *str, double *answer, double X) {
  int correct = 1;
  int count = 0;
  int size = strlen(str);
  char *s = (char *)calloc(size + 2, sizeof(char));
  correct = s ? 1 : 0;

  for (int i = 0; i < size && correct; i++) {
    if (str[i] != ' ') s[count++] = str[i];
  }
  s[count] = '\0';

  double *array_Y = answer;
  struct queue *q_infix = 0;
  struct queue *q_postfix = 0;
  if (correct) {
    q_infix = init_queue();
    correct = (q_infix != 0);
  }
  if (correct) {
    correct = queue_input(q_infix, s);
  }
  if (s) free(s);

  if (correct) {
    q_postfix = init_queue();
    correct = (q_postfix != 0);
  }
  if (correct) {
    infixToPostfix(q_infix, q_postfix);
    for (int i = 0; i < WIDTH && correct; i++) {
      struct queue *queue_x = init_queue();
      insertValue(X, q_postfix, queue_x);
      double result = 0;
      int check = fromRPNtoValues(queue_x, &result);
      if (check == 1 || check == 4) {
        correct = 0;
      } else if (check == 2 || check == 3) {
        array_Y[i] = 100;
      } else {
        array_Y[i] = result;
      }
      destroy_queue(queue_x);
    }
  }
  destroy_queue(q_infix);
  destroy_queue(q_postfix);

  return correct;
}

int getValueFromExpressionForGraphWithoutX(char *str, double *answer) {
  int correct = 1;
  int count = 0;
  int size = strlen(str);
  char *s = (char *)calloc(size + 2, sizeof(char));
  correct = s ? 1 : 0;

  for (int i = 0; i < size && correct; i++) {
    if (str[i] != ' ') s[count++] = str[i];
  }
  s[count] = '\0';

  double *array_Y = answer;
  struct queue *q_infix = 0;
  struct queue *q_postfix = 0;
  if (correct) {
    q_infix = init_queue();
    correct = (q_infix != 0);
  }
  if (correct) {
    correct = queue_input(q_infix, s);
  }
  if (s) free(s);

  if (correct) {
    q_postfix = init_queue();
    correct = (q_postfix != 0);
  }
  if (correct) {
    infixToPostfix(q_infix, q_postfix);
    for (int i = 0; i < WIDTH && correct; i++) {
      double x = 4 * M_PI / 79 * i;
      struct queue *queue_x = init_queue();
      insertValue(x, q_postfix, queue_x);
      double result = 0;
      int check = fromRPNtoValues(queue_x, &result);
      if (check == 1 || check == 4) {
        correct = 0;
      } else if (check == 2 || check == 3) {
        array_Y[i] = 100;
      } else {
        array_Y[i] = result;
      }
      destroy_queue(queue_x);
    }
  }
  destroy_queue(q_infix);
  destroy_queue(q_postfix);
  return correct;
}

int getValueFromExpressionWithX(char *str, double *answer, double X) {
  int correct = 1;
  int count = 0;
  int size = strlen(str);
  char *s = (char *)calloc(size + 2, sizeof(char));
  correct = s ? 1 : 0;

  for (int i = 0; i < size && correct; i++) {
    if (str[i] != ' ') s[count++] = str[i];
  }
  s[count] = '\0';

  struct queue *q_infix = 0;
  struct queue *q_postfix = 0;
  if (correct) {
    q_infix = init_queue();
    correct = (q_infix != 0);
  }
  if (correct) {
    correct = queue_input(q_infix, s);
  }
  if (s) free(s);

  if (correct) {
    q_postfix = init_queue();
    correct = (q_postfix != 0);
  }
  if (correct) {
    infixToPostfix(q_infix, q_postfix);
    struct queue *queue_x = init_queue();
    insertValue(X, q_postfix, queue_x);
    double result = 0;
    int check = fromRPNtoValues(queue_x, &result);
    if (check == 1 || check == 4) {
      correct = 0;
    } else {
      *answer = result;
    }
  }
  destroy_queue(q_infix);
  destroy_queue(q_postfix);
  return correct;
}

int getValueFromExpression(char *str, double *answer) {
  int correct = 1;
  int count = 0;
  int size = strlen(str);
  char *s = (char *)calloc(size + 2, sizeof(char));
  correct = s ? 1 : 0;

  for (int i = 0; i < size && correct; i++) {
    if (str[i] != ' ') s[count++] = str[i];
  }

  struct queue *q_infix = 0;
  struct queue *q_postfix = 0;
  if (correct) {
    q_infix = init_queue();
    correct = (q_infix != 0);
  }
  if (correct) {
    correct = queue_input(q_infix, s);
  }
  if (s) free(s);

  if (correct) {
    q_postfix = init_queue();
    correct = (q_postfix != 0);
  }
  if (correct) {
    infixToPostfix(q_infix, q_postfix);
    double x = 4 * M_PI / 79 * 1;
    struct queue *queue_x = init_queue();
    insertValue(x, q_postfix, queue_x);
    double result = 0;
    int check = fromRPNtoValues(queue_x, &result);
    if (check == 1 || check == 4) {
      correct = 0;
    } else {
      *answer = result;
    }
  }
  destroy_queue(q_infix);
  destroy_queue(q_postfix);
  return correct;
}