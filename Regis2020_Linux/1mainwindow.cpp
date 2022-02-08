#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);//блокируем кнопку развернуть на весь экран и закрыть

    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen()); // прямоугольник с размерами экрана
    QPoint center = rect.center(); //координаты центра экрана
    center.setX(center.x() - (this->width()/2));  // учитываем половину ширины окна
    center.setY(center.y() - (this->height()/2));  // .. половину высоты
    move(center);

    if(!Temp_DB.isOpen()){
      dbc.conn_DB(&Temp_DB);
    }
    //if(Temp_DB.isOpen())
      //  qDebug () << "Connected DB";

    ui->ConnectDevice->setStyleSheet("background-color: red");

    //read avaible comports
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
            ui->comboBox->addItem(info.portName());

     ui->comboBox_2->addItem("1200");
     ui->comboBox_2->addItem("2400");
     ui->comboBox_2->addItem("4800");
     ui->comboBox_2->addItem("9600");
     ui->comboBox_2->addItem("19200");
     ui->comboBox_2->addItem("38400");
     ui->comboBox_2->addItem("57600");
     ui->comboBox_2->addItem("115200");

     ui->comboBox_3->addItem("5");
     ui->comboBox_3->addItem("6");
     ui->comboBox_3->addItem("7");
     ui->comboBox_3->addItem("8");

     ui->comboBox_4->addItem("None");
     ui->comboBox_4->addItem("Even");
     ui->comboBox_4->addItem("Odd");
     ui->comboBox_4->addItem("Space");
     ui->comboBox_4->addItem("Mark");

     ui->comboBox_5->addItem("1");
     ui->comboBox_5->addItem("2");

     ui->comboBox_6->addItem("None");
     ui->comboBox_6->addItem("Hardware");
     ui->comboBox_6->addItem("Software");



     QWidget *tab_3 = new QWidget();
     ui->tabWidget->addTab(tab_3, "Актуальные данные");

     QHBoxLayout *box = new QHBoxLayout(tab_3);

     QLabel *label1 = new QLabel("Актуальная температура:");
     label1->setFont(QFont("Ubuntu", 14, QFont::Normal));
     label1->setFixedWidth(250);
     box->addWidget(label1,1,0);

     label2 = new QLabel("0");
     label2->setFont(QFont("Ubuntu", 14, QFont::Normal));
     label2->setFixedWidth(100);
     box->addWidget(label2,1,0);

     timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()), this, SLOT(timer_Update()));
     timer->setInterval(2000);
    // timer->start();
}

MainWindow::~MainWindow()
{
    serialPort.close();
    delete ui;
}

void MainWindow::on_ConnectDevice_clicked()
{
    if(ui->comboBox->currentText()!=""){
       serialPort.setPortName("/dev/" +ui->comboBox->currentText());

    int itemNum = ui->comboBox_2->currentIndex();
    switch(itemNum){
      case 0: serialPort.setBaudRate(QSerialPort::Baud1200); break;
      case 1: serialPort.setBaudRate(QSerialPort::Baud2400); break;
      case 2: serialPort.setBaudRate(QSerialPort::Baud4800); break;
      case 3: serialPort.setBaudRate(QSerialPort::Baud9600); break;
      case 4: serialPort.setBaudRate(QSerialPort::Baud19200); break;
      case 5: serialPort.setBaudRate(QSerialPort::Baud38400); break;
      case 6: serialPort.setBaudRate(QSerialPort::Baud57600); break;
      case 7: serialPort.setBaudRate(QSerialPort::Baud115200); break;
    }

    itemNum = ui->comboBox_3->currentIndex();
    switch(itemNum){
          case 0: serialPort.setDataBits(QSerialPort::Data5); break;
          case 1: serialPort.setDataBits(QSerialPort::Data6); break;
          case 2: serialPort.setDataBits(QSerialPort::Data7); break;
          case 3: serialPort.setDataBits(QSerialPort::Data8); break;
    }

    itemNum = ui->comboBox_4->currentIndex();
    switch(itemNum){
           case 0: serialPort.setParity(QSerialPort::NoParity); break;
           case 1: serialPort.setParity(QSerialPort::EvenParity); break;
           case 2: serialPort.setParity(QSerialPort::OddParity); break;
           case 3: serialPort.setParity(QSerialPort::SpaceParity); break;
           case 4: serialPort.setParity(QSerialPort::MarkParity); break;
    }

    itemNum = ui->comboBox_5->currentIndex();
    switch(itemNum){
           case 0: serialPort.setStopBits(QSerialPort::OneStop); break;
           case 1: serialPort.setStopBits(QSerialPort::TwoStop); break;
    }

    itemNum = ui->comboBox_6->currentIndex();
    switch(itemNum){
            case 0: serialPort.setFlowControl(QSerialPort::NoFlowControl); break;
            case 1: serialPort.setFlowControl(QSerialPort::HardwareControl); break;
            case 2: serialPort.setFlowControl(QSerialPort::SoftwareControl); break;
    }
     connect(&serialPort, SIGNAL(readyRead()), SLOT(readReady()));

     if(!serialPort.isOpen()){
         serialPort.open(QSerialPort::ReadOnly);
         ui->ConnectDevice->setStyleSheet("background-color: green");
         timer->start();
     }else {
          timer->stop();
          serialPort.close();
          ui->ConnectDevice->setStyleSheet("background-color: red");
     }
  }
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

void MainWindow::timer_Update()
{
    QString str;
    QTextStream standardOutput(&str);
   if (!readData.isEmpty()) {
     standardOutput << readData << endl;
      label2->setText(standardOutput.readAll());
     readData = 0;
   }
}

void MainWindow::readReady()
{
    readData.append(serialPort.readAll());
}




