#ifndef WORKINGFILES_H
#define WORKINGFILES_H

#include <QObject>
#include <QFile>
#include <QTextStream>

class WorkingFiles
{
public:
    WorkingFiles();

public:
    bool createFile(QString fileName, QString text);
    bool deleteFile(QString fileName);
    bool writeToFile(QString fileName, QString text);
    QString readFromFile(QString fileName);

};

#endif // FILESANDFOLDERS_H
