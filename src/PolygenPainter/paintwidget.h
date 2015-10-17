#ifndef PAINTWIDGET
#define PAINTWIDGET

#include <QWidget>

class PaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintWidget(QWidget *parent = 0);

private slots:
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);
    void focusOutEvent(QFocusEvent* event);
    void focusInEvent(QFocusEvent* event);
    //void paintEvent(QPaintEvent *);

signals:
    void rightPressed(int x, int y);
    void leftPressed(int x, int y);

    void rightReleased(int x, int y);
    void leftReleased(int x, int y);

    void moved(int x, int y);
    void doubleClicked();

public slots:

};

#endif // PAINTWIDGET

