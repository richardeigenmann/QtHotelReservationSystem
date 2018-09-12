#-------------------------------------------------
#
# Project created by QtCreator 2018-08-21T19:05:14
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = QtHotelReservationSystem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++14

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    mongostuff.cpp

HEADERS += \
    mongostuff.h \
    mainwindow.h \
    reservation.h
#    $$PWD/../../../vcpkg/packages/boost-utility_x64-windows/include/boost/utility/string_ref.hpp

FORMS += \
        mainwindow.ui


#VCPKG =$$PWD/../../../vcpkg
VCPKG = C:/Users/Richard/Documents/vcpkg

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix|win32: LIBS += -L$$VCPKG/packages/mongo-cxx-driver_x64-windows/lib/ -lmongocxx -lbsoncxx



INCLUDEPATH += $$VCPKG/packages/mongo-cxx-driver_x64-windows/include
DEPENDPATH += $$VCPKG/packages/mongo-cxx-driver_x64-windows/include

INCLUDEPATH += $$VCPKG/packages/boost-utility_x64-windows/include
INCLUDEPATH += $$VCPKG/packages/boost-config_x64-windows/include
INCLUDEPATH += $$VCPKG/packages/boost-throw-exception_x64-windows/include
INCLUDEPATH += $$VCPKG/packages/boost-assert_x64-windows/include
INCLUDEPATH += $$VCPKG/packages/boost-optional_x64-windows/include
INCLUDEPATH += $$VCPKG/packages/boost-core_x64-windows/include
INCLUDEPATH += $$VCPKG/packages/boost-static-assert_x64-windows/include
INCLUDEPATH += $$VCPKG/packages/boost-type-traits_x64-windows/include
INCLUDEPATH += $$VCPKG/packages/boost-move_x64-windows/include
INCLUDEPATH += $$VCPKG/packages/boost-bind_x64-windows/include
INCLUDEPATH += $$VCPKG/packages/boost-compatibility_x64-windows/include
INCLUDEPATH += $$VCPKG/packages/boost-detail_x64-windows/include
INCLUDEPATH += $$VCPKG/packages/boost-integer_x64-windows/include
INCLUDEPATH += $$VCPKG/packages/boost-mpl_x64-windows/include
INCLUDEPATH += $$VCPKG/packages/boost-predef_x64-windows/include
INCLUDEPATH += $$VCPKG/packages/boost-preprocessor_x64-windows/include
INCLUDEPATH += $$VCPKG/packages/boost-smart-ptr_x64-windows/include
INCLUDEPATH += $$VCPKG/packages/boost-utility_x64-windows/include
INCLUDEPATH += $$VCPKG/packages/boost-vcpkg-helpers_x64-windows/include

unix|win32: LIBS += -L$$VCPKG/packages/libbson_x64-windows/lib/ -lbson-1.0

INCLUDEPATH += $$VCPKG/packages/libbson_x64-windows/include
DEPENDPATH += $$VCPKG/packages/libbson_x64-windows/include

DISTFILES += \
    .gitignore \
    Readme.md








unix:!macx: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lmongocxx
unix:!macx: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lbsoncxx
unix:!macx: INCLUDEPATH += $$PWD/../../../../../usr/local/include/mongocxx/v_noabi/
unix:!macx: INCLUDEPATH += $$PWD/../../../../../usr/local/include/bsoncxx/v_noabi/


