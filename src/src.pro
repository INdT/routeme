PROJECTNAME = Route Me

TARGET = routeme

TEMPLATE = app

QT += declarative network

INCLUDEPATH = .
DESTDIR = ../

CONFIG += mobility
MOBILITY += location

HEADERS += \
    routegeomap.h \
    routemapitem.h \
    routeme.h \
    routemeserver.h \
    serviceprovider.h \
    routepositioninfo.h \
    routemecoordinate.h \
    routemapobject.h \
    routingmanager.h \
    routemecontroller.h \
    routemeaddress.h \
    routemeplace.h \
    routesearchmanager.h

SOURCES += \
    routegeomap.cpp \
    routemapitem.cpp \
    routeme.cpp \
    routemeserver.cpp \
    serviceprovider.cpp \
    routepositioninfo.cpp \
    routemecoordinate.cpp \
    routemapobject.cpp \
    routingmanager.cpp \
    routemecontroller.cpp \
    routemeaddress.cpp \
    routemeplace.cpp \
    routesearchmanager.cpp \
    main.cpp

RESOURCES += qml.qrc

contains(MEEGO_EDITION, harmattan) {
    DEFINES += MEEGO_EDITION_HARMATTAN
    target.path = /opt/src/bin
}

INSTALLS += target

OTHER_FILES += \
    qml/*
