#ifndef SIMPLEWINDOW_H
#define SIMPLEWINDOW_H

#include <string.h>

#include <QWidget>

#include "../../Controller/controller.h"
#include "../../Model/model.h"
#include "secretx.h"
#include "simplegraph.h"

namespace Ui {
class SimpleWindow;
}

class SimpleWindow : public QWidget {
  Q_OBJECT

 public:
  explicit SimpleWindow(QWidget *parent = nullptr);
  ~SimpleWindow();
  double array_Y[80] = {0};
  int graph_status;

 signals:
  void startWindow();

 private slots:
  void digits_numbers();
  void on_previousButton_clicked();
  void on_geomOp_clicked();
  void on_baseOp_clicked();
  void on_AC_clicked();
  void on_ownXButton_clicked();
  void on_plusX_clicked();
  void on_pushEqual_clicked();

  void on_pushGraph_clicked();

  void on_pushPoint_clicked();

 private:
  // additional part
  SimpleGraph *simpleGraph;

  Ui::SimpleWindow *ui;
  SecretX *XRoom;
};

#endif  // SIMPLEWINDOW_H
