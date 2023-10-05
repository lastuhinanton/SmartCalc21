#include "simplegraph.h"

#include <string.h>

#include "simplewindow.h"
#include "ui_simplegraph.h"

SimpleGraph::SimpleGraph(QWidget *parent)
    : QWidget(parent), ui(new Ui::SimpleGraph) {
  ui->setupUi(this);
  QPixmap pix(":/src/image/19110ba5-e527-4d18-9cfa-413f9ccff7c3.jpeg");
  ui->backgroundLabel->setPixmap(pix);
}

SimpleGraph::~SimpleGraph() { delete ui; }

void SimpleGraph::on_previousButton_clicked() {
  this->close();
  emit startWindow();
}

void SimpleGraph::transfer_data(double *array) {
  for (int i = 0; i < 80; i++) {
    array_Y_2[i] = array[i];
  }

  h = 1;
  xBegin = 0;
  xEnd = 80;

  //    ui->graph->graph(0)->data()->clear();
  //    ui->graph->graph(1)->data()->clear();
  //    ui->graph->replot();

  ui->graph->xAxis->setRange(0, (int)array_Y_2[79] * 2);
  ui->graph->yAxis->setRange(0, (int)array_Y_2[79] * 2);

  for (int i = 0; i < (int)xEnd; i++) {
    x.push_back(i);
    y.push_back(array_Y_2[i]);
  }

  ui->graph->addGraph();
  ui->graph->graph(0)->addData(x, y);
  ui->graph->xAxis->setBasePen(QPen("#44eb9b"));
  ui->graph->xAxis->grid()->setPen(QPen("#44eb9b"));
  ui->graph->xAxis->grid()->setSubGridPen(QPen("#44eb9b"));
  ui->graph->yAxis->setBasePen(QPen("#44eb9b"));
  ui->graph->yAxis->grid()->setPen(QPen("#44eb9b"));
  ui->graph->yAxis->grid()->setSubGridPen(QPen("#44eb9b"));
  ui->graph->replot();
}
