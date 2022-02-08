#ifndef SAVETOFLASHCARD_H
#define SAVETOFLASHCARD_H

#include "workingfiles.h"
#include "QDir"
#include "tabledata.h"

class SaveToFlashCard
{
public:
    SaveToFlashCard();
    void saveDataTiFlash();

private:
    WorkingFiles ExWorkingFiles;
    TableData ExTableData;
    bool flashConected =false;
};

#endif // SAVETOFLASHCARD_H
