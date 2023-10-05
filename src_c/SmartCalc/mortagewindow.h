#ifndef MORTAGEWINDOW_H
#define MORTAGEWINDOW_H

#include <QWidget>

#include "simplegraph.h"

namespace Ui {
class MortageWindow;
}

class MortageWindow : public QWidget {
  Q_OBJECT

 public:
  explicit MortageWindow(QWidget *parent = nullptr);
  ~MortageWindow();

 signals:
  void startWindow();

 private slots:
  void on_pushButton_clicked();
  void on_pushButton_2_clicked();

 private:
  Ui::MortageWindow *ui;
  double xBegin, xEnd, h, X;

  QVector<double> x, y;
  int isValidatedMortage(QString string);
};

#endif  // MORTAGEWINDOW_H
