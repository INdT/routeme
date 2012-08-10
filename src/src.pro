PROJECTNAME = Route Me

TARGET = routeme

TEMPLATE = app

QT += declarative

INCLUDEPATH = .

CONFIG += mobility
MOBILITY += location

HEADERS += \
    routegeomap.h \
    routemapitem.h \
    routeme.h

SOURCES += \
    routegeomap.cpp \
    routemapitem.cpp \
    routeme.cpp \
    main.cpp

RESOURCES += qml.qrc

contains(MEEGO_EDITION, harmattan) {
    DEFINES += MEEGO_EDITION_HARMATTAN
    target.path = /opt/src/bin
}

INSTALLS += target

OTHER_FILES += \
    qml/*
