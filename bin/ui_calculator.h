/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculator
{
public:
    QWidget *centralwidget;
    QLabel *display;
    QPushButton *btnClear;
    QPushButton *btnClearExpr;
    QPushButton *btnSquare;
    QPushButton *btnDiv;
    QPushButton *btnNum9;
    QPushButton *btnNum7;
    QPushButton *btnNum8;
    QPushButton *btnMultiply;
    QPushButton *btnNum6;
    QPushButton *btnNum4;
    QPushButton *btnNum5;
    QPushButton *btnNum1;
    QPushButton *btnNum2;
    QPushButton *btnNum3;
    QPushButton *btnSub;
    QPushButton *btnSum;
    QPushButton *btnNum00;
    QPushButton *btnNum0;
    QPushButton *btnPercent;
    QPushButton *btnDecimal;
    QPushButton *btnMC;
    QPushButton *btnMR;
    QPushButton *btnSin;
    QPushButton *btnCos;
    QPushButton *btnTan;
    QPushButton *btnSqrt;
    QPushButton *btnOpen;
    QPushButton *btnAns;
    QPushButton *btnClose;
    QPushButton *btnAdd;

    void setupUi(QMainWindow *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName(QString::fromUtf8("Calculator"));
        Calculator->resize(428, 500);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(114, 27, 101, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 213, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(255, 191, 63, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(127, 85, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(170, 113, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        QBrush brush7(QColor(255, 212, 127, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        QBrush brush9(QColor(0, 0, 0, 128));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        QBrush brush10(QColor(255, 170, 0, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        Calculator->setPalette(palette);
        QIcon icon;
        icon.addFile(QString::fromUtf8("Calculator.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Calculator->setWindowIcon(icon);
        Calculator->setAutoFillBackground(false);
        Calculator->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"	background-color: #721b65;\n"
"}"));
        centralwidget = new QWidget(Calculator);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        display = new QLabel(centralwidget);
        display->setObjectName(QString::fromUtf8("display"));
        display->setGeometry(QRect(10, 12, 408, 75));
        QFont font;
        font.setFamily(QString::fromUtf8("Roboto"));
        font.setPointSize(32);
        font.setBold(true);
        font.setWeight(75);
        display->setFont(font);
        display->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"	border: 3px solid transparent;\n"
"	background-color: #f9fcfb;\n"
"}"));
        btnClear = new QPushButton(centralwidget);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        btnClear->setGeometry(QRect(92, 182, 80, 60));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Roboto"));
        font1.setPointSize(24);
        btnClear->setFont(font1);
        btnClear->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 216, 104);"));
        btnClearExpr = new QPushButton(centralwidget);
        btnClearExpr->setObjectName(QString::fromUtf8("btnClearExpr"));
        btnClearExpr->setGeometry(QRect(10, 182, 80, 60));
        btnClearExpr->setFont(font1);
        btnClearExpr->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 216, 104);"));
        btnSquare = new QPushButton(centralwidget);
        btnSquare->setObjectName(QString::fromUtf8("btnSquare"));
        btnSquare->setGeometry(QRect(256, 182, 80, 60));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Roboto Light"));
        font2.setPointSize(22);
        btnSquare->setFont(font2);
        btnSquare->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 97, 90);"));
        btnDiv = new QPushButton(centralwidget);
        btnDiv->setObjectName(QString::fromUtf8("btnDiv"));
        btnDiv->setGeometry(QRect(338, 305, 80, 60));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Roboto Light"));
        font3.setPointSize(26);
        btnDiv->setFont(font3);
        btnDiv->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 97, 90);"));
        btnNum9 = new QPushButton(centralwidget);
        btnNum9->setObjectName(QString::fromUtf8("btnNum9"));
        btnNum9->setGeometry(QRect(174, 244, 80, 60));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Roboto Black"));
        font4.setPointSize(18);
        font4.setBold(true);
        font4.setWeight(75);
        btnNum9->setFont(font4);
        btnNum9->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 13, 87);\n"
"color: #ffffff;"));
        btnNum7 = new QPushButton(centralwidget);
        btnNum7->setObjectName(QString::fromUtf8("btnNum7"));
        btnNum7->setGeometry(QRect(10, 244, 80, 60));
        btnNum7->setFont(font4);
        btnNum7->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 13, 87);\n"
