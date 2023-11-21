include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)


QT += quick pdf

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += source \
                ../lib/source
SOURCES += \
        source/main.cpp

RESOURCES += views.qrc \
    assets.qrc \
    components.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH += $$PWD
QML_IMPORT_TRACE += 1
message(QML_IMPORT_PATH: $${QML_IMPORT_PATH})


LIBS += -L$$PWD/../binaries/$$DESTINATION_PATH -l lib

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui

message(UI output dir: $${DESTDIR} )

INCLUDEPATH += /usr/include/poppler/qt6
LIBS += -lpoppler-qt6

DISTFILES +=
