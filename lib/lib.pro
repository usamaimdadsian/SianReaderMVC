include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)


QT -= gui

QT += sql \
    quick

TARGET = lib
TEMPLATE = lib
DEFINES += LIB_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += source

SOURCES += \
    source/controllers/book_controller.cpp \
    source/controllers/command_controller.cpp \
    source/controllers/database_controller.cpp \
    source/controllers/master_controller.cpp \
    source/data/data_decorator.cpp \
    source/data/datetime_decorator.cpp \
    source/data/entity.cpp \
    source/data/enumerator_decorator.cpp \
    source/data/float_decorator.cpp \
    source/data/int_decorator.cpp \
    source/data/string_decorator.cpp \
    source/framework/command.cpp \
    source/models/audiobook.cpp \
    source/models/audiotrack.cpp \
    source/models/book.cpp \
    source/models/pdfbook.cpp \
#    cryptopp/hex.cpp \
#    cryptopp/sha.cpp

HEADERS += \
    source/controllers/book_controller.h \
    source/controllers/command_controller.h \
    source/controllers/database_controller.h \
    source/controllers/i_database_controller.h \
    source/controllers/navigation_controller.h \
    source/controllers/master_controller.h \
    source/data/data_decorator.h \
    source/data/datetime_decorator.h \
    source/data/entity.h \
    source/data/entity_collection.h \
    source/data/enumerator_decorator.h \
    source/data/float_decorator.h \
    source/data/int_decorator.h \
    source/data/string_decorator.h \
    source/framework/command.h \
    source/lib_global.h \
    source/models/audiobook.h \
    source/models/audiotrack.h \
    source/models/book.h \
    source/models/pdfbook.h \
#    cryptopp/hex.h \
#    cryptopp/sha.h


message(lib project dir: $${PWD})
DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui
message(lib output dir: $${DESTDIR})

INCLUDEPATH += /usr/include/poppler/qt6
LIBS += -lpoppler-qt6