"color: #ffffff;"));
        btnNum8 = new QPushButton(centralwidget);
        btnNum8->setObjectName(QString::fromUtf8("btnNum8"));
        btnNum8->setGeometry(QRect(92, 244, 80, 60));
        btnNum8->setFont(font4);
        btnNum8->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 13, 87);\n"
"color: #ffffff;"));
        btnMultiply = new QPushButton(centralwidget);
        btnMultiply->setObjectName(QString::fromUtf8("btnMultiply"));
        btnMultiply->setGeometry(QRect(256, 306, 80, 60));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Roboto Light"));
        font5.setPointSize(24);
        btnMultiply->setFont(font5);
        btnMultiply->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 97, 90);"));
        btnNum6 = new QPushButton(centralwidget);
        btnNum6->setObjectName(QString::fromUtf8("btnNum6"));
        btnNum6->setGeometry(QRect(174, 306, 80, 60));
        btnNum6->setFont(font4);
        btnNum6->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 13, 87);\n"
"color: #ffffff;"));
        btnNum4 = new QPushButton(centralwidget);
        btnNum4->setObjectName(QString::fromUtf8("btnNum4"));
        btnNum4->setGeometry(QRect(10, 306, 80, 60));
        btnNum4->setFont(font4);
        btnNum4->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 13, 87);\n"
"color: #ffffff;background-color: rgb(184, 13, 87);"));
        btnNum5 = new QPushButton(centralwidget);
        btnNum5->setObjectName(QString::fromUtf8("btnNum5"));
        btnNum5->setGeometry(QRect(92, 306, 80, 60));
        btnNum5->setFont(font4);
        btnNum5->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 13, 87);\n"
"color: #ffffff;"));
        btnNum1 = new QPushButton(centralwidget);
        btnNum1->setObjectName(QString::fromUtf8("btnNum1"));
        btnNum1->setGeometry(QRect(10, 368, 80, 60));
        btnNum1->setFont(font4);
        btnNum1->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 13, 87);\n"
"color: #ffffff;"));
        btnNum2 = new QPushButton(centralwidget);
        btnNum2->setObjectName(QString::fromUtf8("btnNum2"));
        btnNum2->setGeometry(QRect(92, 368, 80, 60));
        btnNum2->setFont(font4);
        btnNum2->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 13, 87);\n"
"color: #ffffff;"));
        btnNum3 = new QPushButton(centralwidget);
        btnNum3->setObjectName(QString::fromUtf8("btnNum3"));
        btnNum3->setGeometry(QRect(174, 368, 80, 60));
        btnNum3->setFont(font4);
        btnNum3->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 13, 87);\n"
"color: #ffffff;"));
        btnSub = new QPushButton(centralwidget);
        btnSub->setObjectName(QString::fromUtf8("btnSub"));
        btnSub->setGeometry(QRect(338, 368, 80, 60));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Roboto Light"));
        font6.setPointSize(32);
        btnSub->setFont(font6);
        btnSub->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 97, 90);"));
        btnSum = new QPushButton(centralwidget);
        btnSum->setObjectName(QString::fromUtf8("btnSum"));
        btnSum->setGeometry(QRect(256, 430, 80, 60));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Roboto Light"));
        font7.setPointSize(30);
        btnSum->setFont(font7);
        btnSum->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 216, 104);"));
        btnNum00 = new QPushButton(centralwidget);
        btnNum00->setObjectName(QString::fromUtf8("btnNum00"));
        btnNum00->setGeometry(QRect(92, 430, 80, 60));
        btnNum00->setFont(font4);
        btnNum00->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 13, 87);\n"
"color: #ffffff;"));
        btnNum0 = new QPushButton(centralwidget);
        btnNum0->setObjectName(QString::fromUtf8("btnNum0"));
        btnNum0->setGeometry(QRect(10, 430, 80, 60));
        btnNum0->setFont(font4);
        btnNum0->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 13, 87);\n"
