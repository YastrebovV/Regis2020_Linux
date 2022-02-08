#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>
#include <QLabel>
#include <QApplication>
#include <QTimer>
#include <QHBoxLayout>
#include "charttemp.h"
#include "tabledata.h"
#include "customplot.h"
#include "databaseclass.h"



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
    void on_ConnectDevice_clicked();
    void on_ChartPaint_clicked();
    void on_TableData_Open_clicked();
    void timer_Update();
    void readReady();

private:
    Ui::MainWindow *ui;
    QSerialPort serialPort;

public:   
    QSqlDatabase Temp_DB;
    DataBaseClass dbc;
    QLabel *label2;
    QByteArray  readData;

    QTimer *timer;

};

#endif // MAINWINDOW_H
