/********************************************************************************
** Form generated from reading UI file 'tabledata.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEDATA_H
#define UI_TABLEDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TableData
{
public:
    QWidget *centralwidget;

    void setupUi(QMainWindow *TableData)
    {
        if (TableData->objectName().isEmpty())
            TableData->setObjectName(QStringLiteral("TableData"));
        TableData->resize(612, 414);
        QFont font;
        font.setPointSize(12);
        TableData->setFont(font);
        centralwidget = new QWidget(TableData);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        TableData->setCentralWidget(centralwidget);

        retranslateUi(TableData);

        QMetaObject::connectSlotsByName(TableData);
    } // setupUi

    void retranslateUi(QMainWindow *TableData)
    {
        TableData->setWindowTitle(QApplication::translate("TableData", "\320\242\320\220\320\221\320\233\320\230\320\246\320\220 \320\241 \320\224\320\220\320\235\320\235\320\253\320\234\320\230 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TableData: public Ui_TableData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEDATA_H
