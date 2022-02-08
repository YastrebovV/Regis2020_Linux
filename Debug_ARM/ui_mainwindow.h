/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *TableData_Open;
    QPushButton *ChartPaint;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(448, 347);
        MainWindow->setMaximumSize(QSize(448, 400));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TableData_Open = new QPushButton(centralWidget);
        TableData_Open->setObjectName(QStringLiteral("TableData_Open"));
        TableData_Open->setGeometry(QRect(10, 239, 431, 101));
        QFont font;
        font.setPointSize(14);
        TableData_Open->setFont(font);
        ChartPaint = new QPushButton(centralWidget);
        ChartPaint->setObjectName(QStringLiteral("ChartPaint"));
        ChartPaint->setGeometry(QRect(10, 130, 431, 101));
        ChartPaint->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 211, 17));
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(240, 20, 161, 17));
        label_2->setFont(font);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 50, 191, 17));
        label_3->setFont(font);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(240, 50, 171, 17));
        label_4->setFont(font);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 80, 191, 17));
        label_5->setFont(font);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(240, 80, 171, 17));
        label_6->setFont(font);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Regis2020", nullptr));
        TableData_Open->setText(QApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260 \321\201 \320\264\320\260\320\275\320\275\321\213\320\274\320\270", nullptr));
        ChartPaint->setText(QApplication::translate("MainWindow", "\320\223\320\240\320\220\320\244\320\230\320\232", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\241\320\236\320\241\320\242\320\236\320\257\320\235\320\230\320\225 \320\237\320\236\320\240\320\242\320\220:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\236\320\242\320\232\320\233\320\256\320\247\320\201\320\235", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\221\320\220\320\227\320\220 \320\224\320\220\320\235\320\235\320\253\320\245:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\236\320\242\320\232\320\233\320\256\320\247\320\201\320\235", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\242\320\225\320\234\320\237\320\225\320\240\320\220\320\242\320\243\320\240\320\220:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
