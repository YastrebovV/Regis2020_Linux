#ifndef TABLEDATA_H
#define TABLEDATA_H

#include <QMainWindow>
#include <QDebug>
#include "databaseclass.h"
#include <QDateTime>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QDateEdit>
#include <QTableView>
#include <QCheckBox>
#include <QDesktopWidget>
#include <QResizeEvent>

namespace Ui {
class TableData;
}

class TableData : public QMainWindow
{
    Q_OBJECT

public:
    explicit TableData(QWidget *parent = nullptr);
    ~TableData();

private slots:
    void outData_clicked();
    void pushButton_clicked();
    void saveToCSV();
public:
    void saveTableToCSV(QSqlQueryModel *md,  QString fileName, bool messageOn);
    void getData(QSqlQueryModel *md, QString date1, QString date2);

private:
    Ui::TableData *ui;
    QGridLayout *gridLayout;
    QPushButton *but_Date;
    QPushButton *but_tEMP;
    QPushButton *but_Save_CSV;
    QLabel *label1;
    QDateEdit *dateEdit1;
    QLabel *label2;
    QDateEdit *dateEdit2;
    QTableView *tableView1;
    QCheckBox *checkBox1;
    void resizeEvent(QResizeEvent *event);
    //void saveTableToCSV(QTableView *tb);

};

#endif // TABLEDATA_H
