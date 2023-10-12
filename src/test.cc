#include "model.h"

int main(void) {
    s21::Model m;
    const char *string = "10 * 7 * 2 * 2 * 10 / 10";
    m.getValueFromExpression(string);

    std::cout << m.getTheResult() << std::endl;
}
