QT       += core gui printsupport charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    depositwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    mortagewindow.cpp \
    qcustomplot.cpp \
    secretx.cpp \
    simplegraph.cpp \
    simplewindow.cpp \
    ../graph.c \
    ../lib/calculate.c \
    ../lib/code.c \
    ../lib/input_formula.c \
    ../lib/polish_notation.c \
    ../lib/stack.c \



HEADERS += \
    depositwindow.h \
    mainwindow.h \
    mortagewindow.h \
    qcustomplot.h \
    secretx.h \
    simplegraph.h \
    simplewindow.h \
    ../graph.h \
    ../lib/calculate.h \
    ../lib/code.h \
    ../lib/input_formula.h \
    ../lib/polish_notation.h \
    ../lib/stack.h

FORMS += \
    depositwindow.ui \
    mainwindow.ui \
    mortagewindow.ui \
    secretx.ui \
    simplegraph.ui \
    simplewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    sources.qrc
