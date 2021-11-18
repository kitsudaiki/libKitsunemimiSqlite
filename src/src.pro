QT -= qt core gui

TARGET = KitsunemimiSqlite
TEMPLATE = lib
CONFIG += c++17
VERSION = 0.2.0

LIBS += -L../../libKitsunemimiCommon/src -lKitsunemimiCommon
LIBS += -L../../libKitsunemimiCommon/src/debug -lKitsunemimiCommon
LIBS += -L../../libKitsunemimiCommon/src/release -lKitsunemimiCommon
INCLUDEPATH += ../../libKitsunemimiCommon/include

LIBS += -lsqlite3

INCLUDEPATH += $$PWD \
               $$PWD/../include

HEADERS += \
    ../include/libKitsunemimiSqlite/sqlite.h

SOURCES += \
    sqlite.cpp

