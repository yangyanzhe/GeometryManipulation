#include <QWidget>
#include <QMouseEvent>
#include "paintwidget.h"
#include "paint.h"

PaintWidget::PaintWidget(QWidget *parent) : QWidget(parent)
{

}

void PaintWidget::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::RightButton)
        emit rightPressed(e->x(), e->y());
    else
        emit leftPressed(e->x(), e->y());
}

void PaintWidget::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button()==Qt::RightButton)
        emit rightReleased(e->x(), e->y());
    else
        emit leftReleased(e->x(), e->y());
}

void PaintWidget::mouseDoubleClickEvent(QMouseEvent *e)
{
    emit doubleClicked();
}

void PaintWidget::mouseMoveEvent(QMouseEvent *e)
{
    emit moved(e->x(), e->y());
}

void PaintWidget::focusOutEvent(QFocusEvent *event)
{

}

void PaintWidget::focusInEvent(QFocusEvent *event)
{

}

/*
void PaintWidget::paintEvent(QPaintEvent *)
{
    if(painter->currentPolygen == NULL) return;

    //QPainter painter(this);
    if(painter->withInnerCircle)
    {
        Polygen* p = painter->currentInnerPolygen;
        painter->fillPolygenWithInnerCircle(painter->gHDC);
    }
    else
    {
        Polygen* p = painter->currentPolygen;
        painter->fill(painter->gHDC, p, painter->backColor);
        painter->drawBoundary(painter->gHDC, p);
    }

}*/
