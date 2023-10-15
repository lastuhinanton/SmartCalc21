#ifndef ANOTHERWINDOW_H
#define ANOTHERWINDOW_H

#include <QWidget>

namespace Ui {
class AnotherWindow;
}

class AnotherWindow : public QWidget {
  Q_OBJECT

 public:
  explicit AnotherWindow(QWidget *parent = nullptr);
  ~AnotherWindow();

 signals:
  void selectWindow();

 private:
  Ui::AnotherWindow *ui;
};

#endif  // ANOTHERWINDOW_H
