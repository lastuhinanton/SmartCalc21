#include "polish_notation.h"

#include <stdlib.h>

int insertValue(double x, struct queue *queue, struct queue *queue_x) {
  struct queue *queue_backup = init_queue();
  while (queue->first != 0) {
    double number;
    int code;
    dequeue(&number, &code, queue);
    enqueue(number, code, queue_backup);
    if (code == 2) {
      number = x;
      code = 0;
    }
    enqueue(number, code, queue_x);
  }
  queue->first = queue_backup->first;
  queue->last = queue_backup->last;
  free(queue_backup);
  return 0;
}

int infixToPostfix(struct queue *q_infix, struct queue *q_postfix) {
  struct stack *stack = 0;
  double number_queue;
  int code, number_stack;
  while (!isEmpty(q_infix)) {
    dequeue(&number_queue, &code, q_infix);
    if (code != 1) {
      enqueue(number_queue, code, q_postfix);
    } else {
      if (stack == 0) {
        stack = init_stack((int)number_queue);
      } else if (number_queue == 0) {
        push((int)number_queue, &stack);
      } else if (number_queue == 1) {
        do {
          pop(&number_stack, &stack);
          if (number_stack != 0) enqueue(number_stack, 1, q_postfix);
        } while (stack != 0 && number_stack != 0);
      } else {
        while (stack != 0 && (stack->number) / 10 >= number_queue / 10) {
          pop(&number_stack, &stack);
          enqueue(number_stack, 1, q_postfix);
        }
        push((int)number_queue, &stack);
      }
    }
  }
  while (stack != 0) {
    pop(&number_stack, &stack);
    enqueue(number_stack, 1, q_postfix);
  }
  return 0;
}
