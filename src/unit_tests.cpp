#include <gtest/gtest.h>
#include "calculator.h"

TEST(CalculatorTest, Test_1) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;

  std::string str = "2 + 2 + 2 + 2 + 2 + 2 + 2 + 2 + 2 + 2";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(1, correct);
  EXPECT_EQ(20, answer);
}

TEST(CalculatorTest, Test_2) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "1 + ";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(0, correct);
}

// TEST(CalculatorTest, Test_3) {
//   s21::Model m;
//   s21::Controller c(&m);
//   double answer = 0.0;
  
//   answer = 0.0;
//   std::string str =
//       "15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/"
//       "(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))";
//   int correct = c.calcExpression(str, &answer);
//   EXPECT_EQ(1, correct);
//   ASSERT_NEAR(-114.2, answer, 1e-2);
// }

TEST(CalculatorTest, Test_4) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str_1_extra = "16 - 5";
  int correct = c.calcExpression(str_1_extra, &answer);
  EXPECT_EQ(1, correct);
  EXPECT_EQ(11, answer);
}

// TEST(CalculatorTest, Test_5) {
//   s21::Model m;
//   s21::Controller c(&m);
//   double answer = 0.0;
  
//   answer = 0.0;
//   std::string str_1_extra = "5 - 5 - 5";
//   int correct = c.calcExpression(str_1_extra, &answer);
//   EXPECT_EQ(1, correct);
//   EXPECT_EQ(-5, answer);
// }

TEST(CalculatorTest, Test_6) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "2 / 2 / 2 / 2 / 2 / 2 / 2 / 2 / 2 / 2";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(1, correct);
  ASSERT_NEAR(0, answer, 1e-2);
}

TEST(CalculatorTest, Test_7) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "2 /";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(0, correct);
  EXPECT_EQ(0, answer);
}

TEST(CalculatorTest, Test_8) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "sin(0.7) + sin(0.7) + sin(0.7) + sin(0.7) + sin(0.7)";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(1, correct);
  ASSERT_NEAR(3.22108844, answer, 1e-7);
}

TEST(CalculatorTest, Test_9) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "sin";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(0, correct);
}

TEST(CalculatorTest, Test_10) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "cos(0.7) + cos(0.7) + cos(0.7) + cos(0.7) + cos(0.7)";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(1, correct);
  ASSERT_NEAR(3.82421094, answer, 1e-7);
}

TEST(CalculatorTest, Test_11) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "cos(";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(0, correct);
}

TEST(CalculatorTest, Test_12) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "tan(0.7) + tan(0.7) + tan(0.7) + tan(0.7) + tan(0.7)";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(1, correct);
  ASSERT_NEAR(4.2114419, answer, 1e-7);
}

TEST(CalculatorTest, Test_13) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "tan(";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(0, correct);
}

TEST(CalculatorTest, Test_14) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "ctg(0.7) + ctg(0.7) + ctg(0.7) + ctg(0.7) + ctg(0.7)";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(1, correct);
  ASSERT_NEAR(5.93620915, answer, 1e-7);
}

TEST(CalculatorTest, Test_15) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "ctg(";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(0, correct);
}

TEST(CalculatorTest, Test_16) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "acos(0.7) + acos(0.7) + acos(0.7) + acos(0.7) + acos(0.7)";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(1, correct);
  ASSERT_NEAR(3.976994151, answer, 1e-7);
}

TEST(CalculatorTest, Test_17) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "acos(";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(0, correct);
}

TEST(CalculatorTest, Test_18) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "asin(0.7) + asin(0.7) + asin(0.7) + asin(0.7) + asin(0.7)";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(1, correct);
  ASSERT_NEAR(3.876987483, answer, 1e-7);
}

TEST(CalculatorTest, Test_19) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "asin(";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(0, correct);
}

TEST(CalculatorTest, Test_20) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "atan(0.7) + atan(0.7) + atan(0.7) + atan(0.7) + atan(0.7)";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(1, correct);
  ASSERT_NEAR(3.053629822, answer, 1e-7);
}

TEST(CalculatorTest, Test_21) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "atan(";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(0, correct);
}

TEST(CalculatorTest, Test_22) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "(7 mod 7) + (7 mod 6) + (7 mod 6) + (7 mod 5) + (7 mod 4)";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(1, correct);
  EXPECT_EQ(21, answer);
}

TEST(CalculatorTest, Test_23) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "mod mod mod";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(0, correct);
}

TEST(CalculatorTest, Test_24) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "0 mod 0";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(0, correct);
}

TEST(CalculatorTest, Test_25) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "log(";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(0, correct);
}

TEST(CalculatorTest, Test_26) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "sqrt(4) + sqrt(7) + sqrt(0.99) + sqrt(81) + sqrt(100)";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(1, correct);
  ASSERT_NEAR(24.6407387, answer, 1e-7);
}

