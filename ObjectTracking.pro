#-------------------------------------------------
#
# Project created by QtCreator 2013-11-09T23:40:16
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = ObjectTracking
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

INCLUDEPATH += C:\OpenCV2.2\include\

LIBS += -LC:\OpenCV2.2\lib \
-lopencv_core220d \
-lopencv_highgui220d \
-lopencv_imgproc220d \
-lopencv_features2d220d \
-lopencv_calib3d220d \
-lopencv_video220d

HEADERS += \
    objectFinder.h \
    colorhistogram.h
