#include "mortagewindow.h"

#include <math.h>

#include <QPixmap>

#include "ui_mortagewindow.h"

MortageWindow::MortageWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::MortageWindow) {
  ui->setupUi(this);
  QPixmap pix(":/src/image/19110ba5-e527-4d18-9cfa-413f9ccff7c3.jpeg");
  ui->backgroundLabel->setPixmap(pix);

  ui->lineEdit_amount->setPlaceholderText("(rub)");
  ui->lineEdit_term->setPlaceholderText("(mounths)");
  ui->lineEdit_rate->setPlaceholderText("(%)");

  ui->widget->setVisible(false);
}

MortageWindow::~MortageWindow() { delete ui; }

void MortageWindow::on_pushButton_clicked() {
  ui->lineEdit_amount->clear();
  ui->lineEdit_rate->clear();
  ui->lineEdit_term->clear();
  ui->lineEdit_mounth_pay->clear();
  ui->lineEdit_over_pay->clear();
  ui->lineEdit_whole_pay->clear();
  ui->widget->setVisible(false);
  this->close();
  emit startWindow();
}

void MortageWindow::on_pushButton_2_clicked() {
  if (ui->lineEdit_amount->text() != "" && ui->lineEdit_rate->text() != "" &&
      ui->lineEdit_term->text() != "" &&
      (ui->annuityButton->isChecked() ||
       ui->differentiatedButton->isChecked())) {
    QString mounth_payment_str = ui->lineEdit_amount->text();
    QString over_payment_str = ui->lineEdit_rate->text();
    QString whole_payment_str = ui->lineEdit_term->text();

    if (isValidatedMortage(mounth_payment_str) &&
        isValidatedMortage(over_payment_str) &&
        isValidatedMortage(whole_payment_str)) {
      double amount = ui->lineEdit_amount->text().toDouble();
      double rate = ui->lineEdit_rate->text().toDouble();
      int term = ui->lineEdit_term->text().toInt();

      int mounth_payment = 0;
      int over_payment = 0;
      int whole_payment = 0;

      h = 1;
      xBegin = 0;
      xEnd = term + 1;

      ui->widget->xAxis->setRange(0, term);

      X = xBegin;

      if (ui->annuityButton->isChecked()) {
        ui->widget->yAxis->setRange(0, (int)amount / 2);
        double percent_rate = (double)rate / (100 * 12);
        mounth_payment =
            amount * ((percent_rate) / (1 - pow((1 + percent_rate), -term)));
        whole_payment = mounth_payment * term;
        over_payment = whole_payment - amount;

        for (int i = 0; i < (int)xEnd; i++) {
          X += h;
          x.push_back(X);
          y.push_back(mounth_payment);
        }

      } else if (ui->differentiatedButton->isChecked()) {
        ui->widget->yAxis->setRange(0, amount / 2);

        double base_loan;
        double percent_loan;
        int day_of_mounth = 30;
        int day_of_year = 365;

        mounth_payment =
            (amount / term) +
            ((amount * (rate / 100) * day_of_mounth) / (day_of_year));

        for (int i = 0; term; i++, term--) {
          base_loan = amount / term;
          percent_loan =
              (amount * ((double)rate / 100) * day_of_mounth) / (day_of_year);
          over_payment += percent_loan;
          whole_payment += (base_loan + percent_loan);
          amount -= base_loan;
          x.push_back(i);
          y.push_back(base_loan + percent_loan);
        }
      }

      ui->widget->addGraph();
      ui->widget->graph(0)->addData(x, y);
      ui->widget->xAxis->setBasePen(QPen("#44eb9b"));
      ui->widget->xAxis->grid()->setPen(QPen("#44eb9b"));
      ui->widget->xAxis->grid()->setSubGridPen(QPen("#44eb9b"));
      ui->widget->yAxis->setBasePen(QPen("#44eb9b"));
      ui->widget->yAxis->grid()->setPen(QPen("#44eb9b"));
      ui->widget->yAxis->grid()->setSubGridPen(QPen("#44eb9b"));
      ui->widget->replot();

      ui->widget->setVisible(true);

      mounth_payment_str = QString::number(mounth_payment);
      over_payment_str = QString::number(over_payment);
      whole_payment_str = QString::number(whole_payment);

      ui->lineEdit_mounth_pay->setText(mounth_payment_str);
      ui->lineEdit_over_pay->setText(over_payment_str);
      ui->lineEdit_whole_pay->setText(whole_payment_str);
    } else {
      ui->lineEdit_mounth_pay->setText("Invalid data");
      ui->lineEdit_over_pay->setText("Invalid data");
      ui->lineEdit_whole_pay->setText("Invalid data");
      ui->widget->setVisible(false);
    }
  }
}

int MortageWindow::isValidatedMortage(QString string) {
  int correct = 1;
  QString patterns = "0123456789";
  int size = string.size();
  for (int i = 0; i < size && correct; i++) {
    if (!patterns.contains(string[i])) correct = 0;
  }
  return correct;
}
