#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.setMaximumHeight(630);
  w.setMaximumWidth(1270);
  w.setMinimumHeight(630);
  w.setMinimumWidth(1270);
  w.show();
  return a.exec();
}
