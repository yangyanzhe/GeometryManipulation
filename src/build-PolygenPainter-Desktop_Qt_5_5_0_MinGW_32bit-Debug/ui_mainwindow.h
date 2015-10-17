/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QColumnView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>
#include "mybutton.h"
#include "paintwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *toolBarWidget;
    QToolBox *toolBox;
    QWidget *color;
    QColumnView *backGround;
    MyButton *green;
    MyButton *yellow;
    MyButton *blueLight;
    MyButton *greenLight;
    MyButton *purple;
    MyButton *purpleLight;
    MyButton *red;
    QColumnView *frontGround;
    MyButton *blue;
    MyButton *orange;
    QPushButton *polygen;
    QPushButton *fill;
    QPushButton *circle;
    QPushButton *square;
    QCheckBox *checkBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *tools;
    QPushButton *rotateLeft;
    QPushButton *rotateRight;
    QPushButton *reflectDown;
    MyButton *zoom;
    QPushButton *clip;
    QPushButton *reflectRight;
    QPushButton *moveLeft;
    QPushButton *moveRight;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QPushButton *clipPolygen;
    PaintWidget *paintArea;
    QHBoxLayout *horizontalLayout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(851, 620);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        toolBarWidget = new QWidget(centralWidget);
        toolBarWidget->setObjectName(QStringLiteral("toolBarWidget"));
        toolBarWidget->setGeometry(QRect(0, 0, 171, 621));
        toolBarWidget->setStyleSheet(QLatin1String("QWidget#toolBarWidget\n"
"{\n"
"	background: url(:/images/6.jpg);\n"
"}"));
        toolBox = new QToolBox(toolBarWidget);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(10, 20, 151, 591));
        QFont font;
        font.setFamily(QStringLiteral("Buxton Sketch"));
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        toolBox->setFont(font);
        color = new QWidget();
        color->setObjectName(QStringLiteral("color"));
        color->setGeometry(QRect(0, 0, 151, 517));
        backGround = new QColumnView(color);
        backGround->setObjectName(QStringLiteral("backGround"));
        backGround->setGeometry(QRect(80, 20, 48, 48));
        green = new MyButton(color);
        green->setObjectName(QStringLiteral("green"));
        green->setGeometry(QRect(110, 160, 32, 32));
        green->setStyleSheet(QLatin1String("QPushButton#green\n"
"{\n"
"	background-image: url(:/images/green.png);\n"
"}"));
        yellow = new MyButton(color);
        yellow->setObjectName(QStringLiteral("yellow"));
        yellow->setGeometry(QRect(110, 80, 32, 32));
        yellow->setStyleSheet(QLatin1String("QPushButton#yellow\n"
"{\n"
"	background-image: url(:/images/yellow.png);\n"
"}"));
        blueLight = new MyButton(color);
        blueLight->setObjectName(QStringLiteral("blueLight"));
        blueLight->setGeometry(QRect(60, 160, 32, 32));
        blueLight->setStyleSheet(QLatin1String("QPushButton#blueLight\n"
"{\n"
"	background-image: url(:/images/blue-light.png);\n"
"}"));
        greenLight = new MyButton(color);
        greenLight->setObjectName(QStringLiteral("greenLight"));
        greenLight->setGeometry(QRect(110, 120, 32, 32));
        greenLight->setStyleSheet(QLatin1String("QPushButton#greenLight\n"
"{\n"
"	background-image: url(:/images/green-light.png);\n"
"}"));
        purple = new MyButton(color);
        purple->setObjectName(QStringLiteral("purple"));
        purple->setGeometry(QRect(10, 120, 32, 32));
        purple->setStyleSheet(QLatin1String("QPushButton#purple\n"
"{\n"
"	background-image: url(:/images/purple.png);\n"
"}"));
        purpleLight = new MyButton(color);
        purpleLight->setObjectName(QStringLiteral("purpleLight"));
        purpleLight->setGeometry(QRect(60, 120, 32, 32));
        purpleLight->setStyleSheet(QLatin1String("QPushButton#purpleLight\n"
"{\n"
"	background-image: url(:/images/purple-light.png);\n"
"}"));
        red = new MyButton(color);
        red->setObjectName(QStringLiteral("red"));
        red->setGeometry(QRect(10, 80, 32, 32));
        red->setMouseTracking(false);
        red->setStyleSheet(QLatin1String("QPushButton#red\n"
"{\n"
"	background-image: url(:/images/red.png);\n"
"    \n"
"	border-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        red->setAutoDefault(false);
        red->setFlat(false);
        frontGround = new QColumnView(color);
        frontGround->setObjectName(QStringLiteral("frontGround"));
        frontGround->setGeometry(QRect(10, 20, 48, 48));
        frontGround->setStyleSheet(QStringLiteral("background-color: rgb(255,127,39);"));
        blue = new MyButton(color);
        blue->setObjectName(QStringLiteral("blue"));
        blue->setGeometry(QRect(10, 160, 32, 32));
        blue->setStyleSheet(QLatin1String("QPushButton#blue\n"
"{\n"
"	background-image: url(:/images/blue.png);\n"
"}"));
        blue->setIconSize(QSize(16, 16));
        orange = new MyButton(color);
        orange->setObjectName(QStringLiteral("orange"));
        orange->setGeometry(QRect(60, 80, 32, 32));
        orange->setStyleSheet(QLatin1String("QPushButton#orange\n"
"{\n"
"	background-image: url(:/images/orange.png);\n"
"}"));
        polygen = new QPushButton(color);
        polygen->setObjectName(QStringLiteral("polygen"));
        polygen->setGeometry(QRect(90, 270, 52, 52));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\232\266\344\271\246"));
        font1.setPointSize(9);
        polygen->setFont(font1);
        polygen->setStyleSheet(QLatin1String("QPushButton#polygen\n"
"{\n"
"	background-image: url(:/images/Free-Transform-48.png)\n"
"}"));
        fill = new QPushButton(color);
        fill->setObjectName(QStringLiteral("fill"));
        fill->setGeometry(QRect(20, 350, 52, 52));
        fill->setStyleSheet(QLatin1String("QPushButton#fill\n"
"{\n"
"	background-image: url(:/images/Paint-Bucket-48.png)\n"
"}"));
        circle = new QPushButton(color);
        circle->setObjectName(QStringLiteral("circle"));
        circle->setGeometry(QRect(90, 350, 52, 52));
        circle->setStyleSheet(QLatin1String("QPushButton#circle\n"
"{\n"
"	background-image: url(:/images/Shape62-48.png)\n"
"}"));
        square = new QPushButton(color);
        square->setObjectName(QStringLiteral("square"));
        square->setGeometry(QRect(20, 270, 52, 52));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\351\232\266\344\271\246"));
        font2.setPointSize(9);
        square->setFont(font2);
        square->setStyleSheet(QLatin1String("QPushButton#square\n"
"{\n"
"	background-image: url(:/images/Selection-48.png)\n"
"}"));
        checkBox = new QCheckBox(color);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(20, 240, 111, 16));
        QFont font3;
        font3.setFamily(QStringLiteral("Buxton Sketch"));
        font3.setPointSize(12);
        checkBox->setFont(font3);
        label = new QLabel(color);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 320, 41, 16));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font4.setPointSize(10);
        label->setFont(font4);
        label_2 = new QLabel(color);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 320, 41, 20));
        label_2->setFont(font4);
        label_4 = new QLabel(color);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(100, 410, 41, 20));
        label_4->setFont(font4);
        label_5 = new QLabel(color);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 410, 41, 16));
        label_5->setFont(font4);
        toolBox->addItem(color, QStringLiteral(" Color and Painting"));
        tools = new QWidget();
        tools->setObjectName(QStringLiteral("tools"));
        tools->setGeometry(QRect(0, 0, 151, 517));
        QFont font5;
        font5.setFamily(QStringLiteral("Arial"));
        font5.setPointSize(12);
        tools->setFont(font5);
        rotateLeft = new QPushButton(tools);
        rotateLeft->setObjectName(QStringLiteral("rotateLeft"));
        rotateLeft->setGeometry(QRect(20, 10, 52, 52));
        rotateLeft->setStyleSheet(QLatin1String("QPushButton#rotateLeft\n"
"{\n"
"	background-image: url(:/images/Command-Undo-48.png)\n"
"}"));
        rotateRight = new QPushButton(tools);
        rotateRight->setObjectName(QStringLiteral("rotateRight"));
        rotateRight->setGeometry(QRect(80, 10, 52, 52));
        rotateRight->setStyleSheet(QLatin1String("QPushButton#rotateRight\n"
"{\n"
"	background-image: url(:/images/Command-Redo-48.png)\n"
"}"));
        reflectDown = new QPushButton(tools);
        reflectDown->setObjectName(QStringLiteral("reflectDown"));
        reflectDown->setGeometry(QRect(20, 90, 52, 52));
        reflectDown->setStyleSheet(QLatin1String("QPushButton#reflectDown\n"
"{\n"
"	background-image: url(:/images/Share-02-48.png)\n"
"}"));
        zoom = new MyButton(tools);
        zoom->setObjectName(QStringLiteral("zoom"));
        zoom->setGeometry(QRect(80, 250, 52, 52));
        zoom->setContextMenuPolicy(Qt::ActionsContextMenu);
        zoom->setStyleSheet(QLatin1String("QPushButton#zoom\n"
"{\n"
"	background-image: url(:/images/Zooming-48.png)\n"
"}"));
        clip = new QPushButton(tools);
        clip->setObjectName(QStringLiteral("clip"));
        clip->setGeometry(QRect(20, 250, 52, 52));
        clip->setStyleSheet(QLatin1String("QPushButton#clip\n"
"{\n"
"	background-image: url(:/images/Cut-48 (1).png)\n"
"}"));
        reflectRight = new QPushButton(tools);
        reflectRight->setObjectName(QStringLiteral("reflectRight"));
        reflectRight->setGeometry(QRect(80, 90, 52, 52));
        reflectRight->setContextMenuPolicy(Qt::ActionsContextMenu);
        reflectRight->setStyleSheet(QLatin1String("QPushButton#reflectRight\n"
"{\n"
"	background-image: url(:/images/Turn-48.png)\n"
"}"));
        moveLeft = new QPushButton(tools);
        moveLeft->setObjectName(QStringLiteral("moveLeft"));
        moveLeft->setGeometry(QRect(20, 170, 52, 52));
        moveLeft->setStyleSheet(QLatin1String("QPushButton#moveLeft\n"
"{\n"
"	background-image:url(:/images/Swap-Left-48.png)\n"
"}"));
        moveRight = new QPushButton(tools);
        moveRight->setObjectName(QStringLiteral("moveRight"));
        moveRight->setGeometry(QRect(80, 170, 52, 52));
        moveRight->setStyleSheet(QLatin1String("QPushButton#moveRight\n"
"{\n"
"	background-image: url(:/images/Swap-Right-48.png)\n"
"}"));
        label_6 = new QLabel(tools);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(80, 60, 41, 20));
        label_6->setFont(font4);
        label_7 = new QLabel(tools);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 60, 51, 16));
        label_7->setFont(font4);
        label_8 = new QLabel(tools);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 140, 61, 20));
        label_8->setFont(font4);
        label_9 = new QLabel(tools);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(80, 140, 71, 20));
        label_9->setFont(font4);
        label_10 = new QLabel(tools);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 220, 31, 16));
        label_10->setFont(font4);
        label_11 = new QLabel(tools);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(90, 220, 41, 20));
        label_11->setFont(font4);
        label_12 = new QLabel(tools);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 310, 71, 20));
        label_12->setFont(font4);
        label_13 = new QLabel(tools);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(90, 310, 41, 20));
        label_13->setFont(font4);
        label_14 = new QLabel(tools);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(20, 410, 81, 16));
        label_14->setFont(font4);
        clipPolygen = new QPushButton(tools);
        clipPolygen->setObjectName(QStringLiteral("clipPolygen"));
        clipPolygen->setGeometry(QRect(20, 350, 52, 52));
        clipPolygen->setStyleSheet(QLatin1String("QPushButton#clipPolygen\n"
"{\n"
"	background-image: url(:/images/Cut-48 (1).png)\n"
"}"));
        toolBox->addItem(tools, QStringLiteral("           Tools"));
        paintArea = new PaintWidget(centralWidget);
        paintArea->setObjectName(QStringLiteral("paintArea"));
        paintArea->setEnabled(true);
        paintArea->setGeometry(QRect(169, -1, 681, 621));
        paintArea->setMinimumSize(QSize(681, 621));
        paintArea->setMaximumSize(QSize(681, 621));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217"));
        paintArea->setFont(font6);
        paintArea->setMouseTracking(false);
        paintArea->setFocusPolicy(Qt::StrongFocus);
        paintArea->setAutoFillBackground(false);
        horizontalLayout = new QHBoxLayout(paintArea);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(0);
        red->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Polygen Painter", 0));
        green->setText(QString());
        yellow->setText(QString());
        blueLight->setText(QString());
        greenLight->setText(QString());
        purple->setText(QString());
        purpleLight->setText(QString());
        red->setText(QString());
        blue->setText(QString());
        orange->setText(QString());
        polygen->setText(QString());
        fill->setText(QString());
        circle->setText(QString());
        square->setText(QString());
        checkBox->setText(QApplication::translate("MainWindow", "with inner circle", 0));
        label->setText(QApplication::translate("MainWindow", "\351\225\277\346\226\271\345\275\242", 0));
        label_2->setText(QApplication::translate("MainWindow", "\345\244\232\350\276\271\345\275\242", 0));
        label_4->setText(QApplication::translate("MainWindow", "\346\244\255\345\234\206", 0));
        label_5->setText(QApplication::translate("MainWindow", "\346\262\271\346\274\206\346\241\266", 0));
        toolBox->setItemText(toolBox->indexOf(color), QApplication::translate("MainWindow", " Color and Painting", 0));
        rotateLeft->setText(QString());
        rotateRight->setText(QString());
        reflectDown->setText(QString());
        zoom->setText(QString());
        clip->setText(QString());
        reflectRight->setText(QString());
        moveLeft->setText(QString());
        moveRight->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "\345\217\263\350\275\25490", 0));
        label_7->setText(QApplication::translate("MainWindow", "\345\267\246\350\275\25490", 0));
        label_8->setText(QApplication::translate("MainWindow", "\344\270\212\344\270\213\347\277\273\350\275\254", 0));
        label_9->setText(QApplication::translate("MainWindow", "\345\267\246\345\217\263\347\277\273\350\275\254", 0));
        label_10->setText(QApplication::translate("MainWindow", "\345\267\246\347\247\273", 0));
        label_11->setText(QApplication::translate("MainWindow", "\345\217\263\347\247\273", 0));
        label_12->setText(QApplication::translate("MainWindow", "\344\273\245\347\237\251\345\275\242\350\243\201\345\211\252", 0));
        label_13->setText(QApplication::translate("MainWindow", "\347\274\251\346\224\276", 0));
        label_14->setText(QApplication::translate("MainWindow", "\344\273\245\345\244\232\350\276\271\345\275\242\350\243\201\345\211\252", 0));
        clipPolygen->setText(QString());
        toolBox->setItemText(toolBox->indexOf(tools), QApplication::translate("MainWindow", "           Tools", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
