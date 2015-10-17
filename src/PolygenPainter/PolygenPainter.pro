#-------------------------------------------------
#
# Project created by QtCreator 2015-10-07T12:27:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PolygenPainter
TEMPLATE = app

LIBS += -lgdi32

SOURCES += main.cpp\
        mainwindow.cpp \
    paint.cpp \
    mybutton.cpp \
    paintwidget.cpp \
    mainwindowbuttons.cpp \
    polygen.cpp \
    paintoperation.cpp \
    paintclip.cpp

HEADERS  += mainwindow.h \
    paint.h \
    mybutton.h \
    paintwidget.h \
    polygen.h

FORMS    += mainwindow.ui

RESOURCES += \
    icon.qrc

DISTFILES += \
    images/blue.png \
    images/blue-light.png \
    images/cut-32.png \
    images/cut-48.png \
    images/green.png \
    images/green-light.png \
    images/orange.png \
    images/purple.png \
    images/purple-light.png \
    images/red.png \
    images/Rotate-01-32.png \
    images/rotate-32.png \
    images/Stationery-Pen-32.png \
    images/Stationery-Pen-48.png \
    images/yellow.png \
    images/Zooming-32.png \
    images/Zoom-Scroll-32.png \
    images/Zoom-Scroll-48.png \
    images/3.jpg \
    images/6.jpg \
    gdi32.dll
