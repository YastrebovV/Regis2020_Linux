#include "databaseclass.h"

DataBaseClass::DataBaseClass()
{

}
bool DataBaseClass::conn_DB(QSqlDatabase *db, QString path)
{
   *db = QSqlDatabase::addDatabase("QSQLITE");
   db->setDatabaseName(path +"/Temp_DB.sqlite3");

   if (db->open()) {
       return true;
   }else return  false;
}

void DataBaseClass::dis_conn_DB(QSqlDatabase *db)
{
   db->close();
}
