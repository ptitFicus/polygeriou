#-------------------------------------------------
#
# Project created by QtCreator 2013-05-23T15:52:57
#
#-------------------------------------------------

QT       += core gui \
		printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = polygeriou
QMAKE_CXXFLAGS += -std=c++0x
TEMPLATE = app


SOURCES += \
    controller/main.cpp\
    controller/mainwindow.cpp \
    controller/squarescene.cpp \
    controller/mainwindowcontroller.cpp \
    controller/dictionnarymanagerdialogcontroller.cpp \
    controller/dictionnarymanagerdialog.cpp \
    controller/newgamedialog.cpp \
    controller/newgamedialogcontroller.cpp \
    controller/selectnamedialog.cpp \
    controller/normalisersaisie.cpp \
    model/DictionnaryManager.cpp \
    model/Dictionnary.cpp \
    model/DefinitionSquare.cpp \
    model/Grid.cpp \
    model/Node.cpp \
    model/Square.cpp \
    model/StandardSquare.cpp \
    model/Word.cpp \
    controller/aboutdialog.cpp

HEADERS  += \
    controller/mainwindow.h \
    controller/ui_dictionnarymanager.h \
    controller/squarescene.h \
    controller/mainwindowcontroller.h \
    controller/dictionnarymanagerdialogcontroller.h \
    controller/dictionnarymanagerdialog.h \
    controller/newgamedialog.h \
    controller/newgamedialogcontroller.h \
    controller/selectnamedialog.h \
    controller/normalisersaisie.h \
    model/DictionnaryManager.h \
    model/Dictionnary.h \
    model/DefinitionSquare.h \
    model/Grid.h \
    model/Node.h \
    model/Square.h \
    model/StandardSquare.h \
    model/Word.h \
    controller/aboutdialog.h

OTHER_FILES += \
    translation/polygeriou_fr.ts \
    translation/polygeriou_en.ts \
    translation/polygeriou_br.ts

 TRANSLATIONS    = translation/polygeriou_fr.ts \
                   translation/polygeriou_br.ts \
                   translation/polygeriou_en.ts

FORMS += \
    view/newgamedialog.ui \
    view/mainwindow.ui \
    view/dictionnarymanagerdialog.ui \
    view/selectnamedialog.ui \
    view/aboutdialog.ui

RESOURCES += \
    translation/translations.qrc
