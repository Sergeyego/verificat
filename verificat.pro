QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    db/dbcombobox.cpp \
    db/dbdateedit.cpp \
    db/dbdelegate.cpp \
    db/dblogin.cpp \
    db/dbmapper.cpp \
    db/dbrelationeditdialog.cpp \
    db/dbtablemodel.cpp \
    db/dbviewer.cpp \
    db/executor.cpp \
    db/tablemodel.cpp \
    formdev.cpp \
    formrep.cpp \
    formver.cpp \
    main.cpp \
    mainwindow.cpp \
    modelro.cpp \
    rels.cpp \
    tableview.cpp

HEADERS += \
    db/dbcombobox.h \
    db/dbdateedit.h \
    db/dbdelegate.h \
    db/dblogin.h \
    db/dbmapper.h \
    db/dbrelationeditdialog.h \
    db/dbtablemodel.h \
    db/dbviewer.h \
    db/executor.h \
    db/tablemodel.h \
    formdev.h \
    formrep.h \
    formver.h \
    mainwindow.h \
    modelro.h \
    rels.h \
    tableview.h

FORMS += \
    db/dblogin.ui \
    db/dbrelationeditdialog.ui \
    formdev.ui \
    formrep.ui \
    formver.ui \
    mainwindow.ui

RC_FILE = ico.rc

DISTFILES += \
    ico.rc

RESOURCES += \
    res.qrc

macx:ICON = icon.icns

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

