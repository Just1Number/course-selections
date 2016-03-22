#-------------------------------------------------
#
# Project created by QtCreator 2016-03-18T14:34:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = course-selections
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    algorithm.cpp \
    jsontranslator.cpp \
    votingdata.cpp

HEADERS  += mainwindow.h \
    algorithm.h \
    jsontranslator.h \
    votingdata.h

FORMS    += mainwindow.ui

DISTFILES += \
    README.md \
    course-selections.py \
    json_test.json
