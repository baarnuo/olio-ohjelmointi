#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , state(1)
    , result(0)
    , operand(4)
{
    ui->setupUi(this);

    connect(ui->N0, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N1, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N2, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N3, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N4, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N5, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N6, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N7, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N8, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N9, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);

    connect(ui->add, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->sub, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->mul, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->div, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);

    connect(ui->clear, &QPushButton::clicked, this, &MainWindow::clearAndEnterClickHandler);
    connect(ui->enter, &QPushButton::clicked, this, &MainWindow::clearAndEnterClickHandler);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickedHandler()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug() << "Button name:" << name;

    if (state == 1) {
        number1 = number1 + name.last(1);
        ui->num1->setText(number1);
    } else if (state == 2) {
        number2 = number2 + name.last(1);
        ui->num2->setText(number2);
    }
}

void MainWindow::clearAndEnterClickHandler()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug() << "Button name:" << name;

    if (name == "enter") {
        if (number1.isEmpty() || number2.isEmpty()) {
            return;
        }
        state = 0;
        float n1 = number1.toFloat();
        float n2 = number2.toFloat();
        qDebug() << "Number 1 =" << n1 << "and number 2 =" << n2;

        switch (operand) {
        case 0:
            result = n1 + n2;
            qDebug() << "Operation:" << n1 << "+" << n2;
            break;
        case 1:
            result = n1 - n2;
            qDebug() << "Operation:" << n1 << "-" << n2;
            break;
        case 2:
            result = n1 * n2;
            qDebug() << "Operation:" << n1 << "*" << n2;
            break;
        case 3:
            if (n2 == 0) {
                qDebug() << "Error: Division by zero";
                ui->result->setText("error");
                return;
            } else {
                result = n1 / n2;
                qDebug() << "Operation:" << n1 << "/" << n2;
            } break;
        }
        ui->result->setText(QString::number(result));
        qDebug() << "Result =" << result;
    } else if (name == "clear") {
        resetLineEdits();
    }
}

void MainWindow::addSubMulDivClickHandler()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug() << "Button name:" << name;

    if (!number1.isEmpty() && number2.isEmpty()) {
        state = 2;
    } else if (number1.isEmpty()){
        state = 1;
    }

    if (name == "add") {
        operand = 0;
    } else if (name == "sub") {
        operand = 1;
    } else if (name == "mul") {
        operand = 2;
    } else if (name == "div") {
        operand = 3;
    }
}

void MainWindow::resetLineEdits()
{
    ui->num1->clear();
    ui->num2->clear();
    ui->result->clear();
    state = 1;
    number1 = "";
    number2 = "";
}
