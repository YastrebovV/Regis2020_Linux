#ifndef DATABASECLASS_H
#define DATABASECLASS_H

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlError>

class DataBaseClass
{
public:
    DataBaseClass();
    bool conn_DB(QSqlDatabase *db, QString path);
    void dis_conn_DB(QSqlDatabase *db);

};

#endif // DATABASECLASS_H
