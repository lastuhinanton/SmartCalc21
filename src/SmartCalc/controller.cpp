
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

    void Controller::initDepData(int period, double deposit, double rate, double tax) {
        model->initDepositCalculatorData(period, deposit, rate, tax);
    }

    void Controller::calcDepWithCapital(double* profit_percent, double* profit_sum, double *tax_sum) {
        model->getValuesForDepositCalculatorWithCapitalization(profit_percent, profit_sum, tax_sum);
    }

    void Controller::calcDepWithoutCapital(double* profit_percent, double* profit_sum, double *tax_sum) {
        model->getValuesForDepositCalculatorWithoutCapitalization(profit_percent, profit_sum, tax_sum);
    }

    void Controller::initMortData(double amount, double rate, int term) {
        model->initMortageCalculatorData(amount, rate, term);
    }

    void Controller::calcMortAnnuity(int* mounth_payment, int* over_payment, int* whole_payment) {
        model->getValuesForMortageAnnuityCalculator(mounth_payment, over_payment, whole_payment);
    }

    void Controller::calcMortDifferenty(int term_d, double* amount_d, double* base_loan, double* percent_loan, int* over_payment, int* whole_payment) {
        model->getValuesForMortageDifferentyCalculator(term_d, amount_d, base_loan, percent_loan, over_payment, whole_payment);
    }

}