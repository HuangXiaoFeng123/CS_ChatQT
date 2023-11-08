QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clientrecord.cpp \
    cs_client.cpp \
    main.cpp \
    cs_server.cpp \
    mypthread.cpp \
    serverrecord.cpp

HEADERS += \
    clientrecord.h \
    cs_client.h \
    cs_server.h \
    mypthread.h \
    serverrecord.h

FORMS += \
    clientrecord.ui \
    cs_client.ui \
    cs_server.ui \
    serverrecord.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ImageResource.qrc
