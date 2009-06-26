TEMPLATE = app
QT = gui \
    core \
    network
CONFIG += qt \
    release \
    warn_on \
    console
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/mainwindow.ui
HEADERS = src/mainwindowimpl.h \
    libs/src/mytelnetwidget.h
SOURCES = src/mainwindowimpl.cpp \
    src/main.cpp \
    libs/src/mytelnetwidget.cpp
include(./libs/solutions/qttelnet-2.1-opensource/src/qttelnet.pri)
