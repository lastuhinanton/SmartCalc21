#include "simplewindow.h"

#include <QPixmap>

#include "ui_simplewindow.h"

SimpleWindow::SimpleWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::SimpleWindow) {
  ui->setupUi(this);
  QPixmap pix(":/src/image/19110ba5-e527-4d18-9cfa-413f9ccff7c3.jpeg");
  ui->backgroundLabel->setPixmap(pix);

  XRoom = new SecretX();

  // Initialize calculator's windows
  simpleGraph = new SimpleGraph();

  simpleGraph->setMaximumHeight(630);
  simpleGraph->setMaximumWidth(1270);
  simpleGraph->setMinimumHeight(630);
  simpleGraph->setMinimumWidth(1270);

  // Connected to the slot start the main window on the button in the windows
  connect(simpleGraph, &SimpleGraph::startWindow, this, &SimpleWindow::show);

  connect(ui->zero, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->one, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->two, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->three, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->four, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->five, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->six, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->seven, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->eight, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->nine, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->cos, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->sin, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->tan, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->acos, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->asin, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->atan, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->sqrt, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->ln, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->log, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->plus, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->minus, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->bracketOpen, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->bracketClose, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->multiply, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->divide, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->mod, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pow, SIGNAL(clicked()), this, SLOT(digits_numbers()));

  ui->output->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
  ui->ownX2->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
  ui->groupBase->setStyleSheet("QFrame::pane { border: 0; }");
  ui->groupGeom->setStyleSheet("QFrame::pane { border: 0; }");

  ui->pushEqual->setStyleSheet(
      "QPushButton {background-color: #44eb9b; border-radius: 10px; color: "
      "rgb(74, 71, 169); font-weight: bold;}");
  ui->pushGraph->setStyleSheet(
      "QPushButton {background-color: #44eb9b; border-radius: 10px; color: "
      "rgb(74, 71, 169); font-weight: bold;}");
  ui->AC->setStyleSheet(
      "QPushButton {background-color: #44eb9b; border-radius: 10px; color: "
      "rgb(74, 71, 169); font-weight: bold;}");

  ui->groupGeom->setVisible(false);
  ui->groupBase->setVisible(false);
  ui->ownX1->setVisible(false);
  ui->ownX2->setVisible(false);
  ui->plusX->setVisible(false);
}

SimpleWindow::~SimpleWindow() { delete ui; }

void SimpleWindow::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();

  QString new_label;

  if (ui->plusX->isVisible()) {
    if (ui->ownX2->text().contains(".") && button->text() == "0") {
      if (ui->ownX2->text() == "0")
        new_label = button->text();
      else
        new_label = ui->ownX2->text() + button->text();
    } else if (button->text() == "0" || button->text() == "1" ||
               button->text() == "2" || button->text() == "3" ||
               button->text() == "4" || button->text() == "5" ||
               button->text() == "6" || button->text() == "7" ||
               button->text() == "8" || button->text() == "9") {
      if (ui->ownX2->text() == "0")
        new_label = button->text();
      else
        new_label = ui->ownX2->text() + button->text();
    } else {
      if (ui->ownX2->text() == "0")
        new_label = button->text();
      else
        new_label = ui->ownX2->text() + button->text();
    }
    ui->ownX2->setText(new_label);
  } else {
    if (ui->output->text().contains(".") && button->text() == "0") {
      if (ui->output->text() == "0")
        new_label = button->text();
      else
        new_label = ui->output->text() + button->text();
    } else if (button->text() == "0" || button->text() == "1" ||
               button->text() == "2" || button->text() == "3" ||
               button->text() == "4" || button->text() == "5" ||
               button->text() == "6" || button->text() == "7" ||
               button->text() == "8" || button->text() == "9") {
      if (ui->output->text() == "0")
        new_label = button->text();
      else
        new_label = ui->output->text() + button->text();
    } else {
      if (ui->output->text() == "0")
        new_label = button->text();
      else
        new_label = ui->output->text() + button->text();
    }
    ui->output->setText(new_label);
  }
}

