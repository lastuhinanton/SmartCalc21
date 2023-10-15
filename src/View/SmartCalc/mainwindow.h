#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

#include "depositwindow.h"
#include "mortagewindow.h"
#include "simplegraph.h"
#include "simplewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_selectButton_clicked();

 private:
  Ui::MainWindow *ui;
  //--- main window calculator ---
  SimpleWindow *simpleWindow;

  // additional part
  MortageWindow *mortageWindow;
  DepositWindow *depositWindow;
};
#endif  // MAINWINDOW_H
