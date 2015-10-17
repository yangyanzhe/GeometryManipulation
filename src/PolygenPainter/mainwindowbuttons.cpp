#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>
#include <QDebug>

//==============================================
// change color
//==============================================

void MainWindow::onRedRightClicked()
{
    painter->backColor = RGB(237,28,36);
    ui->backGround->setStyleSheet("background-color: rgb(237,28,36);");
}

void MainWindow::onRedLeftClicked()
{
    painter->frontColor = RGB(237,28,36);
    ui->frontGround->setStyleSheet("background-color: rgb(237,28,36);");
}

void MainWindow::onOrangeRightClicked()
{
    painter->backColor = RGB(244,127,39);
    ui->backGround->setStyleSheet("background-color: rgb(244,127,39);");
}

void MainWindow::onOrangeLeftClicked()
{
    painter->frontColor = RGB(244,127,39);
    ui->frontGround->setStyleSheet("background-color: rgb(244,127,39);");
}

void MainWindow::onYellowRightClicked()
{
    painter->backColor = RGB(255,201,14);
    ui->backGround->setStyleSheet("background-color: rgb(255,201,14);");
}

void MainWindow::onYellowLeftClicked()
{
    painter->frontColor = RGB(255,201,14);
    ui->frontGround->setStyleSheet("background-color: rgb(255,201,14);");
}

void MainWindow::onPurpleRightClicked()
{
    painter->backColor = RGB(163, 73, 164);
    ui->backGround->setStyleSheet("background-color: rgb(163, 73, 164);");
}

void MainWindow::onPurpleLeftClicked()
{
    painter->frontColor = RGB(163, 73, 164);
    ui->frontGround->setStyleSheet("background-color: rgb(163, 73, 164);");
}

void MainWindow::onPurpleLightRightClicked()
{
    painter->backColor = RGB(200,191,231);
    ui->backGround->setStyleSheet("background-color: rgb(200,191,231);");
}

void MainWindow::onPurpleLightLeftClicked()
{
    painter->frontColor = RGB(200,191,231);
    ui->frontGround->setStyleSheet("background-color: rgb(200,191,231);");
}

void MainWindow::onBlueRightClicked()
{
    painter->backColor = RGB(0,162,232);
    ui->backGround->setStyleSheet("background-color: rgb(0,162,232);");
}

void MainWindow::onBlueLeftClicked()
{
    painter->frontColor = RGB(0,162,232);
    ui->frontGround->setStyleSheet("background-color: rgb(0,162,232);");
}

void MainWindow::onBlueLightRightClicked()
{
    painter->backColor = RGB(153,217,234);
    ui->backGround->setStyleSheet("background-color: rgb(153,217,234);");
}

void MainWindow::onBlueLightLeftClicked()
{
    painter->frontColor = RGB(153,217,234);
    ui->frontGround->setStyleSheet("background-color: rgb(153,217,234);");
}

void MainWindow::onGreenRightClicked()
{
    painter->backColor = RGB(34,177,76);
    ui->backGround->setStyleSheet("background-color: rgb(34,177,76);");
}

void MainWindow::onGreenLeftClicked()
{
    painter->frontColor = RGB(34,177,76);
    ui->frontGround->setStyleSheet("background-color: rgb(34,177,76);");
}

void MainWindow::onGreenLightRightClicked()
{
    painter->backColor = RGB(181,230,29);
    ui->backGround->setStyleSheet("background-color: rgb(181,230,29);");
}

void MainWindow::onGreenLightLeftClicked()
{
    painter->frontColor = RGB(181,230,29);
    ui->frontGround->setStyleSheet("background-color: rgb(181,230,29);");
}

//==============================================
// change operation mode
//==============================================

void MainWindow::on_polygen_clicked()
{
    painter->mmode = polygen;
}

void MainWindow::on_fill_clicked()
{
    painter->mmode = fill;
}

void MainWindow::on_circle_clicked()
{
    painter->mmode = eclipse;
}

void MainWindow::on_square_clicked()
{
    painter->mmode = rectangle;
}

void MainWindow::on_clip_clicked()
{
    painter->mmode = clip;
    qDebug() << "clip";
}

void MainWindow::on_clipPolygen_clicked()
{
    painter->mmode = clipPolygen;
}

void MainWindow::on_reflectDown_clicked()
{
    ui->paintArea->repaint();
    painter->reflectDown(hdc);
}

void MainWindow::on_reflectRight_clicked()
{
    ui->paintArea->repaint();
    painter->reflectRight(hdc);
}

void MainWindow::on_rotateLeft_clicked()
{
    ui->paintArea->repaint();
    painter->rotateLeft(hdc);
}

void MainWindow::on_rotateRight_clicked()
{
    ui->paintArea->repaint();
    painter->rotateRight(hdc);
}

void MainWindow::on_moveLeft_clicked()
{
    ui->paintArea->repaint();
    painter->moveLeft(hdc);
}

void MainWindow::on_moveRight_clicked()
{
    ui->paintArea->repaint();
    painter->moveRight(hdc);
}

void MainWindow::on_zoomIn_clicked()
{
    ui->paintArea->repaint();
    painter->zoomIn(hdc);
}

void MainWindow::on_zoomOut_clicked()
{
    ui->paintArea->repaint();
    painter->zoomOut(hdc);
}
