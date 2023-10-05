#ifndef SRC_GRAPH_H_
#define SRC_GRAPH_H_

#define WIDTH 80
#define M_PI 3.14159265358979323846264338327950288

int getValueFromExpression(char *str, double *answer);
int getValueFromExpressionWithX(char *str, double *answer, double X);
int getValueFromExpressionForGraphWithoutX(char *str, double *answer);
int getValueFromExpressionForGraphWithX(char *str, double *answer, double X);

#endif  // SRC_GRAPH_H_
