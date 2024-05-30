QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    change.cpp \
    changeinfo.cpp \
    info.cpp \
    input.cpp \
    main.cpp \
    page_login.cpp \
    page_manage.cpp \
    page_stu.cpp \
    sha256.cpp \
    statistics.cpp \
    view.cpp

HEADERS += \
    change.h \
    changeinfo.h \
    info.h \
    input.h \
    page_login.h \
    page_manage.h \
    page_stu.h \
    sha256.h \
    statistics.h \
    view.h

FORMS += \
    change.ui \
    changeinfo.ui \
    input.ui \
    page_login.ui \
    page_manage.ui \
    page_stu.ui \
    statistics.ui \
    view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
