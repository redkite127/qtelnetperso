TEMPLATE = app
QT = gui \
    core \
    network
CONFIG += qt \
    release \
    warn_on
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/mainwindow.ui
HEADERS = src/mainwindowimpl.h \
    libs/src/mytelnetwidget.h \
    libs/src/qtelnetperso.h
SOURCES = src/mainwindowimpl.cpp \
    src/main.cpp \
    libs/src/mytelnetwidget.cpp \
    libs/src/qtelnetperso.cpp
