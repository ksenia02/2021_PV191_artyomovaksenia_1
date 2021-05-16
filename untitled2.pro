QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    file.cpp

HEADERS  += mainwindow.h \
    file.h \
    fileexception.h \
    sharedptr.h

FORMS    += mainwindow.ui
