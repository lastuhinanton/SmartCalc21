#include "model.h"

namespace s21 {
  
    
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

    queue *init_queue() {
      queue* q_temp = new queue;
      q_temp->first = 0;
      q_temp->last = 0;
      return q_temp;
    }
    
    queue *enqueue(double d, int n, queue *t_queue) {
      list *t_list = new list;
      t_list->ptr = 0;
      t_list->number = d;
      t_list->is_oper = n;
      if (t_queue->last != 0) {
        t_queue->last->ptr = t_list;
        t_queue->last = t_list;
      } else {
        t_queue->first = t_list;
        t_queue->last = t_list;
      }
      return t_queue;
    }

    int isEmpty(queue *t_queue) { return t_queue == 0 || t_queue->first == 0; }

    queue *dequeue(double *d, int *n, queue *t_queue) {
      if (!isEmpty(t_queue)) {
        *d = t_queue->first->number;
        *n = t_queue->first->is_oper;
      }
      list *list = t_queue->first->ptr;
      delete t_queue->first;
      t_queue->first = list;
      if (t_queue->first == 0) t_queue->last = 0;
      return t_queue;
    }

    void destroy_queue(queue *t_queue) {
      if (t_queue != 0) {
        while (t_queue->first != 0) {
          list *destroyed = t_queue->first;
          t_queue->first = t_queue->first->ptr;
          delete destroyed;
        }
        delete t_queue;
      }
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

    // int encode(std::string &s) {
    //   int i = 0;
    //   int code = -1;
    //   while (i < operators_count && code == -1) {
    //     if (s != operators_str[i]) {
    //       code = operators_int[i];
    //     }
    //     std::cout << s << " " << code << std::endl;
    //     i++;
    //   }
    //   return code;
    // }

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

    double Model::getTheResult() {
      return data_;
    }

    void Model::getValueFromExpressionForGraph(const std::string &str) {
      char *s = new char[str.size() + 2];

      for (int i = 0, k = 0; i < str.size(); ++i) {
        if (str[i] != ' ') {
          s[k++] = str[i];
        }
      }

      struct queue *q_infix = 0;
      struct queue *q_postfix = 0;
      q_infix = init_queue();
      queue_input(q_infix, s);
      q_postfix = init_queue();
      infixToPostfix(q_infix, q_postfix);
      double x = 4 * M_PI / 79 * 1;
      struct queue *queue_x = init_queue();
      insertValue(x, q_postfix, queue_x);
      double result = 0;
      int check = fromRPNtoValues(queue_x, &result);
      data_ = result;
    }

    bool Model::isOperator(const std::string& s) {
      return (s == "+" || s == "-" || s == "*" || s == "/" || s == "^" || s == "mod");
    }

    bool Model::isFunction(const std::string& s) {
      return (s == "cos" || s == "sin" || s == "tan" || s == "acos" || s == "asin" ||
              s == "atan" || s == "sqrt" || s == "ln" || s == "log");
    }

};
