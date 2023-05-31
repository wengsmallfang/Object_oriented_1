/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <bqgraphicsview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *circleBtn;
    QPushButton *ellipseBtn;
    QPushButton *conCircleBtn;
    QPushButton *pieBtn;
    QPushButton *chordBtn;
    QPushButton *squareBtn;
    QPushButton *rectangleBtn;
    QPushButton *polygonBtn;
    QPushButton *rnRecBtn;
    QPushButton *roundRecBtn;
    QPushButton *clearBtn;
    QPushButton *saveBtn;
    QPushButton *loadBtn;
    BQGraphicsView *graphicsView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1024, 768);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 91, 731));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        circleBtn = new QPushButton(verticalLayoutWidget);
        circleBtn->setObjectName(QString::fromUtf8("circleBtn"));

        verticalLayout->addWidget(circleBtn);

        ellipseBtn = new QPushButton(verticalLayoutWidget);
        ellipseBtn->setObjectName(QString::fromUtf8("ellipseBtn"));

        verticalLayout->addWidget(ellipseBtn);

        conCircleBtn = new QPushButton(verticalLayoutWidget);
        conCircleBtn->setObjectName(QString::fromUtf8("conCircleBtn"));

        verticalLayout->addWidget(conCircleBtn);

        pieBtn = new QPushButton(verticalLayoutWidget);
        pieBtn->setObjectName(QString::fromUtf8("pieBtn"));

        verticalLayout->addWidget(pieBtn);

        chordBtn = new QPushButton(verticalLayoutWidget);
        chordBtn->setObjectName(QString::fromUtf8("chordBtn"));

        verticalLayout->addWidget(chordBtn);

        squareBtn = new QPushButton(verticalLayoutWidget);
        squareBtn->setObjectName(QString::fromUtf8("squareBtn"));

        verticalLayout->addWidget(squareBtn);

        rectangleBtn = new QPushButton(verticalLayoutWidget);
        rectangleBtn->setObjectName(QString::fromUtf8("rectangleBtn"));

        verticalLayout->addWidget(rectangleBtn);

        polygonBtn = new QPushButton(verticalLayoutWidget);
        polygonBtn->setObjectName(QString::fromUtf8("polygonBtn"));

        verticalLayout->addWidget(polygonBtn);

        rnRecBtn = new QPushButton(verticalLayoutWidget);
        rnRecBtn->setObjectName(QString::fromUtf8("rnRecBtn"));

        verticalLayout->addWidget(rnRecBtn);

        roundRecBtn = new QPushButton(verticalLayoutWidget);
        roundRecBtn->setObjectName(QString::fromUtf8("roundRecBtn"));

        verticalLayout->addWidget(roundRecBtn);

        clearBtn = new QPushButton(verticalLayoutWidget);
        clearBtn->setObjectName(QString::fromUtf8("clearBtn"));

        verticalLayout->addWidget(clearBtn);

        saveBtn = new QPushButton(verticalLayoutWidget);
        saveBtn->setObjectName(QString::fromUtf8("saveBtn"));

        verticalLayout->addWidget(saveBtn);

        loadBtn = new QPushButton(verticalLayoutWidget);
        loadBtn->setObjectName(QString::fromUtf8("loadBtn"));

        verticalLayout->addWidget(loadBtn);

        graphicsView = new BQGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(140, 20, 861, 731));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        circleBtn->setText(QCoreApplication::translate("MainWindow", "\345\234\206", nullptr));
        ellipseBtn->setText(QCoreApplication::translate("MainWindow", "\346\244\255\345\234\206", nullptr));
        conCircleBtn->setText(QCoreApplication::translate("MainWindow", "\345\220\214\345\277\203\345\234\206", nullptr));
        pieBtn->setText(QCoreApplication::translate("MainWindow", "\351\245\274", nullptr));
        chordBtn->setText(QCoreApplication::translate("MainWindow", "\345\222\214\345\274\246", nullptr));
        squareBtn->setText(QCoreApplication::translate("MainWindow", "\346\255\243\346\226\271\345\275\242", nullptr));
        rectangleBtn->setText(QCoreApplication::translate("MainWindow", "\347\237\251\345\275\242", nullptr));
        polygonBtn->setText(QCoreApplication::translate("MainWindow", "\345\244\232\350\276\271\345\275\242", nullptr));
        rnRecBtn->setText(QCoreApplication::translate("MainWindow", "\345\234\206\347\253\257\347\237\251\345\275\242", nullptr));
        roundRecBtn->setText(QCoreApplication::translate("MainWindow", "\345\234\206\350\247\222\347\237\251\345\275\242", nullptr));
        clearBtn->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
        saveBtn->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        loadBtn->setText(QCoreApplication::translate("MainWindow", "\345\212\240\350\275\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
