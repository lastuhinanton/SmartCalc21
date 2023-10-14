
#include "controller.h"

namespace s21 {
    int Controller::calcExpression(const std::string &str, double *answer) {
        return model->getValueFromExpression(str, answer);
    }

    int Controller::calcExpressionWithX(const std::string &str, double *answer, double X) {
        return model->getValueFromExpressionWithX(str, answer, X);
    }

    int Controller::calcExpressionForGraphWithX(const std::string &str, double *answer, double X) {
        return model->getValueFromExpressionForGraphWithX(str, answer, X);
    }

    int Controller::calcExpressionForGraphWithoutX(const std::string &str, double *answer) {
        return model->getValueFromExpressionForGraphWithoutX(str, answer);
    }
}