QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bala.cpp \
    baladib.cpp \
    disparabo.cpp \
    disparo.cpp \
    dispmrua.cpp \
    jugada.cpp \
    jugador.cpp \
    main.cpp \
    mainwindow.cpp \
    nave.cpp \
    navedib.cpp \
    piedras.cpp

HEADERS += \
    bala.h \
    baladib.h \
    disparabo.h \
    disparo.h \
    dispmrua.h \
    jugada.h \
    jugador.h \
    mainwindow.h \
    nave.h \
    navedib.h \
    piedras.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Imagenes.qrc