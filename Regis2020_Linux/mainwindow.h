#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QString>
#include <QLabel>
#include <QApplication>
#include <QTimer>
#include <QHBoxLayout>
#include <QStatusBar>
#include <QThread>
#include "charttemp.h"
#include "tabledata.h"
#include "customplot.h"
#include "databaseclass.h"
#include <wiringPi.h>

#include "savetoflashcard.h"
#include "kelvinartoport.h"
//#include "outdisplay.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ChartPaint_clicked();
    void on_TableData_Open_clicked();
    void timerUpdate();
    void timerLedUpdate();
    void timerClearUpdate();
    void timerPortUpdate();
    void readPort();

private:
    Ui::MainWindow *ui;
    QThread *PortThread;
    KelvinArtoPort *KelvinClass;
    SaveToFlashCard saveToCard;
    QString str_temp;
    QString str_emiss;
    QLabel *label2;
    float temp_Old = 0.0;
    QTimer *timer;
    QTimer *timerLED;
    QTimer *timerClear;
    QTimer *timerPort;
    QSqlDatabase Temp_DB;
    DataBaseClass dbc;
    QSerialPort serialPort;
    bool initCom();

//    QByteArray comData;


};

class Sleeper : public QThread
{
public:
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
    static void sleep(unsigned long secs){QThread::sleep(secs);}
};

#endif // MAINWINDOW_H
