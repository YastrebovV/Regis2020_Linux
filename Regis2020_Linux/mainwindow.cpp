#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (wiringPiSetup () == -1)
       exit (1) ;
    pinMode (23, OUTPUT);

    PortThread = new QThread();
    KelvinClass = new KelvinArtoPort();
    KelvinClass->moveToThread(PortThread);

    connect(PortThread, SIGNAL(started()), KelvinClass, SLOT(outputData()));
    connect(KelvinClass, SIGNAL(finished()), PortThread, SLOT(terminate()));
    PortThread->start();

    Sleeper::msleep(1000);

    QIcon qi;
    qi.addFile(":/ico-temperatura-circle.svg");//  QCoreApplication::applicationDirPath()+"/ico-temperatura-circle.svg");
    setWindowIcon(qi);

    setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);//блокируем кнопку развернуть на весь экран и закрыть

    //размещение формы в центре экрана
    //**********************************************************
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen()); // прямоугольник с размерами экрана
    QPoint center = rect.center(); //координаты центра экрана
    center.setX(center.x() - (this->width()/2));  // учитываем половину ширины окна
    center.setY(center.y() - (this->height()/2));  // .. половину высоты
    move(center);
    //***********************************************************

     bool conn_DB = dbc.conn_DB(&Temp_DB, QCoreApplication::applicationDirPath()); //подключаемя к локальной базе данных

     timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
     timer->setInterval(15000);

     timerLED = new QTimer(this);
     connect(timerLED, SIGNAL(timeout()), this, SLOT(timerLedUpdate()));
     timerLED->setInterval(1000);

     timerPort= new QTimer(this);
     connect(timerPort, SIGNAL(timeout()), this, SLOT(timerPortUpdate()));
     timerPort->setInterval(50);

     timerClear= new QTimer(this);
     connect(timerClear, SIGNAL(timeout()), this, SLOT(timerClearUpdate()));
     timerClear->setInterval(3000);

     if (conn_DB){
           ui->label_4->setText("ПОДКЛЮЧЕНА");
        if (initCom()){
           ui->label_2->setText("ПОДКЛЮЧЕНО");
           timer->start();
           timerLED->start();
           timerPort->start();
        }
      }
}

MainWindow::~MainWindow()
{
    PortThread->terminate();
    delete ui;
}

void MainWindow::on_ChartPaint_clicked()
{
    customplot *cp = new customplot(this);
    if(Temp_DB.isOpen())
       cp->show();
}

void MainWindow::on_TableData_Open_clicked()
{
     TableData *td = new TableData;
     if(Temp_DB.isOpen())
        td->show();
}

void MainWindow::timerUpdate()
{
    float temp = KelvinClass->getTemp();
    float emiss = KelvinClass->getEmiss();

     ui->label_6->setText(QString::number(temp));

     if(temp!=temp_Old && temp>402.0 && temp<2000){
           temp_Old = temp;
           QSqlQuery query;
           QDateTime *dt = new QDateTime();

           double utc_time = dt->currentMSecsSinceEpoch()/1000;
           query.exec("INSERT INTO Kelvin_Data ([Температура],[Уровень излучения],[Дата],[Время],TimeUTC) VALUES ("+QString::number(temp)+", "+QString::number((emiss+1.0f)/100.0f)+", date(), time('now', 'localtime'),"+QString::number(utc_time, 'f',3)+");");
     }  
}
void MainWindow::timerLedUpdate()
{
    timerLED->stop();
    //включение/выключение светодиода
    if (digitalRead (23) == 0) {
       digitalWrite (23, HIGH);
    }else{
        digitalWrite (23, LOW);
    }

    saveToCard.saveDataTiFlash();
    timerLED->start();
}

bool MainWindow::initCom()
{
    //serialPort.setPortName("/dev/ttyS0");
    serialPort.setPortName("/dev/ttyUSB0");
    serialPort.setBaudRate(QSerialPort::Baud9600);
    serialPort.setDataBits(QSerialPort::Data8);
    serialPort.setParity(QSerialPort::NoParity);
    serialPort.setStopBits(QSerialPort::OneStop);
    serialPort.setFlowControl(QSerialPort::NoFlowControl);

    connect(&serialPort, SIGNAL(readyRead()),this,SLOT(readPort()));

    serialPort.open(QSerialPort::ReadOnly);
    if(serialPort.isOpen()){
      return true;
    }else {
      return false;
    }
}

void MainWindow::readPort()
{
//    QString str;
//    QTextStream standardOutput(&str);

//    if(serialPort.canReadLine()){
//    //qDebug() << "New ava. data: " << serialPort.bytesAvailable();
//    QByteArray readData = serialPort.readAll();
//    //qDebug() << readData;

//     if (readData.size()>=15) {
//       for(int i=8; i!=12; i++)
//         standardOutput << readData[i];
//         str_temp = standardOutput.readAll();

//       for(int i=6; i!=8; i++)
//         standardOutput << readData[i];
//         str_emiss = standardOutput.readAll();

//         KelvinClass->setTemp(str_temp.toFloat());
//         KelvinClass->setEmiss(str_emiss.toFloat());
//     }
//    }
}
void MainWindow::timerPortUpdate()
{
    QString str;
    QTextStream standardOutput(&str);

    if(serialPort.canReadLine()){
        timerClear->stop();
    //qDebug() << "New ava. data: " << serialPort.bytesAvailable();
    QByteArray readData = serialPort.readAll();
    //qDebug() << readData;

     if (readData.size()>=15) {
       for(int i=8; i!=12; i++)
         standardOutput << readData[i];
         str_temp = standardOutput.readAll();

       for(int i=6; i!=8; i++)
         standardOutput << readData[i];
         str_emiss = standardOutput.readAll();

         KelvinClass->setTemp(str_temp.toFloat());
         KelvinClass->setEmiss(str_emiss.toFloat());
     }
   }else{
        if(!timerClear->isActive())
            timerClear->start();
   }
}
void MainWindow::timerClearUpdate()
{
        timerClear->stop();
        KelvinClass->setTemp(0);
}



