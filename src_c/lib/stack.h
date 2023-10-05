#ifndef SRC_LIB_STACK_H_
#define SRC_LIB_STACK_H_

struct stack {
  int number;
  struct stack *ptr;
};

struct list {
  double number;
  int is_oper;
  struct list *ptr;
};

struct queue {
  struct list *first;
  struct list *last;
};

struct stack *init_stack(int n);
struct stack *push(int n, struct stack **stack);
struct stack *pop(int *n, struct stack **stack);

struct queue *init_queue();
int isEmpty(struct queue *queue);
struct queue *enqueue(double d, int n, struct queue *queue);
struct queue *dequeue(double *d, int *n, struct queue *queue);
void destroy_queue(struct queue *queue);

#endif  // SRC_LIB_STACK_H_
