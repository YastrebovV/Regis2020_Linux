#include "customplot.h"
#include "ui_customplot.h"

customplot::customplot(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::customplot)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);

    customplot::resize(1000, 500);

    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen()); // прямоугольник с размерами экрана
    QPoint center = rect.center(); //координаты центра экрана
    center.setX(center.x() - (this->width()/2));  // учитываем половину ширины окна
    center.setY(center.y() - (this->height()/2));  // .. половину высоты
    move(center);

    gridLayout = new QGridLayout();
    //********************************************************************
    //********************************************************************
    customPlot = new QCustomPlot(); // Инициализируем графическое полотно
    gridLayout->addWidget(customPlot,0,0,1,6);  // Устанавливаем customPlot в окно проложения

    customPlot->setInteraction(QCP::iRangeZoom,true);   // Включаем взаимодействие удаления/приближения
    customPlot->setInteraction(QCP::iRangeDrag, true);  // Включаем взаимодействие перетаскивания графика
    customPlot->axisRect()->setRangeDrag(Qt::Horizontal);   // Включаем перетаскивание только по горизонтальной оси
    customPlot->axisRect()->setRangeZoom(Qt::Horizontal);   // Включаем удаление/приближение только по горизонтальной оси
    customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);   // Подпись координат по Оси X в качестве Даты и Времени
    customPlot->xAxis->setDateTimeFormat("hmmh:");  // Устанавливаем формат даты и времени

    // Настраиваем шрифт по осям координат
    customPlot->xAxis->setTickLabelFont(QFont(QFont().family(), 11));
    customPlot->yAxis->setTickLabelFont(QFont(QFont().family(), 11));

    // Автоматическое масштабирование тиков по Оси X
    customPlot->xAxis->setAutoTickStep(true);

    /* Делаем видимыми оси X и Y по верхней и правой границам графика,
     * но отключаем на них тики и подписи координат
     * */
    customPlot->xAxis2->setVisible(true);
    customPlot->yAxis2->setVisible(true);
    customPlot->xAxis2->setTicks(false);
    customPlot->yAxis2->setTicks(false);
    customPlot->xAxis2->setTickLabels(false);
    customPlot->yAxis2->setTickLabels(false);

    customPlot->xAxis->setTickLabelColor(QColor(Qt::black));
    customPlot->yAxis->setTickLabelColor(QColor(Qt::black)); // черный цвет подписей тиков по Оси Y
    customPlot->legend->setVisible(true);   //Включаем Легенду графика
    // Устанавливаем Легенду в левый верхний угол графика
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft|Qt::AlignTop);
    //customPlot->setBackground(QBrush(QColor(42, 42, 43)));
    // Инициализируем график и привязываем его к Осям
    graphic = new QCPGraph(customPlot->xAxis, customPlot->yAxis);
    customPlot->addPlottable(graphic);  // Устанавливаем график на полотно
    graphic->setName("Температура, С");       // Устанавливаем
    graphic->setPen(QPen(QColor(Qt::green))); // Устанавливаем цвет графика
    //graphic->setAntialiased(false);         // Отключаем сглаживание, по умолчанию включено
    //graphic->setLineStyle(QCPGraph::lsImpulse); // График в виде импульсных тиков
    graphic->setLineStyle(QCPGraph::lsLine);

    /* Подключаем сигнал от Оси X об изменении видимого диапазона координат
     * к СЛОТу для переустановки формата времени оси.
     * */
    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)),
            this, SLOT(slotRangeChanged(QCPRange)));

    but_Date = new QPushButton("ПОСТРОИТЬ ГРАФИК");
    but_Date->setFixedHeight(60);
   // but_Date->setFixedWidth(500);
    gridLayout->addWidget(but_Date,2,0,1,6);

    but_Save_Graphic = new QPushButton("СОХРАНИТЬ В ФАЙЛ");
    but_Save_Graphic->setFixedHeight(60);
    //but_Save_Graphic->setFixedWidth(500);
    gridLayout->addWidget(but_Save_Graphic,3,0,1,6);

    label1 = new QLabel("Дата:");
    label1->setFixedWidth(50);
    gridLayout->addWidget(label1,1,0);

    dateEdit1 = new QDateEdit();
    dateEdit1->setFixedWidth(115);
    gridLayout->addWidget(dateEdit1,1,1,1,1);

    label2 = new QLabel("Дата 2:");
    label2->setFixedWidth(70);
    gridLayout->addWidget(label2,1,2);

    dateEdit2 = new QDateEdit();
    dateEdit2->setFixedWidth(115);
    gridLayout->addWidget(dateEdit2,1,3,1,1);
    dateEdit2->setDate(QDate::currentDate());

    checkBox1 = new QCheckBox();
    checkBox1->setFixedWidth(250);
    gridLayout->addWidget(checkBox1,1,4,1,1);
    checkBox1->setChecked(false);
    checkBox1->setText("Выборка по диапазону дат");

    QDate date = QDate::currentDate();
    dateEdit1->setDate(date);

    // Set the grid layout as a main layout
    ui->centralwidget->setLayout(gridLayout);

    connect(but_Date, SIGNAL(clicked()), this, SLOT(slotButClick()));
    connect(but_Save_Graphic, SIGNAL(clicked()), this, SLOT(saveToFile()));
}

