#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void timeout(); 

private:
    QTimer *pQTimer;
    Ui::MainWindow *ui;

    short player1Time;
    short player2Time;
    short currentPlayer;
    short gameTime;

    void updateProgressBar();
    void setGameInfoText(QString, short);
    void switchButtonClickHandler();
    void timeButtonClickHandler();
    void startStopButtonClickHandler();

};
#endif // MAINWINDOW_H
