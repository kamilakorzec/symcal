#-------------------------------------------------
#
# Project created by QtCreator 2018-03-24T12:18:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += charts

TARGET = sym_cal
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
        symcal.cpp \
    src/inputparser.cpp \
    src/onevarfunction.cpp \
    src/onevarfunctionparser.cpp \
    src/operators.cpp \
    src/token.cpp \
    src/operations.cpp \
    ui_symcal.cpp \
    src/range.cpp \
    src/onevarfunctionvalues.cpp \
    src/exporter.cpp

HEADERS += \
        symcal.h \
    lib/inputparser.h \
    lib/nvarfunction.h \
    lib/onevarfunction.h \
    lib/onevarfunctionparser.h \
    lib/onevarfunctionvalues.h \
    lib/operators.h \
    lib/point.h \
    lib/range.h \
    lib/token.h \
    lib/operations.h \
    ui_symcal.h \
    lib/exporter.h

FORMS +=
