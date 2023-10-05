#include "anotherwindow.h"

#include "ui_anotherwindow.h"

AnotherWindow::AnotherWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::AnotherWindow) {
  ui->setupUi(this);
}

AnotherWindow::~AnotherWindow() { delete ui; }
