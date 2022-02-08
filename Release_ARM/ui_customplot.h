/********************************************************************************
** Form generated from reading UI file 'customplot.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMPLOT_H
#define UI_CUSTOMPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_customplot
{
public:
    QWidget *centralwidget;

    void setupUi(QMainWindow *customplot)
    {
        if (customplot->objectName().isEmpty())
            customplot->setObjectName(QStringLiteral("customplot"));
        customplot->resize(598, 370);
        QFont font;
        font.setPointSize(12);
        customplot->setFont(font);
        centralwidget = new QWidget(customplot);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        customplot->setCentralWidget(centralwidget);

        retranslateUi(customplot);

        QMetaObject::connectSlotsByName(customplot);
    } // setupUi

    void retranslateUi(QMainWindow *customplot)
    {
        customplot->setWindowTitle(QApplication::translate("customplot", "\320\223\320\240\320\220\320\244\320\230\320\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class customplot: public Ui_customplot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMPLOT_H
