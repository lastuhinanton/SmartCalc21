#ifndef SRC_CONTROLLER_H
#define SRC_CONTROLLER_H


namespace s21 {
    class Controller 
    {
        public:
            Controller(Model *m):model(m) {};

            int calcExpression(const std::string &str, double *answer);
            int calcExpressionWithX(const std::string &str, double *answer, double X);
            int calcExpressionForGraphWithX(const std::string &str, double *answer, double X);
            int calcExpressionForGraphWithoutX(const std::string &str, double *answer);
        private:
            Model *model;
    };
}

#include "model.h"
#include "controller.tpp"

#endif // SRC_CONTROLLER_H