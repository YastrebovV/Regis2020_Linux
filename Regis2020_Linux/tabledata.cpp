#include "tabledata.h"
#include "ui_tabledata.h"
#include "mainwindow.h"

TableData::TableData(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TableData)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);

    TableData::resize(1000, 500);

    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen()); // прямоугольник с размерами экрана
    QPoint center = rect.center(); //координаты центра экрана
    center.setX(center.x() - (this->width()/2));  // учитываем половину ширины окна
    center.setY(center.y() - (this->height()/2));  // .. половину высоты
    move(center);

    gridLayout = new QGridLayout();

    but_Date = new QPushButton("ЗАПРОС ДАННЫХ");
    but_Date->setFixedHeight(50);
    gridLayout->addWidget(but_Date,2,0,1,6);

    label1 = new QLabel("Дата:");
    label1->setFixedWidth(70);
    gridLayout->addWidget(label1,1,0);

    dateEdit1 = new QDateEdit();
    dateEdit1->setFixedWidth(115);
    gridLayout->addWidget(dateEdit1,1,1,1,1);
    dateEdit1->setDate(QDate::currentDate());

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

    tableView1 = new QTableView();
    gridLayout->addWidget(tableView1,0,0,1,6);

//    but_tEMP = new QPushButton("ВРЕМЕННАЯ");
//    but_tEMP->setFixedHeight(50);
//    gridLayout->addWidget(but_tEMP,2,1,1,1);

    but_Save_CSV = new QPushButton("СОХРАНИТЬ ТАБЛИЦУ В ФАЙЛ");
    but_Save_CSV->setFixedHeight(50);
    gridLayout->addWidget(but_Save_CSV,3,0,1,6);

    // Set the grid layout as a main layout
    ui->centralwidget->setLayout(gridLayout);

    connect(but_Date, SIGNAL(clicked()), this, SLOT(outData_clicked()));
 //  connect(but_tEMP, SIGNAL(clicked()), this, SLOT(pushButton_clicked()));
    connect(but_Save_CSV, SIGNAL(clicked()), this, SLOT(saveToCSV()));
}

TableData::~TableData()
{
    delete ui; 
}


void TableData::getData(QSqlQueryModel *md, QString date1, QString date2)
{
//    QString date_Format = dateEdit1->date().toString("yyyy-MM-dd");
//    QString date_Format2 = dateEdit2->date().toString("yyyy-MM-dd");

    if(!checkBox1->isChecked()){
      md->setQuery("SELECT [Температура],[Уровень излучения],[Дата],[Время] FROM Kelvin_Data WHERE [Дата] = '"+date1+"';");
    }else{
      md->setQuery("SELECT [Температура],[Уровень излучения],[Дата],[Время] FROM Kelvin_Data WHERE [Дата] BETWEEN '"+date1+"' AND '"+ date2 + "';");
    }
}

void TableData::outData_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QString date_Format = dateEdit1->date().toString("yyyy-MM-dd");
    QString date_Format2 = dateEdit2->date().toString("yyyy-MM-dd");

    getData(model, date_Format, date_Format2);

    tableView1->setModel(model);
   //qDebug () << model->lastError().text();
    QSize sizeView = tableView1->size();

    tableView1->setColumnWidth(0, sizeView.width()/4);
    tableView1->setColumnWidth(1, sizeView.width()/4);
    tableView1->setColumnWidth(2, sizeView.width()/4);
    tableView1->setColumnWidth(3, sizeView.width()/4);
    //tableView1->resizeColumnsToContents();
    tableView1->show();
}
void TableData::pushButton_clicked()
{
        QSqlQuery query;
        QDateTime *dt = new QDateTime();

        double utc_time = dt->currentMSecsSinceEpoch()/1000;
        query.exec("INSERT INTO Kelvin_Data ([Температура],[Уровень излучения],[Дата],[Время],TimeUTC) VALUES (425, 30, date(), time(),"+QString::number(utc_time, 'f',3)+");");
        qDebug () << query.lastError().text();
}
void TableData::resizeEvent(QResizeEvent *event)
{
    QSize sizeView = tableView1->size();

    tableView1->setColumnWidth(0, sizeView.width()/4);
    tableView1->setColumnWidth(1, sizeView.width()/4);
    tableView1->setColumnWidth(2, sizeView.width()/4);
    tableView1->setColumnWidth(3, sizeView.width()/4);
    tableView1->show();
}
void TableData::saveToCSV()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QString date_Format = dateEdit1->date().toString("yyyy-MM-dd");
    QString date_Format2 = dateEdit2->date().toString("yyyy-MM-dd");

    getData(model, date_Format, date_Format2);

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
    tr("CSV (*.csv);;"));

    saveTableToCSV(model, fileName, true);
}

void TableData::saveTableToCSV(QSqlQueryModel *md, QString fileName, bool messageOn)
{
        if (fileName != "") {           
            QFile file(fileName);
            if (!file.open(QIODevice::WriteOnly)) {
                if(messageOn)
                   QMessageBox::information(this, "", "Ошибка при создание файла CSV!!!", QMessageBox::Ok);
            } else {
               QTextStream ts(&file);
               QStringList strList;
               strList << "\" \"";

               for(int c=0; c < md->columnCount(); ++c)
                   strList << "\""+md->headerData(c, Qt::Horizontal).toString()+"\"";

               ts << strList.join(";")+"\n";

               while(md->canFetchMore()){
                   md->fetchMore();
               }

               for(int r=0; r < md->rowCount(); ++r)
               {
                   strList.clear();
                   strList << "\""+md->headerData(r, Qt::Vertical).toString()+"\"";
                   for(int c=0; c < md->columnCount(); ++c)
                   {
                       strList << "\""+md->data(md->index(r, c), Qt::DisplayRole).toString()+"\"";
                   }
                   ts << strList.join(";")+"\n";
               }
                file.close();
                if(messageOn)
                   QMessageBox::information(this, "", "CSV файл создан успешно!!!", QMessageBox::Ok);
            }
        }
}
