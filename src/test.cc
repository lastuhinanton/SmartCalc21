#include "calculator.h"

int main(void) {
  double answer;
  s21::Model m;
  s21::Controller c(&m);
  const char *string = "123+1+21*21*100";
  std::cout << c.calcExpression(string, &answer) << std::endl;
  std::cout << answer << std::endl;

  double answer_array[80] = {'\0'};
  const char *string_x = "21 * x";
  std::cout << c.calcExpressionForGraphWithX(string_x, answer_array, 2)
            << std::endl;
  std::cout << answer_array[20] << std::endl;

  double answer_array_2[80] = {'\0'};
  const char *string_y = "21 * x";
  std::cout << c.calcExpressionForGraphWithoutX(string_y, answer_array_2)
            << std::endl;
  std::cout << answer_array_2[6] << std::endl;

  double answer_3 = {'\0'};
  const char *string_q = "21 * x";
  std::cout << c.calcExpressionWithX(string_q, &answer_3, 20) << std::endl;
  std::cout << answer_3 << std::endl;

  return 0;
}
