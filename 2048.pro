#-------------------------------------------------
#
# Project created by QtCreator 2017-06-14T16:16:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2048
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    welcomedialog.cpp \
    picturepath.cpp \
    honordialog.cpp \
    authordialog.cpp \
    gamecontroller.cpp \
    mover.cpp \
    helpdialog.cpp \
    choosedialog.cpp \
    winnerdialog.cpp \
    usermessage.cpp \
    scoredialog.cpp \
    rankdialog.cpp \
    photoshower.cpp

HEADERS  += mainwindow.h \
    welcomedialog.h \
    picturepath.h \
    constants.h \
    honordialog.h \
    authordialog.h \
    gamecontroller.h \
    mover.h \
    helpdialog.h \
    choosedialog.h \
    winnerdialog.h \
    usermessage.h \
    scoredialog.h \
    rankdialog.h \
    photoshower.h

RESOURCES += \
    gamebase.qrc \
    faces.qrc \
    winner.qrc

CONFIG += C++11

CONFIG += resources_big

QT       += core gui opengl
