#include "s21_test_calc.h"

START_TEST(test_1) {
  double answer = 0.0;
  char *str_1 = "2 + 2 + 2 + 2 + 2 + 2 + 2 + 2 + 2 + 2";
  int correct = getValueFromExpression(str_1, &answer);
  ck_assert_int_eq(1, correct);
  ck_assert_int_eq(20, answer);

  answer = 0.0;
  char *str_1_1 = "1 +";
  correct = getValueFromExpression(str_1_1, &answer);
  ck_assert_int_eq(0, correct);

  answer = 0.0;
  char *str_1_extra =
      "15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/"
      "(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))";
  correct = getValueFromExpression(str_1_extra, &answer);
  ck_assert_int_eq(1, correct);
  ck_assert_double_eq_tol(-114.2, answer, 1e-2);

  answer = 0.0;
  char *str_2 = "2 - 2 - 2 - 2 - 2 - 2 - 2 - 2 - 2 - 2";
  correct = getValueFromExpression(str_2, &answer);
  ck_assert_int_eq(1, correct);
  ck_assert_int_eq(-16, answer);

  answer = 0.0;
  char *str_2_1 = "2 -";
  correct = getValueFromExpression(str_2_1, &answer);
  ck_assert_int_eq(0, correct);

  answer = 0.0;
  char *str_3 = "2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2";
  correct = getValueFromExpression(str_3, &answer);
  ck_assert_int_eq(1, correct);
  ck_assert_int_eq(1024, answer);

  answer = 0.0;
  char *str_3_1 = "2 *";
  correct = getValueFromExpression(str_3_1, &answer);
  ck_assert_int_eq(0, correct);

  answer = 0.0;
  char *str_4 = "2 / 2 / 2 / 2 / 2 / 2 / 2 / 2 / 2 / 2";
  correct = getValueFromExpression(str_4, &answer);
  ck_assert_int_eq(1, correct);
  ck_assert_int_eq(0, answer);

  answer = 0.0;
  char *str_4_1 = "2 /";
  correct = getValueFromExpression(str_4_1, &answer);
  ck_assert_int_eq(0, correct);

  answer = 0.0;
  char *str_5 = "sin(0.7) + sin(0.7) + sin(0.7) + sin(0.7) + sin(0.7)";
  correct = getValueFromExpression(str_5, &answer);
  ck_assert_int_eq(1, correct);
  ck_assert_ldouble_eq_tol(3.22108844, answer, 1e-7);

  answer = 0.0;
  char *str_5_1 = "sin";
  correct = getValueFromExpression(str_5_1, &answer);
  ck_assert_int_eq(0, correct);

  answer = 0.0;
  char *str_6 = "cos(0.7) + cos(0.7) + cos(0.7) + cos(0.7) + cos(0.7)";
  correct = getValueFromExpression(str_6, &answer);
  ck_assert_int_eq(1, correct);
  ck_assert_ldouble_eq_tol(3.82421094, answer, 1e-7);

  answer = 0.0;
  char *str_6_1 = "cos(";
  correct = getValueFromExpression(str_6_1, &answer);
  ck_assert_int_eq(0, correct);

  answer = 0.0;
  char *str_7 = "tan(0.7) + tan(0.7) + tan(0.7) + tan(0.7) + tan(0.7)";
  correct = getValueFromExpression(str_7, &answer);
  ck_assert_int_eq(1, correct);
  ck_assert_ldouble_eq_tol(4.2114419, answer, 1e-7);

  answer = 0.0;
  char *str_7_1 = "tan(";
  correct = getValueFromExpression(str_7_1, &answer);
  ck_assert_int_eq(0, correct);

  answer = 0.0;
  char *str_8 = "ctg(0.7) + ctg(0.7) + ctg(0.7) + ctg(0.7) + ctg(0.7)";
  correct = getValueFromExpression(str_8, &answer);
  ck_assert_int_eq(1, correct);
  ck_assert_ldouble_eq_tol(5.93620915, answer, 1e-7);

  answer = 0.0;
  char *str_8_1 = "ctg(";
  correct = getValueFromExpression(str_8_1, &answer);
  ck_assert_int_eq(0, correct);

  answer = 0.0;
  char *str_9 = "acos(0.7) + acos(0.7) + acos(0.7) + acos(0.7) + acos(0.7)";
  correct = getValueFromExpression(str_9, &answer);
  ck_assert_int_eq(1, correct);
  ck_assert_ldouble_eq_tol(3.976994151, answer, 1e-7);

  answer = 0.0;
  char *str_9_1 = "acos(";
  correct = getValueFromExpression(str_9_1, &answer);
  ck_assert_int_eq(0, correct);

  answer = 0.0;
  char *str_10 = "asin(0.7) + asin(0.7) + asin(0.7) + asin(0.7) + asin(0.7)";
  correct = getValueFromExpression(str_10, &answer);
  ck_assert_int_eq(1, correct);
  ck_assert_ldouble_eq_tol(3.876987483, answer, 1e-7);

  answer = 0.0;
  char *str_10_1 = "asin(";
  correct = getValueFromExpression(str_10_1, &answer);
  ck_assert_int_eq(0, correct);

  answer = 0.0;
  char *str_11 = "atan(0.7) + atan(0.7) + atan(0.7) + atan(0.7) + atan(0.7)";
  correct = getValueFromExpression(str_11, &answer);
  ck_assert_int_eq(1, correct);
  ck_assert_ldouble_eq_tol(3.053629822, answer, 1e-7);

  answer = 0.0;
  char *str_11_1 = "atan(";
  correct = getValueFromExpression(str_11_1, &answer);
  ck_assert_int_eq(0, correct);

  answer = 0.0;
  char *str_12 = "(7 mod 7) + (7 mod 6) + (7 mod 6) + (7 mod 5) + (7 mod 4)";
  correct = getValueFromExpression(str_12, &answer);
  ck_assert_int_eq(1, correct);
  ck_assert_int_eq(21, answer);

  answer = 0.0;
  char *str_12_1 = "mod mod mod";
  correct = getValueFromExpression(str_12_1, &answer);
  ck_assert_int_eq(0, correct);

  answer = 0.0;
  char *str_12_2 = "0 mod 0";
  correct = getValueFromExpression(str_12_2, &answer);
  ck_assert_int_eq(0, correct);

  answer = 0.0;
  char *str_13 =
      "log(7 mod 7 + 1) + log(7 mod 6) + log(7 mod 6) + log(7 mod 5) + log(7 "
      "mod 4)";
  correct = getValueFromExpression(str_13, &answer);
  ck_assert_int_eq(1, correct);
  ck_assert_ldouble_eq_tol(2.857332496, answer, 1e-7);

  answer = 0.0;
  char *str_13_1 = "log(";
  correct = getValueFromExpression(str_13_1, &answer);
  ck_assert_int_eq(0, correct);

  answer = 0.0;
  char *str_14 = "sqrt(4) + sqrt(7) + sqrt(0.99) + sqrt(81) + sqrt(100)";
  correct = getValueFromExpression(str_14, &answer);
  ck_assert_int_eq(1, correct);
  ck_assert_ldouble_eq_tol(24.6407387, answer, 1e-7);

  answer = 0.0;
  char *str_14_1 = "sqrt(";
  correct = getValueFromExpression(str_14_1, &answer);
  ck_assert_int_eq(0, correct);

  answer = 0.0;
  char *str_15 = "7 ^ 2 + 7 ^ 5 + 7 ^ 4 + 7 ^ 3 + 7 ^ 7";
  correct = getValueFromExpression(str_15, &answer);
  ck_assert_int_eq(1, correct);
  ck_assert_int_eq(843143, answer);

  answer = 0.0;
  char *str_15_1 = "7 ^";
  correct = getValueFromExpression(str_15_1, &answer);
  ck_assert_int_eq(0, correct);

  answer = 0.0;
  char *str_16 = "ln(7) + ln(7) + ln(7) + ln(7) + ln(7)";
  correct = getValueFromExpression(str_16, &answer);
  ck_assert_int_eq(1, correct);
  ck_assert_ldouble_eq_tol(9.729550745, answer, 1e-7);

  answer = 0.0;
  char *str_16_1 = "ln(";
  correct = getValueFromExpression(str_16_1, &answer);
  ck_assert_int_eq(0, correct);

  answer = 0.0;
  char *str_17 = "-7";
  correct = getValueFromExpression(str_17, &answer);
  ck_assert_int_eq(1, correct);
  ck_assert_int_eq(-7, answer);

  answer = 0.0;
  char *str_17_1 = "-";
  correct = getValueFromExpression(str_17_1, &answer);
  ck_assert_int_eq(0, correct);
}
END_TEST

