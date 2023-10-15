#include "secretx.h"

#include "ui_secretx.h"

SecretX::SecretX(QWidget *parent) : QWidget(parent), ui(new Ui::SecretX) {
  ui->setupUi(this);
  QPixmap pix(
      ":/src/image/"
      "1662202042_35-telochki-org-p-golaya-s-pivom-krasivaya-erotika-42.jpeg");
  ui->label->setPixmap(pix);
}

SecretX::~SecretX() { delete ui; }
