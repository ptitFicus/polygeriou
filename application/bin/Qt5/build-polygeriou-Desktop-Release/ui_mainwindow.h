/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNouvelle_partie;
    QAction *actionCharger_une_partie;
    QAction *actionEnregistrer_partie;
    QAction *actionExporter_grille;
    QAction *actionQuitter;
    QAction *actionCorriger_la_grille;
    QAction *actionVider_la_grille;
    QAction *actionGestion_des_dictionnaire;
    QAction *actionMenu_Aide;
    QAction *actionA_propos;
    QAction *actionV_rifier_la_grille;
    QAction *exportPDF;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *gameLayout_2;
    QGridLayout *gameLayout;
    QListWidget *definitionWidget;
    QMenuBar *menuBar;
    QMenu *menuJeu;
    QMenu *menuPartie;
    QMenu *menuDictionnaires;
    QMenu *menuAide;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(753, 552);
        MainWindow->setAutoFillBackground(false);
        actionNouvelle_partie = new QAction(MainWindow);
        actionNouvelle_partie->setObjectName(QStringLiteral("actionNouvelle_partie"));
        actionCharger_une_partie = new QAction(MainWindow);
        actionCharger_une_partie->setObjectName(QStringLiteral("actionCharger_une_partie"));
        actionEnregistrer_partie = new QAction(MainWindow);
        actionEnregistrer_partie->setObjectName(QStringLiteral("actionEnregistrer_partie"));
        actionExporter_grille = new QAction(MainWindow);
        actionExporter_grille->setObjectName(QStringLiteral("actionExporter_grille"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionCorriger_la_grille = new QAction(MainWindow);
        actionCorriger_la_grille->setObjectName(QStringLiteral("actionCorriger_la_grille"));
        actionVider_la_grille = new QAction(MainWindow);
        actionVider_la_grille->setObjectName(QStringLiteral("actionVider_la_grille"));
        actionGestion_des_dictionnaire = new QAction(MainWindow);
        actionGestion_des_dictionnaire->setObjectName(QStringLiteral("actionGestion_des_dictionnaire"));
        actionMenu_Aide = new QAction(MainWindow);
        actionMenu_Aide->setObjectName(QStringLiteral("actionMenu_Aide"));
        actionA_propos = new QAction(MainWindow);
        actionA_propos->setObjectName(QStringLiteral("actionA_propos"));
        actionV_rifier_la_grille = new QAction(MainWindow);
        actionV_rifier_la_grille->setObjectName(QStringLiteral("actionV_rifier_la_grille"));
        exportPDF = new QAction(MainWindow);
        exportPDF->setObjectName(QStringLiteral("exportPDF"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        gameLayout_2 = new QWidget();
        gameLayout_2->setObjectName(QStringLiteral("gameLayout_2"));
        gameLayout_2->setGeometry(QRect(0, 0, 427, 491));
        gameLayout = new QGridLayout(gameLayout_2);
        gameLayout->setSpacing(0);
        gameLayout->setContentsMargins(11, 11, 11, 11);
        gameLayout->setObjectName(QStringLiteral("gameLayout"));
        gameLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(gameLayout_2);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);

        definitionWidget = new QListWidget(centralWidget);
        definitionWidget->setObjectName(QStringLiteral("definitionWidget"));
        definitionWidget->setMaximumSize(QSize(300, 16777215));

        gridLayout_2->addWidget(definitionWidget, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 753, 21));
        menuJeu = new QMenu(menuBar);
        menuJeu->setObjectName(QStringLiteral("menuJeu"));
        menuPartie = new QMenu(menuBar);
        menuPartie->setObjectName(QStringLiteral("menuPartie"));
        menuDictionnaires = new QMenu(menuBar);
        menuDictionnaires->setObjectName(QStringLiteral("menuDictionnaires"));
        menuAide = new QMenu(menuBar);
        menuAide->setObjectName(QStringLiteral("menuAide"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuJeu->menuAction());
        menuBar->addAction(menuPartie->menuAction());
        menuBar->addAction(menuDictionnaires->menuAction());
        menuBar->addAction(menuAide->menuAction());
        menuJeu->addAction(actionNouvelle_partie);
        menuJeu->addAction(actionCharger_une_partie);
        menuJeu->addAction(actionEnregistrer_partie);
        menuJeu->addAction(actionExporter_grille);
        menuJeu->addAction(exportPDF);
        menuJeu->addAction(actionQuitter);
        menuPartie->addAction(actionV_rifier_la_grille);
        menuPartie->addAction(actionCorriger_la_grille);
        menuPartie->addAction(actionVider_la_grille);
        menuDictionnaires->addAction(actionGestion_des_dictionnaire);
        menuAide->addAction(actionMenu_Aide);
        menuAide->addAction(actionA_propos);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionNouvelle_partie->setText(QApplication::translate("MainWindow", "Nouvelle partie", 0));
        actionCharger_une_partie->setText(QApplication::translate("MainWindow", "Charger une partie", 0));
        actionEnregistrer_partie->setText(QApplication::translate("MainWindow", "Enregistrer partie", 0));
        actionExporter_grille->setText(QApplication::translate("MainWindow", "Exporter grille", 0));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0));
        actionCorriger_la_grille->setText(QApplication::translate("MainWindow", "Corriger la grille", 0));
        actionVider_la_grille->setText(QApplication::translate("MainWindow", "Vider la grille", 0));
        actionGestion_des_dictionnaire->setText(QApplication::translate("MainWindow", "Gestion des dictionnaire", 0));
        actionMenu_Aide->setText(QApplication::translate("MainWindow", "Menu Aide", 0));
        actionA_propos->setText(QApplication::translate("MainWindow", "A propos", 0));
        actionV_rifier_la_grille->setText(QApplication::translate("MainWindow", "V\303\251rifier la grille", 0));
        exportPDF->setText(QApplication::translate("MainWindow", "Export PDF", 0));
#ifndef QT_NO_TOOLTIP
        exportPDF->setToolTip(QApplication::translate("MainWindow", "Exporter en PDF", 0));
#endif // QT_NO_TOOLTIP
        menuJeu->setTitle(QApplication::translate("MainWindow", "Fichier", 0));
        menuPartie->setTitle(QApplication::translate("MainWindow", "Jeu", 0));
        menuDictionnaires->setTitle(QApplication::translate("MainWindow", "Dictionnaires", 0));
        menuAide->setTitle(QApplication::translate("MainWindow", "Aide", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
