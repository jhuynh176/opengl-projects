QT += widgets
QT += charts

requires(qtConfig(listwidget))
qtHaveModule(printsupport): QT += printsupport


CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
        MainWindow.h
SOURCES += \
        main.cpp \
        mainWindow.cpp
RESOURCES += \
        AssignI3.qrc


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/mainwindows/AssignI3
INSTALLS += target