START_TEST(test_2) {
  double answer = 0.0;
  int value = 2;
  char *str_1 = "x + x + x + x + x + x + x + x + x + x";
  int correct = getValueFromExpressionWithX(str_1, &answer, value);
  ck_assert_int_eq(1, correct);
  ck_assert_int_eq(20, answer);

  answer = 0.0;
  char *str_2 = "x - x - x - x - x - x - x - x - x - x";
  correct = getValueFromExpressionWithX(str_2, &answer, value);
  ck_assert_int_eq(1, correct);
  ck_assert_int_eq(-16, answer);

  answer = 0.0;
  char *str_3 = "x * x * x * x * x * x * x * x * x * x";
  correct = getValueFromExpressionWithX(str_3, &answer, value);
  ck_assert_int_eq(1, correct);
  ck_assert_int_eq(1024, answer);

  answer = 0.0;
  char *str_4 = "x / x / x / x / x / x / x / x / x / x";
  correct = getValueFromExpressionWithX(str_4, &answer, value);
  ck_assert_int_eq(1, correct);
  ck_assert_int_eq(0, answer);

  answer = 0.0;
  value = 7;
  char *str_5 = "sin(x) + sin(x) + sin(x) + sin(x) + sin(x)";
  correct = getValueFromExpressionWithX(str_5, &answer, value);
  ck_assert_int_eq(1, correct);
  ck_assert_ldouble_eq_tol(3.28493299, answer, 1e-7);

  answer = 0.0;
  char *str_6 = "cos(x) + cos(x) + cos(x) + cos(x) + cos(x)";
  correct = getValueFromExpressionWithX(str_6, &answer, value);
  ck_assert_int_eq(1, correct);
  ck_assert_ldouble_eq_tol(3.76951127, answer, 1e-7);

  answer = 0.0;
  char *str_7 = "tan(x) + tan(x) + tan(x) + tan(x) + tan(x)";
  correct = getValueFromExpressionWithX(str_7, &answer, value);
  ck_assert_int_eq(1, correct);
  ck_assert_ldouble_eq_tol(4.35724, answer, 1e-7);

  answer = 0.0;
  char *str_8 = "ctg(x) + ctg(x) + ctg(x) + ctg(x) + ctg(x)";
  correct = getValueFromExpressionWithX(str_8, &answer, value);
  ck_assert_int_eq(1, correct);
  ck_assert_ldouble_eq_tol(5.7375771, answer, 1e-7);

  answer = 0.0;
  char *str_12 = "(x mod x) + (x mod 6) + (x mod 6) + (x mod 5) + (x mod 4)";
  correct = getValueFromExpressionWithX(str_12, &answer, value);
  ck_assert_int_eq(1, correct);
  ck_assert_int_eq(21, answer);

  answer = 0.0;
  char *str_13 =
      "log(x mod x + 1) + log(x mod 6) + log(x mod 6) + log(x mod 5) + log(x "
      "mod 4)";
  correct = getValueFromExpressionWithX(str_13, &answer, value);
  ck_assert_int_eq(1, correct);
  ck_assert_ldouble_eq_tol(2.857332496, answer, 1e-7);

  answer = 0.0;
  char *str_14 = "sqrt(4) + sqrt(x) + sqrt(0.99) + sqrt(81) + sqrt(100)";
  correct = getValueFromExpressionWithX(str_14, &answer, value);
  ck_assert_int_eq(1, correct);
  ck_assert_ldouble_eq_tol(24.6407387, answer, 1e-7);

  answer = 0.0;
  char *str_15 = "x ^ 2 + x ^ 5 + x ^ 4 + x ^ 3 + x ^ x";
  correct = getValueFromExpressionWithX(str_15, &answer, value);
  ck_assert_int_eq(1, correct);
  ck_assert_int_eq(843143, answer);

  answer = 0.0;
  char *str_16 = "x ^ 2 + x ^ 5 + x ^ 4 + x ^ 3 + x ^ x";
  correct = getValueFromExpressionWithX(str_16, &answer, value);
  ck_assert_int_eq(1, correct);
  ck_assert_int_eq(843143, answer);
}
END_TEST

