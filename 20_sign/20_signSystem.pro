#-------------------------------------------------
#
# Project created by QtCreator 2020-02-06T16:07:17
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 20_signSystem
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp\
    person.cpp \
    login.cpp \
    reg.cpp
HEADERS  += widget.h\
    person.h \
    login.h \
    reg.h
FORMS    += widget.ui \
    person.ui \
    login.ui \
    reg.ui
  RC_ICONS = MyIcon2.ico

DISTFILES +=

RESOURCES += \
    Lpage/lll.qrc
