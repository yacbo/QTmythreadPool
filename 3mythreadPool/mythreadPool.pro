TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    condition.cpp \
    threadpool.cpp

HEADERS += \
    condition.h \
    threadpool.h
