#ifndef SRC_CONTROLLER_H
#define SRC_CONTROLLER_H

#include "../Model/model.h"

namespace s21 {
class Controller {
 public:
  Controller(Model* m) : model(m){};

  int calcExpression(const std::string& str, double* answer);
  int calcExpressionWithX(const std::string& str, double* answer, double X);
  int calcExpressionForGraphWithX(const std::string& str, double* answer,
                                  double X);
  int calcExpressionForGraphWithoutX(const std::string& str, double* answer);

  void initDepData(int period, double deposit, double rate, double tax);
  void calcDepWithCapital(double* profit_percent, double* profit_sum,
                          double* tax_sum);
  void calcDepWithoutCapital(double* profit_percent, double* profit_sum,
                             double* tax_sum);

  void initMortData(double amount, double rate, int term);
  void calcMortAnnuity(int* mounth_payment, int* over_payment,
                       int* whole_payment);
  void calcMortDifferenty(int term_d, double* amount_d, double* base_loan,
                          double* percent_loan, int* over_payment,
                          int* whole_payment);

 private:
  Model* model;
};
}  // namespace s21

#endif  // SRC_CONTROLLER_H