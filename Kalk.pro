#-------------------------------------------------
#
# Project created by QtCreator 2017-12-13T22:46:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kalk
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
        kalk.cpp \
    colorergb.cpp \
    librettoesami.cpp \
    esame.cpp \
    data.cpp \
    colore.cpp \
    ingrediente.cpp \
    ricetta.cpp \
    matricealgebrica.cpp

HEADERS += \
        kalk.h \
    vettoregenerico.h \
    colore.h \
    colorergb.h \
    esame.h \
    librettoesami.h \
    data.h \
    ingrediente.h \
    ricetta.h \
    matricealgebrica.h

FORMS += \
        kalk.ui
