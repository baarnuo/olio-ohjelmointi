#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , player1Time(0)
    , player2Time(0)
    , currentPlayer(1)
    , gameTime(0)
{
    ui->setupUi(this);
    pQTimer = new QTimer();
    connect(pQTimer, &QTimer::timeout, this, &MainWindow::timeout);

    connect(ui->switchPlayer1, &QPushButton::clicked, this, &MainWindow::switchButtonClickHandler);
    connect(ui->switchPlayer2, &QPushButton::clicked, this, &MainWindow::switchButtonClickHandler);

    connect(ui->setTimeButton120s, &QPushButton::clicked, this, &MainWindow::timeButtonClickHandler);
    connect(ui->setTimeButton5min, &QPushButton::clicked, this, &MainWindow::timeButtonClickHandler);

    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startStopButtonClickHandler);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::startStopButtonClickHandler);

    setGameInfoText("Select playtime and press start game!", 20);
    ui->progressBar1->setValue(0);
    ui->progressBar2->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pQTimer;
}

void MainWindow::timeout()
{
    pQTimer->start(1000);
    updateProgressBar();
}

void MainWindow::updateProgressBar()
{
    double percentage;

    if (currentPlayer == 1) {
        percentage = (((double) player1Time / gameTime) * 100.0);
        qDebug() << "Player 1 percentage" << percentage << "("<< player1Time <<"s )";
        player1Time--;
        ui->progressBar1->setValue(percentage);
        if (percentage == 0) {
            pQTimer->stop();
            setGameInfoText("Player 2 WON!!", 25);
            gameTime = 0;
        }
    } else {
        percentage = (((double) player2Time / gameTime) * 100.0);
        qDebug() << "Player 2 percentage" << percentage << "("<< player2Time <<"s )";
        player2Time--;
        ui->progressBar2->setValue(percentage);
        if (percentage == 0) {
            pQTimer->stop();
            setGameInfoText("Player 1 WON!!", 25);
            gameTime = 0;
        }
    }
}

void MainWindow::setGameInfoText(QString text, short fontSize)
{
    QFont font = ui->statusLabel->font();
    font.setPointSize(fontSize);
    ui->statusLabel->setFont(font);
    ui->statusLabel->setText(text);
}

void MainWindow::switchButtonClickHandler()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();

    if (name == "switchPlayer1") {
        currentPlayer = 2;
    } else {
        currentPlayer = 1;
    }

    qDebug() << currentPlayer;
}

void MainWindow::timeButtonClickHandler()
{
    const short time2Min = 120;
    const short time5Min = 300;

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();

    if (!pQTimer->isActive()) {
        if (name == "setTimeButton120s") {
            gameTime = time2Min;
            player1Time = time2Min;
            player2Time = time2Min;
            ui->progressBar1->setValue(100);
            ui->progressBar2->setValue(100);
        } else {
            gameTime = time5Min;
            player1Time = time5Min;
            player2Time = time5Min;
            ui->progressBar1->setValue(100);
            ui->progressBar2->setValue(100);
        }
        setGameInfoText("Ready to play", 20);
    }
}

void MainWindow::startStopButtonClickHandler()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();

    if (name == "startButton" && !pQTimer->isActive() && gameTime != 0) {
        currentPlayer = 1;
        timeout();
        setGameInfoText("Game ongoing", 20);
        ui->progressBar1->setRange(0, 100);
        ui->progressBar1->setValue(100);
        ui->progressBar2->setRange(0, 100);
        ui->progressBar2->setValue(100);
    } else if (name == "stopButton" && gameTime != 0) {
        pQTimer->stop();
        setGameInfoText("New game via start button", 20);
        ui->progressBar1->setValue(0);
        ui->progressBar2->setValue(0);
        gameTime = 0;
        player1Time = 0;
        player2Time = 0;
    }
}
