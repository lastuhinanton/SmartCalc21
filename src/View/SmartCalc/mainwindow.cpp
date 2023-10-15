#include "mainwindow.h"

#include <QPixmap>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  QPixmap pix(":/src/image/19110ba5-e527-4d18-9cfa-413f9ccff7c3.jpeg");
  ui->main_background->setPixmap(pix);

  // Initialize calculator's windows
  simpleWindow = new SimpleWindow();
  mortageWindow = new MortageWindow();
  depositWindow = new DepositWindow();

  // Setings calculators
  simpleWindow->setMaximumHeight(630);
  simpleWindow->setMaximumWidth(1270);
  simpleWindow->setMinimumHeight(630);
  simpleWindow->setMinimumWidth(1270);

  mortageWindow->setMaximumHeight(630);
  mortageWindow->setMaximumWidth(1270);
  mortageWindow->setMinimumHeight(630);
  mortageWindow->setMinimumWidth(1270);

  depositWindow->setMaximumHeight(630);
  depositWindow->setMaximumWidth(1270);
  depositWindow->setMinimumHeight(630);
  depositWindow->setMinimumWidth(1270);

  // Connected to the slot start the main window on the button in the windows
  connect(simpleWindow, &SimpleWindow::startWindow, this, &MainWindow::show);
  connect(mortageWindow, &MortageWindow::startWindow, this, &MainWindow::show);
  connect(depositWindow, &DepositWindow::startWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_selectButton_clicked() {
  if (ui->simpleCalc->isChecked()) {
    simpleWindow->show();
    this->close();
  } else if (ui->mortageCalc->isChecked()) {
    mortageWindow->show();
    this->close();
  } else if (ui->depositCalc->isChecked()) {
    depositWindow->show();
    this->close();
  }
}
