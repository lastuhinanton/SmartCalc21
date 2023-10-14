#ifndef SRC_MODEL_H
#define SRC_MODEL_H


#include <iostream>
#include <string>
#include <stack>
#include <array>
#include <vector>
#include <cmath>
#include <sstream>
#include <cctype> 

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
    
    class Model
    {
        public:
            Model() {}
            ~Model() {}
            int getValueFromExpression(const std::string &str, double *answer);
            int getValueFromExpressionForGraphWithX(const std::string &str, double *answer, double X);
            int getValueFromExpressionForGraphWithoutX(const std::string &str, double *answer);
            int getValueFromExpressionWithX(const std::string &str, double *answer, double X);

        private:
            double data_;
            bool isOperator(const std::string& s);
            bool isFunction(const std::string& s);
    };

}

#include "model.tpp"

#endif  // SRC_MODEL_H