START_TEST(test_3) {
  double answer[80];
  int value = 2;
  char *str_1 = "x + x + x + x + x + x + x + x + x + x";
  int correct = getValueFromExpressionForGraphWithX(str_1, answer, value);
  ck_assert_int_eq(1, correct);
  ck_assert_int_eq(20, answer[0]);

  memset(answer, 0, sizeof(answer));
  char *str_2 = "x - x - x - x - x - x - x - x - x - x";
  correct = getValueFromExpressionForGraphWithX(str_2, answer, value);
  ck_assert_int_eq(1, correct);
  ck_assert_int_eq(-16, answer[0]);

  memset(answer, 0, sizeof(answer));
  char *str_3 = "x * x * x * x * x * x * x * x * x * x";
  correct = getValueFromExpressionForGraphWithX(str_3, answer, value);
  ck_assert_int_eq(1, correct);
  ck_assert_int_eq(1024, answer[0]);

  memset(answer, 0, sizeof(answer));
  char *str_4 = "x / x / x / x / x / x / x / x / x / x";
  correct = getValueFromExpressionForGraphWithX(str_4, answer, value);
  ck_assert_int_eq(1, correct);
  ck_assert_int_eq(100, answer[0]);

  memset(answer, 0, sizeof(answer));
  value = 7;
  char *str_5 = "sin(x) + sin(x) + sin(x) + sin(x) + sin(x)";
  correct = getValueFromExpressionForGraphWithX(str_5, answer, value);
  ck_assert_int_eq(1, correct);
  ck_assert_ldouble_eq_tol(3.28493299, answer[0], 1e-7);

  memset(answer, 0, sizeof(answer));
  char *str_6 = "cos(x) + cos(x) + cos(x) + cos(x) + cos(x)";
  correct = getValueFromExpressionForGraphWithX(str_6, answer, value);
  ck_assert_int_eq(1, correct);
  ck_assert_ldouble_eq_tol(3.76951127, answer[0], 1e-7);

  memset(answer, 0, sizeof(answer));
  char *str_7 = "tan(x) + tan(x) + tan(x) + tan(x) + tan(x)";
  correct = getValueFromExpressionForGraphWithX(str_7, answer, value);
  ck_assert_int_eq(1, correct);
  ck_assert_ldouble_eq_tol(4.35724, answer[0], 1e-7);

  memset(answer, 0, sizeof(answer));
  char *str_8 = "ctg(x) + ctg(x) + ctg(x) + ctg(x) + ctg(x)";
  correct = getValueFromExpressionForGraphWithX(str_8, answer, value);
  ck_assert_int_eq(1, correct);
  ck_assert_ldouble_eq_tol(5.7375771, answer[0], 1e-7);

  memset(answer, 0, sizeof(answer));
  char *str_12 = "(x mod x) + (x mod 6) + (x mod 6) + (x mod 5) + (x mod 4)";
  correct = getValueFromExpressionForGraphWithX(str_12, answer, value);
  ck_assert_int_eq(1, correct);
  ck_assert_int_eq(21, answer[0]);

  memset(answer, 0, sizeof(answer));
  char *str_13 =
      "log(x mod x + 1) + log(x mod 6) + log(x mod 6) + log(x mod 5) + log(x "
      "mod 4)";
  correct = getValueFromExpressionForGraphWithX(str_13, answer, value);
  ck_assert_int_eq(1, correct);
  ck_assert_ldouble_eq_tol(2.857332496, answer[0], 1e-7);

  memset(answer, 0, sizeof(answer));
  char *str_14 = "sqrt(4) + sqrt(x) + sqrt(0.99) + sqrt(81) + sqrt(100)";
  correct = getValueFromExpressionForGraphWithX(str_14, answer, value);
  ck_assert_int_eq(1, correct);
  ck_assert_ldouble_eq_tol(24.6407387, answer[0], 1e-7);

  memset(answer, 0, sizeof(answer));
  char *str_15 = "x ^ 2 + x ^ 5 + x ^ 4 + x ^ 3 + x ^ x";
  correct = getValueFromExpressionForGraphWithX(str_15, answer, value);
  ck_assert_int_eq(1, correct);
  ck_assert_int_eq(843143, answer[0]);
}
END_TEST

