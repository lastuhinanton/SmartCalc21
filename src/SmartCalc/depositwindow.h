#ifndef DEPOSITWINDOW_H
#define DEPOSITWINDOW_H

#include <QChartView>
#include <QPainter>
#include <QPieSeries>
#include <QPieSlice>
#include <QWidget>
#include <QtCharts>

namespace Ui {
class DepositWindow;
}

class DepositWindow : public QWidget {
  Q_OBJECT

 public:
  explicit DepositWindow(QWidget *parent = nullptr);
  ~DepositWindow();

 signals:
  void startWindow();

 private slots:
  void on_previousButton_clicked();
  void on_pushButton_clicked();

 private:
  Ui::DepositWindow *ui;
  int isValidatedDeposit(QString string);
};

#endif  // DEPOSITWINDOW_H
