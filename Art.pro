#-------------------------------------------------
#
# Project created by QtCreator 2018-03-14T01:54:39
#
#-------------------------------------------------

QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Art
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    views/mainwindow.cpp \
    views/studywindow.cpp \
    views/gamewindow.cpp \
    views/addpict.cpp \
    controllers/controller.cpp \
    models/databaseadapter.cpp \
    views/admindialog.cpp \
    views/logindialog.cpp \
    views/addartistdialog.cpp \
    views/firstgamedialog.cpp \
    views/secondgamedialog.cpp

HEADERS += \
    views/mainwindow.h \
    views/studywindow.h \
    views/gamewindow.h \
    views/addpict.h \
    controllers/controller.h \
    models/databaseadapter.h \
    views/admindialog.h \
    views/logindialog.h \
    views/addartistdialog.h \
    views/firstgamedialog.h \
    views/secondgamedialog.h

FORMS += \
    views/mainwindow.ui \
    views/studywindow.ui \
    views/gamewindow.ui \
    views/addpict.ui \
    views/admindialog.ui \
    views/logindialog.ui \
    views/addartistdialog.ui \
    views/firstgamedialog.ui \
    views/secondgamedialog.ui

RESOURCES += \
    resource.qrc
