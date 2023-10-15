#include "calculator.h"

int main(void) {
    double answer;
    s21::Model m;
    s21::Controller c(&m);

    c.initDepData(124, 1000, 21, 5);
    double profit_percent = 0;
    double profit_sum = 0;
    double tax_sum = 0;
    c.calcDepWithoutCapital(&profit_percent, &profit_sum, &tax_sum);

    std::cout << "Profit_sum == " << profit_percent << std::endl;
    std::cout << "Tax_sum == " << tax_sum << std::endl;
    std::cout << "End_deposit == " << profit_sum - tax_sum << std::endl << std::endl;;



    int mounth_payment = 0;
    int over_payment = 0;
    int whole_payment = 0;

    c.initMortData(1000, 7, 12);
    c.calcMortAnnuity(&mounth_payment, &over_payment, &whole_payment);

    std::cout << "Mounth_payment == " << mounth_payment << std::endl;
    std::cout << "Over_payment == " << over_payment << std::endl;
    std::cout << "Whole_payment == " << whole_payment << std::endl;


    return 0;
}
