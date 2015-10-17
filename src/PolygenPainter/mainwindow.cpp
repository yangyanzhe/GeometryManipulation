#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>
#include <QDebug>
#include "paint.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hwnd = (HWND)ui->paintArea->winId();
    hdc = GetDC(hwnd);
    painter = new Paint;

    connect(ui->red, 	SIGNAL(rightClicked()), this, SLOT(onRedRightClicked()));
    connect(ui->red, 	SIGNAL(leftClicked()), 	this, SLOT(onRedLeftClicked()));
    connect(ui->orange, SIGNAL(rightClicked()), this, SLOT(onOrangeRightClicked()));
    connect(ui->orange, SIGNAL(leftClicked()), 	this, SLOT(onOrangeLeftClicked()));
    connect(ui->yellow, SIGNAL(rightClicked()), this, SLOT(onYellowRightClicked()));
    connect(ui->yellow, SIGNAL(leftClicked()), 	this, SLOT(onYellowLeftClicked()));
    connect(ui->purple, SIGNAL(rightClicked()), this, SLOT(onPurpleRightClicked()));
    connect(ui->purple, SIGNAL(leftClicked()), 	this, SLOT(onPurpleLeftClicked()));
    connect(ui->blue, 	SIGNAL(rightClicked()), this, SLOT(onBlueRightClicked()));
    connect(ui->blue, 	SIGNAL(leftClicked()), 	this, SLOT(onBlueLeftClicked()));
    connect(ui->green, 	SIGNAL(rightClicked()), this, SLOT(onGreenRightClicked()));
    connect(ui->green, 	SIGNAL(leftClicked()), 	this, SLOT(onGreenLeftClicked()));

    connect(ui->purpleLight, 	SIGNAL(rightClicked()), this, SLOT(onPurpleLightRightClicked()));
    connect(ui->purpleLight, 	SIGNAL(leftClicked()), 	this, SLOT(onPurpleLightLeftClicked()));
    connect(ui->blueLight, 		SIGNAL(rightClicked()), this, SLOT(onBlueLightRightClicked()));
    connect(ui->blueLight, 		SIGNAL(leftClicked()), 	this, SLOT(onBlueLightLeftClicked()));
    connect(ui->greenLight, 	SIGNAL(rightClicked()), this, SLOT(onGreenLightRightClicked()));
    connect(ui->greenLight, 	SIGNAL(leftClicked()), 	this, SLOT(onGreenLightLeftClicked()));

    connect(ui->zoom, SIGNAL(leftClicked()), this, SLOT(on_zoomOut_clicked()));
    connect(ui->zoom, SIGNAL(rightClicked()), this, SLOT(on_zoomIn_clicked()));

    connect(ui->paintArea,  SIGNAL(leftPressed(int, int)), this, SLOT(mouseLeftPressed(int, int)));
    connect(ui->paintArea,  SIGNAL(rightPressed(int, int)), this, SLOT(mouseRightPressed(int, int)));
    connect(ui->paintArea,  SIGNAL(leftReleased(int, int)), this, SLOT(mouseLeftReleased(int, int)));
    connect(ui->paintArea,  SIGNAL(rightReleased(int, int)), this, SLOT(mouseRightReleased(int, int)));
    connect(ui->paintArea,  SIGNAL(moved(int, int)), this, SLOT(mouseMoved(int, int)));
    connect(ui->paintArea,  SIGNAL(doubleClicked()), this, SLOT(mouseDoubleClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete painter;
}

// ======= mouse operation in painting =========
void MainWindow::mouseMoved(int x, int y)
{
    qDebug() << "mouseMoved" << x << y ;
}

void MainWindow::mouseLeftPressed(int x, int y)
{
    POINT* p = new POINT;
    p->x = x;
    p->y = y;

    HPEN hPen = CreatePen(PS_SOLID, painter->lineWidth, painter->frontColor);
    SelectObject(hdc, hPen);

    switch(painter->mmode)
    {
        case rectangle:
            painter->drawSquare(hdc, p);
            break;
        case eclipse:
            //painter->drawEclipse(hdc, &p);
            break;
        case polygen:
            painter->drawPolygen(hdc, p);
            break;
        case clip:
            if(painter->drawClipRectangle(hdc, p)){
                ui->paintArea->repaint();
                painter->clip(hdc);
            }
            break;
        case clipPolygen:
            break;
        default: break;
    }


    qDebug() << "mouseLeftPressed" << x << y ;
}

void MainWindow::mouseRightPressed(int x, int y)
{
    HPEN hPen = CreatePen(PS_SOLID, painter->lineWidth, painter->backColor);
    SelectObject(hdc, hPen);
}

void MainWindow::mouseLeftReleased(int x, int y)
{
}

void MainWindow::mouseRightReleased(int x, int y)
{
}

void MainWindow::on_checkBox_clicked()
{
    painter->withInnerCircle = !painter->withInnerCircle;
}

void MainWindow::mouseDoubleClicked()
{
    qDebug() << "double clicked" ;
    painter->direction = true;
    painter->fillPolygenWithInnerCircle(hdc);
}


