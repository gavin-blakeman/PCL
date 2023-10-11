#-------------------------------------------------
#
# Project created by QtCreator 2013-06-16T10:08:35
#
#-------------------------------------------------

TARGET = PCL
TEMPLATE = lib
CONFIG += staticlib create_prl

QT       -= core gui

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

QMAKE_CXXFLAGS += -std=c++20

INCLUDEPATH += \
  "../GCL" \
  "../MCL" \

SOURCES += \
    source/temperature.cpp \
    source/pressure.cpp \
    source/mass.cpp \
    source/velocity.cpp \
    source/common.cpp \
    source/distance.cpp

HEADERS += \
    include/constants.h \
    include/mass.h \
    include/pressure.h \
    include/temperature.h \
    include/velocity.h \
    PCL \
    include/common.h \
    include/distance.h

DISTFILES += \
  CMakeLists.txt
