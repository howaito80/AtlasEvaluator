/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *inputBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *srcDirInput;
    QLineEdit *srcDir;
    QPushButton *srcDirBtn;
    QGroupBox *evaBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QListWidget *quaList;
    QLabel *quaNum;
    QLabel *quaNum_2;
    QPushButton *quaOpenBtn;
    QPushButton *quaDirBtn;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QListWidget *unquaList;
    QLabel *unquaNum;
    QPushButton *unquaOpenBtn;
    QPushButton *unquaDirBtn;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QListWidget *failList;
    QLabel *label_4;
    QLabel *failNum;
    QPushButton *failOpenBtn;
    QLabel *freshLabel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QSlider *thresSlider;
    QSpinBox *thresSpin;
    QPushButton *evaBtn;
    QLabel *label_5;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(709, 633);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        inputBox = new QGroupBox(centralWidget);
        inputBox->setObjectName(QStringLiteral("inputBox"));
        inputBox->setGeometry(QRect(40, 20, 631, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(9);
        inputBox->setFont(font);
        inputBox->setAutoFillBackground(false);
        verticalLayoutWidget = new QWidget(inputBox);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 30, 611, 41));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        srcDirInput = new QHBoxLayout();
        srcDirInput->setSpacing(7);
        srcDirInput->setObjectName(QStringLiteral("srcDirInput"));
        srcDirInput->setSizeConstraint(QLayout::SetNoConstraint);
        srcDir = new QLineEdit(verticalLayoutWidget);
        srcDir->setObjectName(QStringLiteral("srcDir"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(srcDir->sizePolicy().hasHeightForWidth());
        srcDir->setSizePolicy(sizePolicy);

        srcDirInput->addWidget(srcDir);

        srcDirBtn = new QPushButton(verticalLayoutWidget);
        srcDirBtn->setObjectName(QStringLiteral("srcDirBtn"));
        srcDirBtn->setCheckable(false);

        srcDirInput->addWidget(srcDirBtn);


        verticalLayout->addLayout(srcDirInput);

        evaBox = new QGroupBox(centralWidget);
        evaBox->setObjectName(QStringLiteral("evaBox"));
        evaBox->setGeometry(QRect(40, 190, 631, 381));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        evaBox->setFont(font1);
        gridLayoutWidget = new QWidget(evaBox);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 40, 191, 291));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        quaList = new QListWidget(gridLayoutWidget);
        quaList->setObjectName(QStringLiteral("quaList"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(8);
        quaList->setFont(font2);

        gridLayout->addWidget(quaList, 1, 0, 1, 3);

        quaNum = new QLabel(gridLayoutWidget);
        quaNum->setObjectName(QStringLiteral("quaNum"));
        quaNum->setFont(font1);

        gridLayout->addWidget(quaNum, 0, 1, 1, 1);

        quaNum_2 = new QLabel(evaBox);
        quaNum_2->setObjectName(QStringLiteral("quaNum_2"));
        quaNum_2->setGeometry(QRect(310, 310, 14, 29));
        quaNum_2->setFont(font1);
        quaOpenBtn = new QPushButton(evaBox);
        quaOpenBtn->setObjectName(QStringLiteral("quaOpenBtn"));
        quaOpenBtn->setGeometry(QRect(60, 330, 41, 29));
        quaOpenBtn->setFont(font1);
        quaDirBtn = new QPushButton(evaBox);
        quaDirBtn->setObjectName(QStringLiteral("quaDirBtn"));
        quaDirBtn->setGeometry(QRect(100, 330, 101, 29));
        quaDirBtn->setFont(font1);
        gridLayoutWidget_2 = new QWidget(evaBox);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(220, 40, 191, 291));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        unquaList = new QListWidget(gridLayoutWidget_2);
        unquaList->setObjectName(QStringLiteral("unquaList"));
        unquaList->setFont(font2);

        gridLayout_2->addWidget(unquaList, 1, 0, 1, 3);

        unquaNum = new QLabel(gridLayoutWidget_2);
        unquaNum->setObjectName(QStringLiteral("unquaNum"));
        unquaNum->setFont(font1);

        gridLayout_2->addWidget(unquaNum, 0, 1, 1, 1);

        unquaOpenBtn = new QPushButton(evaBox);
        unquaOpenBtn->setObjectName(QStringLiteral("unquaOpenBtn"));
        unquaOpenBtn->setGeometry(QRect(270, 330, 41, 29));
        unquaOpenBtn->setFont(font1);
        unquaDirBtn = new QPushButton(evaBox);
        unquaDirBtn->setObjectName(QStringLiteral("unquaDirBtn"));
        unquaDirBtn->setGeometry(QRect(310, 330, 101, 29));
        unquaDirBtn->setFont(font1);
        gridLayoutWidget_3 = new QWidget(evaBox);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(430, 40, 191, 291));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        failList = new QListWidget(gridLayoutWidget_3);
        failList->setObjectName(QStringLiteral("failList"));
        failList->setFont(font2);

        gridLayout_3->addWidget(failList, 1, 0, 1, 3);

        label_4 = new QLabel(gridLayoutWidget_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        failNum = new QLabel(gridLayoutWidget_3);
        failNum->setObjectName(QStringLiteral("failNum"));
        failNum->setFont(font1);

        gridLayout_3->addWidget(failNum, 0, 1, 1, 1);

        failOpenBtn = new QPushButton(evaBox);
        failOpenBtn->setObjectName(QStringLiteral("failOpenBtn"));
        failOpenBtn->setGeometry(QRect(520, 330, 101, 29));
        failOpenBtn->setFont(font1);
        freshLabel = new QLabel(centralWidget);
        freshLabel->setObjectName(QStringLiteral("freshLabel"));
        freshLabel->setGeometry(QRect(500, 570, 231, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        freshLabel->setFont(font3);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(140, 120, 521, 51));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        thresSlider = new QSlider(layoutWidget);
        thresSlider->setObjectName(QStringLiteral("thresSlider"));
        thresSlider->setPageStep(1);
        thresSlider->setValue(50);
        thresSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(thresSlider);

        thresSpin = new QSpinBox(layoutWidget);
        thresSpin->setObjectName(QStringLiteral("thresSpin"));
        thresSpin->setFont(font1);
        thresSpin->setValue(50);

        horizontalLayout_5->addWidget(thresSpin);

        evaBtn = new QPushButton(layoutWidget);
        evaBtn->setObjectName(QStringLiteral("evaBtn"));
        evaBtn->setFont(font1);

        horizontalLayout_5->addWidget(evaBtn);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 130, 71, 26));
        label_5->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 709, 25));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        inputBox->setTitle(QApplication::translate("MainWindow", "\350\276\223\345\205\245", Q_NULLPTR));
        srcDirBtn->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266\345\244\271..", Q_NULLPTR));
        evaBox->setTitle(QApplication::translate("MainWindow", "\347\273\223\346\236\234", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\345\220\210\346\240\274", Q_NULLPTR));
        quaNum->setText(QString());
        quaNum_2->setText(QString());
        quaOpenBtn->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213", Q_NULLPTR));
        quaDirBtn->setText(QApplication::translate("MainWindow", "\346\211\200\345\234\250\346\226\207\344\273\266\345\244\271", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\344\270\215\345\220\210\346\240\274", Q_NULLPTR));
        unquaNum->setText(QString());
        unquaOpenBtn->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213", Q_NULLPTR));
        unquaDirBtn->setText(QApplication::translate("MainWindow", "\346\211\200\345\234\250\346\226\207\344\273\266\345\244\271", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\346\223\215\344\275\234\345\244\261\350\264\245", Q_NULLPTR));
        failNum->setText(QString());
        failOpenBtn->setText(QApplication::translate("MainWindow", "\346\211\200\345\234\250\346\226\207\344\273\266\345\244\271", Q_NULLPTR));
        freshLabel->setText(QApplication::translate("MainWindow", "\346\255\243\345\234\250\345\210\267\346\226\260\347\273\223\346\236\234...", Q_NULLPTR));
        evaBtn->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\347\255\233\351\200\211", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\351\230\210\345\200\274\357\274\210%\357\274\211", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
