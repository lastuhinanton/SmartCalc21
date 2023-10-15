#include "model.h"

namespace s21 {
  
    
    stack *init_stack(int n) {
      stack *stack_r;
      stack_r = new stack;
      stack_r->number = n;
      stack_r->ptr = 0;
      return stack_r;
    }

    stack *push(int n, stack **stack_g) {
      stack *push_number = new stack;
      push_number->number = n;
      push_number->ptr = *stack_g;
      *stack_g = push_number;
      return push_number;
    }

    stack *pop(int *n, stack **stack_g) {
      stack *pop_number = *stack_g;
      *n = pop_number->number;
      *stack_g = pop_number->ptr;
      delete pop_number;
      return *stack_g;
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


    int fromRPNtoValues(queue *q_postfix, double *result) {
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

    int insertValue(double x, queue *queue_g, queue *queue_x) {
      queue *queue_backup = init_queue();
      while (queue_g->first != 0) {
        double number;
        int code;
        dequeue(&number, &code, queue_g);
        enqueue(number, code, queue_backup);
        if (code == 2) {
          number = x;
          code = 0;
        }
        enqueue(number, code, queue_x);
      }
      queue_g->first = queue_backup->first;
      queue_g->last = queue_backup->last;
      delete queue_backup;
      return 0;
    }

    int infixToPostfix(queue *q_infix, queue *q_postfix) {
      stack *stack = 0;
      double number_queue;
      int code, number_stack;
      while (!isEmpty(q_infix)) {
        dequeue(&number_queue, &code, q_infix);
        if (code != 1) {
          enqueue(number_queue, code, q_postfix);
        } else {
          if (stack == 0) {
            stack = init_stack(number_queue);
          } else if (number_queue == 0) {
            push(number_queue, &stack);
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
            push(number_queue, &stack);
          }
        }
      }
      while (stack != 0) {
        pop(&number_stack, &stack);
        enqueue(number_stack, 1, q_postfix);
      }
      return 0;
    }

    int encode(char *s) {
      const int operator_int[] = {OPERATORS_INT};
      const char *operator_str[] = {OPERATORS_STR};
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

    double customStrToDouble(const std::string& str, int *ind) {
      double result = 0.0;
      double fraction = 0.1;
      bool isNegative = false;
      size_t index = *ind;

      if (str[index] == '-') {
          isNegative = true;
          index += 1;
      } else if (str[0] == '+') {
          index += 1;
      }

      while (index < str.size() && std::isdigit(str[index])) {
          result = result * 10.0 + (str[index] - '0');
          index++;
      }

      if (index < str.size() && str[index] == '.') {
          index++;

          while (index < str.size() && std::isdigit(str[index])) {
              result += (str[index] - '0') * fraction;
              fraction *= 0.1;
              index++;
          }
      }

      if (isNegative) {
          result = -result;
      }
      *ind = index;

      return result;
    }

    int queue_input(struct queue *queue, const std::string &str) {
      std::string str_new = str;
      char oper[5];
      int index = 0;
      int correct = 1;
      while (index != str_new.size() && correct) {
        if (isNumber(str_new[index])) {
          double d = customStrToDouble(str_new, &index);
          correct = isnormal(d);
          enqueue(d, 0, queue);
        } else if (isOperatorOrParanth(str_new[index])) {
          if ((str_new[index] == '-') && (isEmpty(queue) || ((queue->last->is_oper == 1) &&
                                                  (queue->last->number == 0.)))) {
            str_new[index] = '~';
          }
          oper[0] = str_new[index++];
          oper[1] = '\0';
          enqueue(encode(oper), 1, queue);
          if (encode(oper) == -1) correct = 0;
        } else if (str_new[index] == 'l' && str_new[index + 1] == 'n') {
          oper[0] = str_new[index++];
          oper[1] = str_new[index++];
          oper[2] = '\0';
          enqueue(encode(oper), 1, queue);
          if (encode(oper) == -1) correct = 0;
        } else if (str_new[index] == 'l' && str_new[index + 1] == 'o') {
          oper[0] = str_new[index++];
          oper[1] = str_new[index++];
          oper[2] = str_new[index++];
          oper[3] = '\0';
          enqueue(encode(oper), 1, queue);
          if (encode(oper) == -1) correct = 0;
        } else if (str_new[index] == 'm' && str_new[index + 1] == 'o') {
          oper[0] = str_new[index++];
          oper[1] = str_new[index++];
          oper[2] = str_new[index++];
          oper[3] = '\0';
          enqueue(encode(oper), 1, queue);
          if (encode(oper) == -1) correct = 0;
        } else if (str_new[index] == 'x') {
          enqueue(0, 2, queue);
          index++;
        } else if (str_new[index]== 's' && str_new[index + 1] == 'q') {
          oper[0] = str_new[index++];
          oper[1] = str_new[index++];
          oper[2] = str_new[index++];
          oper[3] = str_new[index++];
          oper[4] = '\0';
          enqueue(encode(oper), 1, queue);
          if (encode(oper) == -1) correct = 0;
        } else if (str_new[index] == 'a' && str_new[index + 1] == 'c') {
          oper[0] = str_new[index++];
          oper[1] = str_new[index++];
          oper[2] = str_new[index++];
          oper[3] = str_new[index++];
          oper[4] = '\0';
          enqueue(encode(oper), 1, queue);
          if (encode(oper) == -1) correct = 0;
        } else if (str_new[index] == 'a' && str_new[index + 1] == 's') {
          oper[0] = str_new[index++];
          oper[1] = str_new[index++];
          oper[2] = str_new[index++];
          oper[3] = str_new[index++];
          oper[4] = '\0';
          enqueue(encode(oper), 1, queue);
          if (encode(oper) == -1) correct = 0;
        } else if (str_new[index] == 'a' && str_new[index + 1] == 't') {
          oper[0] = str_new[index++];
          oper[1] = str_new[index++];
          oper[2] = str_new[index++];
          oper[3] = str_new[index++];
          oper[4] = '\0';
          enqueue(encode(oper), 1, queue);
          if (encode(oper) == -1) correct = 0;
        } else {
          oper[0] = str_new[index++];
          oper[1] = str_new[index++];
          oper[2] = str_new[index++];
          oper[3] = '\0';
          enqueue(encode(oper), 1, queue);
          if (encode(oper) == -1) correct = 0;
        }
      }
      return correct;
    }

    int Model::getValueFromExpression(const std::string &str, double *answer) {
      int correct = 1;
      std::string str_new = str;
      str_new.erase(std::remove(str_new.begin(), str_new.end(), ' '), str_new.end());

      queue *q_infix = 0;
      queue *q_postfix = 0;
      if (correct) {
        q_infix = init_queue();
        correct = (q_infix != 0);
      }
      if (correct) {
        correct = queue_input(q_infix, str_new);
      }
      if (correct) {
        q_postfix = init_queue();
        correct = (q_postfix != 0);
      }
      if (correct) {
        infixToPostfix(q_infix, q_postfix);
        double x = 4 * M_PI / 79 * 1;
        queue *queue_x = init_queue();
        insertValue(x, q_postfix, queue_x);
        double result = 0;
        int check = fromRPNtoValues(queue_x, &result);
        if (check == 1 || check == 4) {
          *answer = 0;
        } else {
          *answer = result;
        }
      }
      destroy_queue(q_infix);
      destroy_queue(q_postfix);
      return correct;
    }

    int Model::getValueFromExpressionForGraphWithX(const std::string &str, double *answer, double X) {
      int correct = 1;
      std::string str_new = str;
      str_new.erase(std::remove(str_new.begin(), str_new.end(), ' '), str_new.end());

      double *array_Y = answer;
      queue *q_infix = 0;
      queue *q_postfix = 0;
      if (correct) {
        q_infix = init_queue();
        correct = (q_infix != 0);
      }
      if (correct) {
        correct = queue_input(q_infix, str_new);
      }
      if (correct) {
        q_postfix = init_queue();
        correct = (q_postfix != 0);
      }
      if (correct) {
        infixToPostfix(q_infix, q_postfix);
        for (int i = 0; i < WIDTH && correct; i++) {
          queue *queue_x = init_queue();
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

    int Model::getValueFromExpressionForGraphWithoutX(const std::string &str, double *answer) {
      int correct = 1;
      std::string str_new = str;
      str_new.erase(std::remove(str_new.begin(), str_new.end(), ' '), str_new.end());

      double *array_Y = answer;
      queue *q_infix = 0;
      queue *q_postfix = 0;
      if (correct) {
        q_infix = init_queue();
        correct = (q_infix != 0);
      }
      if (correct) {
        correct = queue_input(q_infix, str_new);
      }
      if (correct) {
        q_postfix = init_queue();
        correct = (q_postfix != 0);
      }
      if (correct) {
        infixToPostfix(q_infix, q_postfix);
        for (int i = 0; i < WIDTH && correct; i++) {
          double X = 4 * M_PI / 79 * i;
          queue *queue_x = init_queue();
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

    int Model::getValueFromExpressionWithX(const std::string &str, double *answer, double X) {
      int correct = 1;
      std::string str_new = str;
      str_new.erase(std::remove(str_new.begin(), str_new.end(), ' '), str_new.end());

      queue *q_infix = 0;
      queue *q_postfix = 0;
      if (correct) {
        q_infix = init_queue();
        correct = (q_infix != 0);
      }
      if (correct) {
        correct = queue_input(q_infix, str_new);
      }
      if (correct) {
        q_postfix = init_queue();
        correct = (q_postfix != 0);
      }
      if (correct) {
        infixToPostfix(q_infix, q_postfix);
        queue *queue_x = init_queue();
        insertValue(X, q_postfix, queue_x);
        double result = 0;
        int check = fromRPNtoValues(queue_x, &result);
        if (check == 1 || check == 4) {
          *answer = 0;
        } else {
          *answer = result;
        }
      }
      destroy_queue(q_infix);
      destroy_queue(q_postfix);
      return correct;
    }

    bool Model::isOperator(const std::string& s) {
      return (s == "+" || s == "-" || s == "*" || s == "/" || s == "^" || s == "mod");
    }

    bool Model::isFunction(const std::string& s) {
      return (s == "cos" || s == "sin" || s == "tan" || s == "acos" || s == "asin" ||
              s == "atan" || s == "sqrt" || s == "ln" || s == "log");
    }


    void Model::initDepositCalculatorData(int period, double deposit, double rate, double tax) {
      periodDep_ = period;
      depositDep_ = deposit;
      rateDep_ = rate;
      taxDep_ = tax;
    }

    void Model::getValuesForDepositCalculatorWithCapitalization(double* profit_percent, double* profit_sum, double *tax_sum) {
      int days_of_month = 31;
      *profit_sum = depositDep_;
      for (int i = 0; i <= periodDep_ % days_of_month; i++) {
        *profit_sum += ((*profit_sum * rateDep_ * days_of_month) / 365) / 100;
      }
      *profit_percent = *profit_sum - depositDep_;
      *tax_sum = (*profit_sum * taxDep_) / 100;
    }

    void Model::getValuesForDepositCalculatorWithoutCapitalization(double* profit_percent, double* profit_sum, double *tax_sum) {
      *profit_percent = ((depositDep_ * rateDep_ * periodDep_) / 365) / 100;
      *profit_sum = depositDep_ + *profit_percent;
      *tax_sum = (*profit_sum * taxDep_) / 100;
    }



    void Model::initMortageCalculatorData(double amount, double rate, int term) {
      amount_ = amount;
      rate_ = rate;
      term_ = term;
    }

    void Model::getValuesForMortageAnnuityCalculator(int* mounth_payment, int* over_payment, int* whole_payment) {
      double percent_rate = (double)rate_ / (100 * 12);
      *mounth_payment =
          amount_ * ((percent_rate) / (1 - pow((1 + percent_rate), -term_)));
      *whole_payment = *mounth_payment * term_;
      *over_payment = *whole_payment - amount_;
    }

    void Model::getValuesForMortageDifferentyCalculator(int term_d, double* amount_d, double* base_loan, double* percent_loan, int* over_payment, int* whole_payment) {
      *base_loan = *amount_d / term_d;
      *percent_loan =
          (*amount_d * ((double)rate_ / 100) * 30) / (365);
      *over_payment += *percent_loan;
      *whole_payment += (*base_loan + *percent_loan);
      *amount_d -= *base_loan;
    }

};
