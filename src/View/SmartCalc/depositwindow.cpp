#include "depositwindow.h"

#include "ui_depositwindow.h"

DepositWindow::DepositWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::DepositWindow) {
  ui->setupUi(this);
  QPixmap pix(":/src/image/19110ba5-e527-4d18-9cfa-413f9ccff7c3.jpeg");
  ui->backgroundLabel->setPixmap(pix);

  ui->period->setPlaceholderText("(days)");
  ui->deposit->setPlaceholderText("(rub)");
  ui->percents->setPlaceholderText("(%)");
  ui->tax->setPlaceholderText("(%)");

  ui->graph->setVisible(false);
}

DepositWindow::~DepositWindow() { delete ui; }

void DepositWindow::on_previousButton_clicked() {
  ui->period->clear();
  ui->deposit->clear();
  ui->percents->clear();
  ui->tax->clear();
  ui->gotPercents->clear();
  ui->sumTax->clear();
  ui->endDeposit->clear();
  ui->graph->setVisible(false);
  this->close();
  emit startWindow();
}

void DepositWindow::on_pushButton_clicked() {
  if (ui->deposit->text() != "" && ui->period->text() != "" &&
      ui->percents->text() != "" && ui->tax->text() != "") {
    QString deposit_check = ui->deposit->text();
    QString period_check = ui->period->text();
    QString percents_check = ui->percents->text();
    QString tax_check = ui->tax->text();

    if (isValidatedDeposit(deposit_check) && isValidatedDeposit(period_check) &&
        isValidatedDeposit(percents_check) && isValidatedDeposit(tax_check)) {
      QString profit_percent_str;
      QString tax_sum_str;
      QString profit_sum_str;

      double profit_sum = 0.0;
      double profit_percent = 0.0;
      double tax_sum = 0.0;

      int period = ui->period->text().toInt();
      double deposit = ui->deposit->text().toDouble();
      double rate = ui->percents->text().toDouble();
      double tax = ui->tax->text().toDouble();

      s21::Model m;
      s21::Controller c(&m);
      c.initDepData(period, deposit, rate, tax);
      if (ui->capitalisationCheck->isChecked()) {
        ui->capitalisationCheck->setChecked(false);
        c.calcDepWithCapital(&profit_percent, &profit_sum, &tax_sum);
      } else {
        c.calcDepWithoutCapital(&profit_percent, &profit_sum, &tax_sum);
      }

      profit_percent_str = QString::number(profit_percent);
      tax_sum_str = QString::number(tax_sum);
      profit_sum_str = QString::number(profit_sum - tax_sum);

      ui->gotPercents->clear();
      ui->sumTax->clear();
      ui->endDeposit->clear();
      ui->gotPercents->setText(profit_percent_str);
      ui->sumTax->setText(tax_sum_str);
      ui->endDeposit->setText(profit_sum_str);

      QPieSeries *series = new QPieSeries();

      series->append("Base payment", profit_sum - tax_sum);
      series->append("Percent payment", profit_sum - tax_sum - deposit);

      QPieSlice *slice = series->slices().at(0);
      slice->setLabelVisible(true);
      slice->setBrush(QColor("#8619e4"));

      slice = series->slices().at(1);
      slice->setExploded(true);
      slice->setLabelVisible(true);
      slice->setBrush(QColor("#44eb9b"));

      QChart *chart = new QChart();
      chart->addSeries(series);

      chart->layout()->setContentsMargins(0, 0, 0, 0);
      chart->setBackgroundRoundness(0);
      QChartView *chartview = new QChartView(chart);
      chartview->setParent(ui->graph);
      ui->graph->setVisible(true);
    } else {
      ui->gotPercents->setText("Invalid date");
      ui->sumTax->setText("Invalid date");
      ui->endDeposit->setText("Invalid date");
      ui->graph->setVisible(false);
    }
  }
}

int DepositWindow::isValidatedDeposit(QString string) {
  int correct = 1;
  QString patterns = "0123456789";
  int size = string.size();
  for (int i = 0; i < size && correct; i++) {
    if (!patterns.contains(string[i])) correct = 0;
  }
  return correct;
}
