#ifndef SRC_MODEL_H
#define SRC_MODEL_H

#include <algorithm>
#include <array>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

namespace s21 {

#define OPERATORS_STR                                                       \
  "(", ")", "+", "-", "*", "/", "sin", "cos", "tan", "ctg", "acos", "asin", \
      "atan", "mod", "log", "ln", "sqrt", "~", "^"
#define OPERATORS_INT \
  0, 1, 10, 11, 20, 21, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62

#define M_PI 3.14159265358979323846264338327950288

const int OPERATORS_COUNT = 19;
const int MAX = 1000;
const int WIDTH = 80;

struct stack {
  int number;
  stack *ptr;
};

struct list {
  double number;
  int is_oper;
  list *ptr;
};

struct queue {
  list *first;
  list *last;
};

class Model {
 public:
  Model() {}
  ~Model() {}
  int getValueFromExpression(const std::string &str, double *answer);
  int getValueFromExpressionForGraphWithX(const std::string &str,
                                          double *answer, double X);
  int getValueFromExpressionForGraphWithoutX(const std::string &str,
                                             double *answer);
  int getValueFromExpressionWithX(const std::string &str, double *answer,
                                  double X);

  void initDepositCalculatorData(int period, double deposit, double rate,
                                 double tax);
  void getValuesForDepositCalculatorWithCapitalization(double *profit_percent,
                                                       double *profit_sum,
                                                       double *tax_sum);
  void getValuesForDepositCalculatorWithoutCapitalization(
      double *profit_percent, double *profit_sum, double *tax_sum);

  void initMortageCalculatorData(double amount, double rate, int term);
  void getValuesForMortageAnnuityCalculator(int *mounth_payment,
                                            int *over_payment,
                                            int *whole_payment);
  void getValuesForMortageDifferentyCalculator(int term_d, double *amount_d,
                                               double *base_loan,
                                               double *percent_loan,
                                               int *over_payment,
                                               int *whole_payment);

 private:
  int periodDep_;
  double depositDep_;
  double rateDep_;
  double taxDep_;
  double amount_;
  double rate_;
  double term_;
  bool isOperator(const std::string &s);
  bool isFunction(const std::string &s);
  stack *init_stack(int n);
  stack *push(int n, stack **stack_g);
  stack *pop(int *n, stack **stack_g);
  queue *init_queue();
  queue *enqueue(double d, int n, queue *t_queue);
  int isEmpty(queue *t_queue);
  queue *dequeue(double *d, int *n, queue *t_queue);
  void destroy_queue(queue *t_queue);
  int isNumber(char c);
  int isOperatorOrParanth(char c);
  int fromRPNtoValues(queue *q_postfix, double *result);
  int insertValue(double x, queue *queue_g, queue *queue_x);
  int infixToPostfix(queue *q_infix, queue *q_postfix);
  int encode(char *s);
  double customStrToDouble(const std::string &str, int *ind);
  int queue_input(struct queue *queue, const std::string &str);
};

}  // namespace s21

#endif  // SRC_MODEL_H
