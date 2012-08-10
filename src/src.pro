PROJECTNAME = Route Me

TARGET = routeme

TEMPLATE = app

INCLUDEPATH = .

CONFIG += mobility
MOBILITY += location bearer

HEADERS += \
    routegeomap.h

SOURCES += \
    routegeomap.cpp \
    main.cpp

INSTALLS += target