void SimpleWindow::on_previousButton_clicked() {
  ui->groupGeom->setVisible(false);
  ui->groupBase->setVisible(false);
  this->close();
  emit startWindow();
}

void SimpleWindow::on_geomOp_clicked() {
  if (!ui->groupGeom->isVisible()) {
    ui->groupGeom->setVisible(true);
  } else {
    ui->groupGeom->setVisible(false);
  }
}

void SimpleWindow::on_baseOp_clicked() {
  if (!ui->groupBase->isVisible()) {
    ui->groupBase->setVisible(true);
  } else {
    ui->groupBase->setVisible(false);
  }
}

void SimpleWindow::on_AC_clicked() {
  ui->output->clear();
  ui->output->setText("0");
  ui->ownX2->setText("");
}

void SimpleWindow::on_ownXButton_clicked() {
  if (!ui->plusX->isVisible()) {
    ui->ownX1->setVisible(true);
    ui->ownX2->setVisible(true);
    ui->plusX->setVisible(true);
  } else {
    if (ui->ownX2->text() == "") {
      ui->ownX1->setVisible(false);
      ui->ownX2->setVisible(false);
    }
    ui->plusX->setVisible(false);
  }
}

void SimpleWindow::on_plusX_clicked() {
  if (ui->output->text() == "0") {
    ui->output->setText("x");
  } else {
    ui->output->setText(ui->output->text() + "x");
  }
}

void SimpleWindow::on_pushEqual_clicked() {
  if (ui->ownX2->text() != "" && ui->output->text().contains("x")) {
    double result = 0.0;
    char str[260] = {0};
    int i = 0;
    int size = (int)(ui->output->text().toStdString()).size();
    for (i = 0; i < size; i++) {
      str[i] = (ui->output->text().toStdString())[i];
    }
    str[i] = '\0';
    getValueFromExpressionWithX(str, &result, ui->ownX2->text().toDouble());
    QString answer = QString::number(result, 'g', 15);
    ui->output->setText(answer);
  } else if (ui->ownX2->text() == "21xxx") {
    this->close();
    XRoom->show();
  } else if (ui->output->text() == "21xxx") {
    ui->ownX2->setText(ui->ownX2->text() + "x");
    ui->output->clear();
  } else {
    double result = 0.0;
    char str[260] = {0};
    int size = (int)(ui->output->text().toStdString()).size();
    int i = 0;
    for (i = 0; i < size; i++) {
      str[i] = (ui->output->text().toStdString())[i];
    }
    str[i] = '\0';

    getValueFromExpression(str, &result);
    QString answer = QString::number(result, 'g', 15);
    ui->output->setText(answer);
  }
}

void SimpleWindow::on_pushGraph_clicked() {
  int correct = 0;
  graph_status = 0;
  if (ui->output->text() != "" && ui->ownX2->text() == "") {
    memset(array_Y, 0, 80);
    char str[260] = {0};
    int size = (int)(ui->output->text().toStdString()).size();
    for (int i = 0; i < size; i++) {
      str[i] = (ui->output->text().toStdString())[i];
    }
    correct = getValueFromExpressionForGraphWithoutX(str, array_Y);
  } else if (ui->output->text() != "" && ui->ownX2->text() != "" &&
             ui->output->text().contains("x")) {
    memset(array_Y, 0, 80);
    char str[260] = {0};
    int size = (int)(ui->output->text().toStdString()).size();
    for (int i = 0; i < size; i++) {
      str[i] = (ui->output->text().toStdString())[i];
    }
    correct = getValueFromExpressionForGraphWithX(str, array_Y,
                                                  ui->ownX2->text().toDouble());
  }

  if (correct) {
    simpleGraph->transfer_data(array_Y);
    this->close();
    simpleGraph->show();
  }
}

void SimpleWindow::on_pushPoint_clicked() {
  ui->output->setText(ui->output->text() + ".");
}
