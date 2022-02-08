#include "savetoflashcard.h"

SaveToFlashCard::SaveToFlashCard()
{

}

void SaveToFlashCard::saveDataTiFlash()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    QDir flashDir;
    flashDir.setFilter(QDir::Dirs);
    flashDir.setPath("/media/pi");
    QFileInfoList listDir = flashDir.entryInfoList();

    if(listDir.size()==3 && !flashConected){
        flashConected =true;
        QFileInfo dirInfo = listDir.at(2);
        QString date = ExWorkingFiles.readFromFile(dirInfo.filePath() +"/Set_backUp.txt");
        ExTableData. getData(model, date, date);
        ExTableData.saveTableToCSV(model, dirInfo.filePath() +"/backUp.csv", false);
    }else if(listDir.size()!=3){
        flashConected = false;
    }

}