"color: #ffffff;"));
        btnPercent = new QPushButton(centralwidget);
        btnPercent->setObjectName(QString::fromUtf8("btnPercent"));
        btnPercent->setGeometry(QRect(174, 182, 80, 60));
        QFont font8;
        font8.setFamily(QString::fromUtf8("Roboto"));
        font8.setPointSize(22);
        btnPercent->setFont(font8);
        btnPercent->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 97, 90);"));
        btnDecimal = new QPushButton(centralwidget);
        btnDecimal->setObjectName(QString::fromUtf8("btnDecimal"));
        btnDecimal->setGeometry(QRect(174, 430, 80, 60));
        QFont font9;
        font9.setFamily(QString::fromUtf8("Roboto Black"));
        font9.setPointSize(24);
        font9.setBold(true);
        font9.setWeight(75);
        btnDecimal->setFont(font9);
        btnDecimal->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 13, 87);\n"
"color: #ffffff;"));
        btnMC = new QPushButton(centralwidget);
        btnMC->setObjectName(QString::fromUtf8("btnMC"));
        btnMC->setGeometry(QRect(338, 120, 80, 60));
        QFont font10;
        font10.setFamily(QString::fromUtf8("Roboto"));
        font10.setPointSize(18);
        btnMC->setFont(font10);
        btnMC->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 97, 90);"));
        btnMR = new QPushButton(centralwidget);
        btnMR->setObjectName(QString::fromUtf8("btnMR"));
        btnMR->setGeometry(QRect(256, 120, 80, 60));
        btnMR->setFont(font10);
        btnMR->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 97, 90);"));
        btnSin = new QPushButton(centralwidget);
        btnSin->setObjectName(QString::fromUtf8("btnSin"));
        btnSin->setGeometry(QRect(10, 120, 80, 60));
        QFont font11;
        font11.setFamily(QString::fromUtf8("Roboto"));
        font11.setPointSize(14);
        font11.setKerning(true);
        btnSin->setFont(font11);
        btnSin->setAutoFillBackground(false);
        btnSin->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 97, 90);"));
        btnCos = new QPushButton(centralwidget);
        btnCos->setObjectName(QString::fromUtf8("btnCos"));
        btnCos->setGeometry(QRect(174, 120, 80, 60));
        QFont font12;
        font12.setFamily(QString::fromUtf8("Roboto"));
        font12.setPointSize(14);
        btnCos->setFont(font12);
        btnCos->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 97, 90);"));
        btnTan = new QPushButton(centralwidget);
        btnTan->setObjectName(QString::fromUtf8("btnTan"));
        btnTan->setGeometry(QRect(92, 120, 80, 60));
        btnTan->setFont(font12);
        btnTan->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 97, 90);"));
        btnSqrt = new QPushButton(centralwidget);
        btnSqrt->setObjectName(QString::fromUtf8("btnSqrt"));
        btnSqrt->setGeometry(QRect(338, 182, 80, 60));
        btnSqrt->setFont(font5);
        btnSqrt->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 97, 90);"));
        btnOpen = new QPushButton(centralwidget);
        btnOpen->setObjectName(QString::fromUtf8("btnOpen"));
        btnOpen->setGeometry(QRect(256, 244, 80, 60));
        QFont font13;
        font13.setFamily(QString::fromUtf8("Roboto"));
        font13.setPointSize(20);
        btnOpen->setFont(font13);
        btnOpen->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 97, 90);"));
        btnAns = new QPushButton(centralwidget);
        btnAns->setObjectName(QString::fromUtf8("btnAns"));
        btnAns->setGeometry(QRect(338, 430, 80, 60));
        btnAns->setFont(font13);
        btnAns->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 216, 104);"));
        btnClose = new QPushButton(centralwidget);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(338, 244, 80, 60));
        btnClose->setFont(font13);
        btnClose->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 97, 90);"));
        btnAdd = new QPushButton(centralwidget);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setGeometry(QRect(256, 368, 80, 60));
        btnAdd->setFont(font7);
        btnAdd->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 97, 90);"));
        Calculator->setCentralWidget(centralwidget);

        retranslateUi(Calculator);

        QMetaObject::connectSlotsByName(Calculator);
    } // setupUi

    void retranslateUi(QMainWindow *Calculator)
    {
        Calculator->setWindowTitle(QCoreApplication::translate("Calculator", "Calculator", nullptr));
        display->setText(QString());
        btnClear->setText(QCoreApplication::translate("Calculator", "C", nullptr));
#if QT_CONFIG(shortcut)
        btnClear->setShortcut(QCoreApplication::translate("Calculator", "Backspace", nullptr));
#endif // QT_CONFIG(shortcut)
        btnClearExpr->setText(QCoreApplication::translate("Calculator", "CE", nullptr));
#if QT_CONFIG(shortcut)
        btnClearExpr->setShortcut(QCoreApplication::translate("Calculator", "Ctrl+Backspace", nullptr));
#endif // QT_CONFIG(shortcut)
        btnSquare->setText(QCoreApplication::translate("Calculator", "x\302\262", nullptr));
#if QT_CONFIG(shortcut)
        btnSquare->setShortcut(QCoreApplication::translate("Calculator", "^", nullptr));
#endif // QT_CONFIG(shortcut)
        btnDiv->setText(QCoreApplication::translate("Calculator", "\303\267", nullptr));
#if QT_CONFIG(shortcut)
        btnDiv->setShortcut(QCoreApplication::translate("Calculator", "/", nullptr));
#endif // QT_CONFIG(shortcut)
        btnNum9->setText(QCoreApplication::translate("Calculator", "9", nullptr));
#if QT_CONFIG(shortcut)
        btnNum9->setShortcut(QCoreApplication::translate("Calculator", "9", nullptr));
#endif // QT_CONFIG(shortcut)
        btnNum7->setText(QCoreApplication::translate("Calculator", "7", nullptr));
#if QT_CONFIG(shortcut)
        btnNum7->setShortcut(QCoreApplication::translate("Calculator", "7", nullptr));
#endif // QT_CONFIG(shortcut)
        btnNum8->setText(QCoreApplication::translate("Calculator", "8", nullptr));
#if QT_CONFIG(shortcut)
        btnNum8->setShortcut(QCoreApplication::translate("Calculator", "8", nullptr));
#endif // QT_CONFIG(shortcut)
        btnMultiply->setText(QCoreApplication::translate("Calculator", "x", nullptr));
#if QT_CONFIG(shortcut)
        btnMultiply->setShortcut(QCoreApplication::translate("Calculator", "*", nullptr));
#endif // QT_CONFIG(shortcut)
        btnNum6->setText(QCoreApplication::translate("Calculator", "6", nullptr));
#if QT_CONFIG(shortcut)
        btnNum6->setShortcut(QCoreApplication::translate("Calculator", "6", nullptr));
#endif // QT_CONFIG(shortcut)
        btnNum4->setText(QCoreApplication::translate("Calculator", "4", nullptr));
#if QT_CONFIG(shortcut)
        btnNum4->setShortcut(QCoreApplication::translate("Calculator", "4", nullptr));
#endif // QT_CONFIG(shortcut)
        btnNum5->setText(QCoreApplication::translate("Calculator", "5", nullptr));
#if QT_CONFIG(shortcut)
        btnNum5->setShortcut(QCoreApplication::translate("Calculator", "5", nullptr));
#endif // QT_CONFIG(shortcut)
        btnNum1->setText(QCoreApplication::translate("Calculator", "1", nullptr));
#if QT_CONFIG(shortcut)
        btnNum1->setShortcut(QCoreApplication::translate("Calculator", "1", nullptr));
#endif // QT_CONFIG(shortcut)
        btnNum2->setText(QCoreApplication::translate("Calculator", "2", nullptr));
#if QT_CONFIG(shortcut)
        btnNum2->setShortcut(QCoreApplication::translate("Calculator", "2", nullptr));
#endif // QT_CONFIG(shortcut)
        btnNum3->setText(QCoreApplication::translate("Calculator", "3", nullptr));
#if QT_CONFIG(shortcut)
        btnNum3->setShortcut(QCoreApplication::translate("Calculator", "3", nullptr));
#endif // QT_CONFIG(shortcut)
        btnSub->setText(QCoreApplication::translate("Calculator", "-", nullptr));
#if QT_CONFIG(shortcut)
        btnSub->setShortcut(QCoreApplication::translate("Calculator", "-", nullptr));
#endif // QT_CONFIG(shortcut)
        btnSum->setText(QCoreApplication::translate("Calculator", "=", nullptr));
#if QT_CONFIG(shortcut)
        btnSum->setShortcut(QCoreApplication::translate("Calculator", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        btnNum00->setText(QCoreApplication::translate("Calculator", "00", nullptr));
        btnNum0->setText(QCoreApplication::translate("Calculator", "0", nullptr));
#if QT_CONFIG(shortcut)
        btnNum0->setShortcut(QCoreApplication::translate("Calculator", "0", nullptr));
#endif // QT_CONFIG(shortcut)
        btnPercent->setText(QCoreApplication::translate("Calculator", "%", nullptr));
#if QT_CONFIG(shortcut)
        btnPercent->setShortcut(QCoreApplication::translate("Calculator", "%", nullptr));
#endif // QT_CONFIG(shortcut)
        btnDecimal->setText(QCoreApplication::translate("Calculator", ".", nullptr));
#if QT_CONFIG(shortcut)
        btnDecimal->setShortcut(QCoreApplication::translate("Calculator", ".", nullptr));
#endif // QT_CONFIG(shortcut)
        btnMC->setText(QCoreApplication::translate("Calculator", "MC", nullptr));
#if QT_CONFIG(shortcut)
        btnMC->setShortcut(QCoreApplication::translate("Calculator", "S", nullptr));
#endif // QT_CONFIG(shortcut)
        btnMR->setText(QCoreApplication::translate("Calculator", "MR", nullptr));
#if QT_CONFIG(shortcut)
        btnMR->setShortcut(QCoreApplication::translate("Calculator", "R", nullptr));
#endif // QT_CONFIG(shortcut)
        btnSin->setText(QCoreApplication::translate("Calculator", "SIN", nullptr));
#if QT_CONFIG(shortcut)
        btnSin->setShortcut(QCoreApplication::translate("Calculator", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        btnCos->setText(QCoreApplication::translate("Calculator", "COS", nullptr));
#if QT_CONFIG(shortcut)
        btnCos->setShortcut(QCoreApplication::translate("Calculator", "F3", nullptr));
#endif // QT_CONFIG(shortcut)
        btnTan->setText(QCoreApplication::translate("Calculator", "TAN", nullptr));
#if QT_CONFIG(shortcut)
        btnTan->setShortcut(QCoreApplication::translate("Calculator", "F2", nullptr));
#endif // QT_CONFIG(shortcut)
        btnSqrt->setText(QCoreApplication::translate("Calculator", "\342\210\232", nullptr));
#if QT_CONFIG(shortcut)
        btnSqrt->setShortcut(QCoreApplication::translate("Calculator", "~", nullptr));
#endif // QT_CONFIG(shortcut)
        btnOpen->setText(QCoreApplication::translate("Calculator", "(", nullptr));
#if QT_CONFIG(shortcut)
        btnOpen->setShortcut(QCoreApplication::translate("Calculator", "(", nullptr));
#endif // QT_CONFIG(shortcut)
        btnAns->setText(QCoreApplication::translate("Calculator", "ANS", nullptr));
#if QT_CONFIG(shortcut)
        btnAns->setShortcut(QCoreApplication::translate("Calculator", "F4", nullptr));
#endif // QT_CONFIG(shortcut)
        btnClose->setText(QCoreApplication::translate("Calculator", ")", nullptr));
#if QT_CONFIG(shortcut)
        btnClose->setShortcut(QCoreApplication::translate("Calculator", ")", nullptr));
#endif // QT_CONFIG(shortcut)
        btnAdd->setText(QCoreApplication::translate("Calculator", "+", nullptr));
#if QT_CONFIG(shortcut)
        btnAdd->setShortcut(QCoreApplication::translate("Calculator", "+", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