TEST(CalculatorTest, Test_27) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "sqrt(";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(0, correct);
}

TEST(CalculatorTest, Test_28) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "7 ^ 2 + 7 ^ 5 + 7 ^ 4 + 7 ^ 3 + 7 ^ 7";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(1, correct);
  EXPECT_EQ(843143, answer);
}

TEST(CalculatorTest, Test_29) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "7 ^";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(0, correct);
}

TEST(CalculatorTest, Test_30) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "ln(7) + ln(7) + ln(7) + ln(7) + ln(7)";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(1, correct);
  ASSERT_NEAR(9.729550745, answer, 1e-7);
}

TEST(CalculatorTest, Test_31) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "ln(";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(0, correct);
}

TEST(CalculatorTest, Test_32) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "-7";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(1, correct);
  EXPECT_EQ(-7, answer);
}

TEST(CalculatorTest, Test_33) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  answer = 0.0;
  std::string str = "-";
  int correct = c.calcExpression(str, &answer);
  EXPECT_EQ(0, correct);
}

TEST(CalculatorTest_X, Test_34) {
  s21::Model m;
  s21::Controller c(&m);
  double answer[80] = {0.0};
  
  int value = 2;
  std::string str = "x + x + x + x + x + x + x + x + x + x";
  int correct = c.calcExpressionForGraphWithX(str, answer, value);
  EXPECT_EQ(1, correct);
  EXPECT_EQ(20, answer[1]);
}

TEST(CalculatorTest_X, Test_35) {
  s21::Model m;
  s21::Controller c(&m);
  double answer[80] = {0.0};
  
  int value = 2;
  std::string str = "x * x * x * x * x * x * x * x * x * x";
  int correct = c.calcExpressionForGraphWithX(str, answer, value);
  EXPECT_EQ(1, correct);
  EXPECT_EQ(1024, answer[1]);
  EXPECT_EQ(1024, answer[10]);
}

TEST(CalculatorTest_X, Test_36) {
  s21::Model m;
  s21::Controller c(&m);
  double answer[80] = {0.0};
  
  int value = 2;
  std::string str = "x / x / x / x / x / x / x / x / x / x";
  int correct = c.calcExpressionForGraphWithX(str, answer, value);
  EXPECT_EQ(1, correct);
  EXPECT_EQ(100, answer[0]);
}

TEST(CalculatorTest_X, Test_37) {
  s21::Model m;
  s21::Controller c(&m);
  double answer[80] = {0.0};
  
  std::string str = "x / x / x / x / x / x / x / x / x / x";
  int correct = c.calcExpressionForGraphWithoutX(str, answer);
  EXPECT_EQ(1, correct);
  EXPECT_EQ(100, answer[0]);
}

TEST(CalculatorTest_X, Test_38) {
  s21::Model m;
  s21::Controller c(&m);
  double answer = 0.0;
  
  std::string str = "x / x / x / x / x / x / x / x / x / x";
  int correct = c.calcExpressionWithX(str, &answer, 2);
  EXPECT_EQ(1, correct);
  ASSERT_NEAR(0, answer, 1e-2);
}

TEST(CalculatorTest_Deposit, Test_39) {
  s21::Model m;
  s21::Controller c(&m);


  double profit_sum = 0.0;
  double profit_percent = 0.0;
  double tax_sum = 0.0;
  
  c.initDepData(365, 1000, 2, 2);
  c.calcDepWithCapital(&profit_percent, &profit_sum, &tax_sum);

  EXPECT_EQ(1043, (int)profit_sum);
  EXPECT_EQ(43, (int)profit_percent);
  EXPECT_EQ(20, (int)tax_sum);

  c.calcDepWithoutCapital(&profit_percent, &profit_sum, &tax_sum);

  EXPECT_EQ(1020, (int)profit_sum);
  EXPECT_EQ(20, (int)profit_percent);
  EXPECT_EQ(20, (int)tax_sum);
}

TEST(CalculatorTest_Mortage, Test_40) {
  s21::Model m;
  s21::Controller c(&m);

  int mounth_payment = 0.0;
  int over_payment = 0.0;
  int whole_payment = 0.0;

  double test_var_1 = 7.0;
  double test_var_2 = 7.0;
  double test_var_3 = 7.0;
  int test_var_4 = 7.0;
  int test_var_5 = 7.0;
  int test_var_6 = 7.0;

  
  c.initMortData(1000, 2, 12);
  c.calcMortAnnuity(&mounth_payment, &over_payment, &whole_payment);
  c.calcMortDifferenty(test_var_6, &test_var_2, &test_var_3, &test_var_1, &test_var_4, &test_var_5);

  EXPECT_EQ(84, mounth_payment);
  EXPECT_EQ(8, over_payment);
  EXPECT_EQ(1008, whole_payment);
}


int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
