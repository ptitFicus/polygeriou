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


SOURCES += main.cpp\
        mainwindow.cpp \
    squarescene.cpp \
    mainwindowcontroller.cpp \
    dictionnarymanagerdialogcontroller.cpp \
    dictionnarymanagerdialog.cpp \
    DictionnaryManager.cpp \
    Dictionnary.cpp \
    newgamedialog.cpp \
    newgamedialogcontroller.cpp \
    selectnamedialog.cpp \
    normalisersaisie.cpp \
    DefinitionSquare.cpp \
    Grid.cpp \
    Node.cpp \
    Square.cpp \
    StandardSquare.cpp \
    Word.cpp

HEADERS  += mainwindow.h \
    ui_dictionnarymanager.h \
    squarescene.h \
    mainwindowcontroller.h \
    dictionnarymanagerdialogcontroller.h \
    dictionnarymanagerdialog.h \
    DictionnaryManager.h \
    Dictionnary.h \
    newgamedialog.h \
    newgamedialogcontroller.h \
    selectnamedialog.h \
    normalisersaisie.h \
    DefinitionSquare.h \
    Grid.h \
    Node.h \
    Square.h \
    StandardSquare.h \
    Word.h

OTHER_FILES += \
    dictionnaire_parse.txt \
    polygeriou_fr.ts \
    polygeriou_en.ts \
    polygeriou_br.ts

 TRANSLATIONS    = polygeriou_fr.ts \
                   polygeriou_br.ts \
                   polygeriou_en.ts

FORMS += \
    newgamedialog.ui \
    mainwindow.ui \
    dictionnarymanagerdialog.ui \
    selectnamedialog.ui
