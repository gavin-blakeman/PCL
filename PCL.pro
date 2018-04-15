#-------------------------------------------------
#
# Project created by QtCreator 2013-06-16T10:08:35
#
#-------------------------------------------------

QT       -= core gui

TARGET = PCL
TEMPLATE = lib
CONFIG += staticlib

win32:CONFIG(release, debug|release) {
  DESTDIR = "../Library/win32/release"
  OBJECTS_DIR = "../Library/win32/release/object/PCL"
}
else:win32:CONFIG(debug, debug|release) {
  DESTDIR = "../Library/win32/debug"
  OBJECTS_DIR = "../Library/win32/debug/object/PCL"
}
else:unix:CONFIG(release, debug|release) {
  DESTDIR = "../Library/unix/release"
  OBJECTS_DIR = "../Library/unix/release/object/PCL"
}
else:unix:CONFIG(debug, debug|release) {
  DESTDIR = ""
  OBJECTS_DIR = "objects"
}

QMAKE_CXXFLAGS += -std=c++1y

INCLUDEPATH += \
  "../boost 1.62" \
  "../GCL"

SOURCES += \
    Source/temperature.cpp \
    Source/pressure.cpp \
    Source/PCLError.cpp \
    Source/mass.cpp \
    Source/velocity.cpp \
    Source/common.cpp \
    Source/distance.cpp

HEADERS += \
    Include/constants.h \
    Include/mass.h \
    Include/PCLError.h \
    Include/pressure.h \
    Include/temperature.h \
    Include/velocity.h \
    PCL \
    Include/common.h \
    Include/distance.h
