#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = 0);

private slots:
	void mousePressEvent(QMouseEvent *e);

signals:
	void rightClicked();
    void leftClicked();
	
public slots:

};

#endif // MYBUTTON_H
