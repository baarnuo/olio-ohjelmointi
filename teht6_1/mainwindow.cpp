#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , number(0)
{
    ui->setupUi(this);
    updateDisplay();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDisplay()
{
    QString str = QString::number(number);
    ui->numberDisplay->setText(str);
}


void MainWindow::on_countButton_clicked()
{
    number++;
    qDebug() << "Count button pressed.";
    updateDisplay();
}


void MainWindow::on_resetButton_clicked()
{
    number = 0;
    qDebug() << "Reset button pressed.";
    updateDisplay();
}
