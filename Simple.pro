QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    gui/mainwindow.cpp \
    gui/input_window.cpp \
    gui/keyboard_window.cpp \
    gui/cell.cpp \
    gui/message_window.cpp \
    core/game.cpp \
    core/load_data.cpp \

HEADERS += \
    gui/mainwindow.h \
    gui/input_window.h \
    gui/keyboard_window.h \
    gui/cell.h \
    gui/message_window.h \
    core/game_status.h \
    core/game.h \
    core/load_data.h \

#FORMS += \
#    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src/valid_word.qrc
