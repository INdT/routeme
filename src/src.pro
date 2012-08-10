PROJECTNAME = Route Me

TARGET = routeme

TEMPLATE = app

INCLUDEPATH = .

CONFIG += mobility
MOBILITY += location bearer

HEADERS += \
    routegeomap.h \
    routemapitem.h

SOURCES += \
    routegeomap.cpp \
    routemapitem.cpp \
    main.cpp

INSTALLS += target
