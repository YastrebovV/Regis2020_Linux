#include "workingfiles.h"

WorkingFiles::WorkingFiles()
{

}

bool WorkingFiles::createFile(QString fileName, QString text){
    bool stateOperation = false;

    QFile file(fileName);
    if(!file.exists()){
        stateOperation = writeToFile(fileName, text);
    }
    file.close();
    return stateOperation;
}

bool WorkingFiles::deleteFile(QString fileName){
          QFile file(fileName);
          file.close();
          return file.remove();
}

bool WorkingFiles::writeToFile(QString fileName, QString text)
{
    QFile file(fileName);

    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
         QTextStream writeStream(&file);
         writeStream << text;
         file.close();
         return true;
    }
    else return false;
}

QString WorkingFiles::readFromFile(QString fileName)
{
    QFile file(fileName);

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
         QTextStream stream(&file);
         QString text = stream.readAll();
         file.close();
         return text;
    }
    return "";
}
