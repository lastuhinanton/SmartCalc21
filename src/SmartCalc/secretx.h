#ifndef SECRETX_H
#define SECRETX_H

#include <QWidget>

namespace Ui {
class SecretX;
}

class SecretX : public QWidget {
  Q_OBJECT

 public:
  explicit SecretX(QWidget *parent = nullptr);
  ~SecretX();

 private:
  Ui::SecretX *ui;
};

#endif  // SECRETX_H
