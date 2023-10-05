#ifndef SIMPLEGRAPH_H
#define SIMPLEGRAPH_H

#include <QVector>
#include <QWidget>

namespace Ui {
class SimpleGraph;
}

class SimpleGraph : public QWidget {
  Q_OBJECT

 public:
  explicit SimpleGraph(QWidget *parent = nullptr);
  ~SimpleGraph();
  int flag = 0;
  void transfer_data(double *array);

 signals:
  void startWindow();

 private slots:
  void on_previousButton_clicked();

 private:
  Ui::SimpleGraph *ui;
  double xBegin, xEnd, h, X;
  QVector<double> x, y;

  double array_Y_2[80] = {0};
  int graph_status_2;
};

#endif  // SIMPLEGRAPH_H
