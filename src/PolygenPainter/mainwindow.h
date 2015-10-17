#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "paint.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    HWND hwnd;
    HDC  hdc;
    Paint* painter;

private slots:

    // ======= color change =========
    void onRedRightClicked();
    void onRedLeftClicked();
    void onOrangeRightClicked();
    void onOrangeLeftClicked();
    void onYellowRightClicked();
    void onYellowLeftClicked();
    void onPurpleRightClicked();
    void onPurpleLeftClicked();
    void onPurpleLightRightClicked();
    void onPurpleLightLeftClicked();
    void onBlueRightClicked();
    void onBlueLeftClicked();
    void onBlueLightRightClicked();
    void onBlueLightLeftClicked();
    void onGreenRightClicked();
    void onGreenLeftClicked();
    void onGreenLightRightClicked();
    void onGreenLightLeftClicked();
    void on_polygen_clicked();

    // ======= operation =========
    void on_fill_clicked();
    void on_circle_clicked();
    void on_square_clicked();
    void on_clip_clicked();
    void on_reflectDown_clicked();
    void on_reflectRight_clicked();
    void on_rotateLeft_clicked();
    void on_rotateRight_clicked();
    void on_moveLeft_clicked();
    void on_moveRight_clicked();
    void on_zoomOut_clicked();
    void on_zoomIn_clicked();

    // ======= mouse operation in painting =========
    // left and right - button of the mouse
    // =============================================
    void mouseMoved(int x, int y);
    void mouseLeftPressed(int x, int y);
    void mouseRightPressed(int x, int y);
    void mouseLeftReleased(int x, int y);
    void mouseRightReleased(int x, int y);
    void mouseDoubleClicked();
    void on_checkBox_clicked();


    void on_clipPolygen_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
