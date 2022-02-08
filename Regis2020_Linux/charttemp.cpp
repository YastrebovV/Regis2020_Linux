#include "charttemp.h"
#include "ui_charttemp.h"
#include <QtCharts/QtCharts>
QT_CHARTS_USE_NAMESPACE

ChartTemp::ChartTemp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChartTemp)
{
    ui->setupUi(this);
    QDate date = QDate::currentDate();
    ui->dateEdit->setDate(date);
}

ChartTemp::~ChartTemp()
{
    delete ui;
}

void ChartTemp::Chart_Paint()
{
    int lenght_data = 0;

    //QChart *chart = new QChart();
    QLineSeries *series = new QLineSeries();
    QDate qd = ui->dateEdit->date();
    QString date_Format = qd.toString("yyyy-MM-dd");

    QSqlQuery query;
    query.exec("SELECT [Температура],[Уровень излучения],[Дата],[Время] FROM Kelvin_Data WHERE [Дата] = '"+date_Format+"';");
    qDebug () << query.lastError().text();

    while(query.next()){
        series->append(query.value(3).toLongLong(), query.value(0).toInt());
        lenght_data++;
    }
    qDebug () << query.lastError().text();

    ui->ChartView_1->chart()->update();

    //add data series ti the chart
    ui->ChartView_1->chart()->addSeries(series);

    //hide legend if needed
    //chart->legend()->hide();

    //specify legend position
    ui->ChartView_1->chart()->legend()->setAlignment(Qt::AlignBottom);

    //set chart title
    ui->ChartView_1->chart()->setTitle("Данные по температуре");

    //add axis to the chart

    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setTickCount(lenght_data);
    axisX->setFormat("h:mm");
    axisX->setTitleText("Время");
    axisX->setMin(QDateTime());
    ui->ChartView_1->chart()->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setTickCount(lenght_data);
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Температура");
    ui->ChartView_1->chart()->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    //create new view
  //  QChartView *chartView = new QChartView(chart);
  //  chartView->setRenderHint(QPainter::Antialiasing);


    //plase it in this widget
   // setCentralWidget(chartView);

}

void ChartTemp::on_OutData_clicked()
{
    Chart_Paint();
}
