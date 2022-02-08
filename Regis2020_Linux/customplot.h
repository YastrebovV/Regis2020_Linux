#ifndef CUSTOMPLOT_H
#define CUSTOMPLOT_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QDateEdit>
#include <QGridLayout>
#include <QFile>
#include <QFileDialog>
#include "qcustomplot.h"
#include "databaseclass.h"

namespace Ui {
class customplot;
}

class customplot : public QMainWindow
{
    Q_OBJECT

public:
    explicit customplot(QWidget *parent = nullptr);
    ~customplot();

private:
    Ui::customplot *ui;
    QCustomPlot *customPlot;    // Объявляем графическое полотно
    QCPGraph *graphic;          // Объявляем график
    QPushButton *but_Date;
    QPushButton *but_Save_Graphic;
    QLabel *label1;
    QDateEdit *dateEdit1;
    QGridLayout *gridLayout;
    QLabel *label2;
    QDateEdit *dateEdit2;
    QTableView *tableView1;
    QCheckBox *checkBox1;



private slots:
    void slotRangeChanged (const QCPRange &newRange);
    void slotButClick();
    void saveGraphic(QCustomPlot *graphic);
    void saveToFile();
};

#endif // CUSTOMPLOT_H
