#ifndef CHARTTEMP_H
#define CHARTTEMP_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class ChartTemp;
}

class ChartTemp : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChartTemp(QWidget *parent = nullptr);
    ~ChartTemp();
    void Chart_Paint();

private slots:
    void on_OutData_clicked();

private:
    Ui::ChartTemp *ui;
};

#endif // CHARTTEMP_H
