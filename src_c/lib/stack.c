#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

struct stack *init_stack(int n) {
  struct stack *stack;
  stack = (struct stack *)malloc(sizeof(struct stack));
  if (stack != 0) {
    stack->number = n;
    stack->ptr = 0;
  }
  return stack;
}

struct stack *push(int n, struct stack **stack) {
  struct stack *push_number = (struct stack *)malloc(sizeof(struct stack));
  if (stack != 0) {
    push_number->number = n;
    push_number->ptr = *stack;
    *stack = push_number;
  }
  return push_number;
}

struct stack *pop(int *n, struct stack **stack) {
  if (*stack != 0) {
    struct stack *pop_number = *stack;
    *n = pop_number->number;
    *stack = pop_number->ptr;
    free(pop_number);
  }
  return *stack;
}

struct queue *init_queue() {
  struct queue *queue = (struct queue *)malloc(sizeof(struct queue));
  if (queue != 0) {
    queue->first = 0;
    queue->last = 0;
  }
  return queue;
}

struct queue *enqueue(double d, int n, struct queue *queue) {
  struct list *list = (struct list *)malloc(sizeof(struct list));
  if (list != 0) {
    list->ptr = 0;
    list->number = d;
    list->is_oper = n;
    if (queue->last != 0) {
      queue->last->ptr = list;
      queue->last = list;
    } else {
      queue->first = list;
      queue->last = list;
    }
  }
  return queue;
}

struct queue *dequeue(double *d, int *n, struct queue *queue) {
  if (!isEmpty(queue)) {
    *d = queue->first->number;
    *n = queue->first->is_oper;
  }
  struct list *list = queue->first->ptr;
  free(queue->first);
  queue->first = list;
  if (queue->first == 0) queue->last = 0;
  return queue;
}

int isEmpty(struct queue *queue) { return queue == 0 || queue->first == 0; }

void destroy_queue(struct queue *queue) {
  if (queue != 0) {
    while (queue->first != 0) {
      struct list *destroyed = queue->first;
      queue->first = queue->first->ptr;
      free(destroyed);
    }
    free(queue);
  }
}
