PROJECTNAME = Route Me

TARGET = routeme

TEMPLATE = app

QT += declarative network

INCLUDEPATH = .
DESTDIR = ../

CONFIG += mobility
MOBILITY += location messaging contacts

CONFIG += qdeclarative-boostable shareuiinterface-maemo-meegotouch meegotouchevents

HEADERS += \
    routemegraphicsgeomap.h \
    routememap.h \
    routeme.h \
    routemeserver.h \
    serviceprovider.h \
    routemepositioninfo.h \
    routemecoordinate.h \
    routemeroutemapobject.h \
    routemeroutemanager.h \
    routemecontroller.h \
    routemeaddress.h \
    routemeplace.h \
    routemesearchmanager.h \
    routemepixmapobject.h

SOURCES += \
    routemegraphicsgeomap.cpp \
    routememap.cpp \
    routeme.cpp \
    routemeserver.cpp \
    serviceprovider.cpp \
    routemepositioninfo.cpp \
    routemecoordinate.cpp \
    routemeroutemapobject.cpp \
    routemeroutemanager.cpp \
    routemecontroller.cpp \
    routemeaddress.cpp \
    routemeplace.cpp \
    routemesearchmanager.cpp \
    routemepixmapobject.cpp \
    main.cpp

RESOURCES += qml.qrc

contains(MEEGO_EDITION, harmattan) {
    DEFINES += MEEGO_EDITION_HARMATTAN
    target.path = /opt/routeme/bin
}

INSTALLS += target

OTHER_FILES += \
    qml/*