START_TEST(test_4) {
  double answer[80];
  char *str_1 = "x + x + x + x + x + x + x + x + x + x";
  int correct = getValueFromExpressionForGraphWithoutX(str_1, answer);
  ck_assert_int_eq(1, correct);
  ck_assert_int_eq(0, answer[0]);

  memset(answer, 0, sizeof(answer));
  char *str_2 = "x - x - x - x - x - x - x - x - x - x";
  correct = getValueFromExpressionForGraphWithoutX(str_2, answer);
  ck_assert_int_eq(1, correct);
  ck_assert_int_eq(0, answer[0]);

  memset(answer, 0, sizeof(answer));
  char *str_3 = "x * x * x * x * x * x * x * x * x * x";
  correct = getValueFromExpressionForGraphWithoutX(str_3, answer);
  ck_assert_int_eq(1, correct);
  ck_assert_int_eq(0, answer[0]);

  memset(answer, 0, sizeof(answer));
  char *str_4 = "x / x / x / x / x / x / x / x / x / x";
  correct = getValueFromExpressionForGraphWithoutX(str_4, answer);
  ck_assert_int_eq(1, correct);
  ck_assert_int_eq(100, answer[0]);

  memset(answer, 0, sizeof(answer));
  char *str_5 = "sin(x) + sin(x) + sin(x) + sin(x) + sin(x)";
  correct = getValueFromExpressionForGraphWithoutX(str_5, answer);
  ck_assert_int_eq(1, correct);
  ck_assert_ldouble_eq_tol(0, answer[0], 1e-7);

  memset(answer, 0, sizeof(answer));
  char *str_6 = "cos(x) + cos(x) + cos(x) + cos(x) + cos(x)";
  correct = getValueFromExpressionForGraphWithoutX(str_6, answer);
  ck_assert_int_eq(1, correct);
  ck_assert_ldouble_eq_tol(5, answer[0], 1e-7);

  memset(answer, 0, sizeof(answer));
  char *str_7 = "tan(x) + tan(x) + tan(x) + tan(x) + tan(x)";
  correct = getValueFromExpressionForGraphWithoutX(str_7, answer);
  ck_assert_int_eq(1, correct);
  ck_assert_ldouble_eq_tol(0, answer[0], 1e-7);

  memset(answer, 0, sizeof(answer));
  char *str_8 = "ctg(x) + ctg(x) + ctg(x) + ctg(x) + ctg(x)";
  correct = getValueFromExpressionForGraphWithoutX(str_8, answer);
  ck_assert_int_eq(1, correct);
  ck_assert_double_infinite(answer[0]);

  memset(answer, 0, sizeof(answer));
  char *str_13 =
      "log(x mod x + 1) + log(x mod 6) + log(x mod 6) + log(x mod 5) + log(x "
      "mod 4)";
  correct = getValueFromExpressionForGraphWithoutX(str_13, answer);
  ck_assert_int_eq(1, correct);
  ck_assert_double_nan(answer[0]);

  memset(answer, 0, sizeof(answer));
  char *str_14 = "sqrt(4) + sqrt(x) + sqrt(0.99) + sqrt(81) + sqrt(100)";
  correct = getValueFromExpressionForGraphWithoutX(str_14, answer);
  ck_assert_int_eq(1, correct);
  ck_assert_ldouble_eq_tol(21.995, answer[0], 1e-3);

  memset(answer, 0, sizeof(answer));
  char *str_15 = "x ^ 2 + x ^ 5 + x ^ 4 + x ^ 3 + x ^ x";
  correct = getValueFromExpressionForGraphWithoutX(str_15, answer);
  ck_assert_int_eq(1, correct);
  ck_assert_int_eq(1, answer[0]);
}
END_TEST

Suite *Calc(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Isabeler");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_1);
  tcase_add_test(tc_core, test_2);
  tcase_add_test(tc_core, test_3);
  tcase_add_test(tc_core, test_4);

  suite_add_tcase(s, tc_core);

  return s;
}