customplot::~customplot()
{
    delete ui;
}


void customplot::slotButClick()
{
    int lenght_data = 0;
    QString date_Format = dateEdit1->date().toString("yyyy-MM-dd");
    QString date_Format2 = dateEdit2->date().toString("yyyy-MM-dd");

    QSqlQuery query;
    if(!checkBox1->isChecked()){
      query.exec("SELECT [Температура],[Уровень излучения],[Дата],[Время] FROM Kelvin_Data WHERE [Дата] = '"+date_Format+"';");
    }else{
      query.exec("SELECT [Температура],[Уровень излучения],[Дата],[Время] FROM Kelvin_Data WHERE [Дата] BETWEEN '"+date_Format+"' AND '"+ date_Format2 + "';");
    }
    //qDebug () << query.lastError().text();

    while(query.next()){
        lenght_data++;
    }

    QVector <double> time(lenght_data), income(lenght_data);

    if(!checkBox1->isChecked()){
      query.exec("SELECT [Температура],[Уровень излучения],[Дата],[Время], TimeUTC FROM Kelvin_Data WHERE [Дата] = '"+date_Format+"';");
    }else{
      query.exec("SELECT [Температура],[Уровень излучения],[Дата],[Время], TimeUTC FROM Kelvin_Data WHERE [Дата] BETWEEN '"+date_Format+"' AND '"+ date_Format2 + "';");
    }
    //qDebug () << query.lastError().text();

    lenght_data=0;
    while(query.next()){
        time[lenght_data] = query.value(4).toDouble();
        income[lenght_data] = query.value(0).toDouble();
        lenght_data++;
    }
    //qDebug () << query.lastError().text();

    graphic->setData(time, income); // Устанавливаем данные
    customPlot->rescaleAxes();      // Масштабируем график по данным
    customPlot->replot();           // Отрисовываем график
}

void customplot::slotRangeChanged(const QCPRange &newRange)
{
    /* Если область видимости графика меньше одного дня,
     * то отображаем часы и минуты по Оси X,
     * в противном случае отображаем дату "День Месяц Год"
     * */
    customPlot->xAxis->setDateTimeFormat((newRange.size() <= 86400)? "hh:mm" : "dd MMM yy");
}

void customplot::saveToFile()
{
    saveGraphic(customPlot);
}
void customplot::saveGraphic(QCustomPlot *graphic){
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
        tr("JPEG (*.jpg);;PDF (*.pdf)"));

        if (fileName != "") {
            QFile file(fileName);
            if (!file.open(QIODevice::WriteOnly)) {
                // error message
            } else {
                graphic->saveJpg(fileName);
                file.close();
            }
        }
}
