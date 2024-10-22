QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alarmrecord.cpp \
    barchart.cpp \
    base.cpp \
    basewidget.cpp \
    datamonitor.cpp \
    dataquery.cpp \
    devicemonitor.cpp \
    equipmanage.cpp \
    equipmentpanel.cpp \
    iniconfig.cpp \
    linegraph.cpp \
    main.cpp \
    menuone.cpp \
    mylogin.cpp \
    mysqlite.cpp \
    normalsettings.cpp \
    operationrecord.cpp \
    operationrecords.cpp \
    othersettings.cpp \
    statusbar.cpp \
    systemsettings.cpp \
    titlebar.cpp \
    usermanagement.cpp

HEADERS += \
    alarmrecord.h \
    barchart.h \
    base.h \
    basewidget.h \
    datamonitor.h \
    dataquery.h \
    devicemonitor.h \
    equipmanage.h \
    equipmentpanel.h \
    iniconfig.h \
    linegraph.h \
    menuone.h \
    mylogin.h \
    mysqlite.h \
    normalsettings.h \
    operationrecord.h \
    operationrecords.h \
    othersettings.h \
    statusbar.h \
    systemsettings.h \
    titlebar.h \
    usermanagement.h

FORMS += \
    alarmrecord.ui \
    barchart.ui \
    base.ui \
    basewidget.ui \
    datamonitor.ui \
    dataquery.ui \
    devicemonitor.ui \
    equipmanage.ui \
    equipmentpanel.ui \
    iniconfig.ui \
    linegraph.ui \
    menuone.ui \
    mylogin.ui \
    mysqlite.ui \
    normalsettings.ui \
    operationrecord.ui \
    operationrecords.ui \
    othersettings.ui \
    statusbar.ui \
    systemsettings.ui \
    titlebar.ui \
    usermanagement.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
