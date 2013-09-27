/********************************************************************************
** Form generated from reading UI file 'dictionnarymanager.ui'
**
** Created: Thu 21. Mar 15:56:51 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DICTIONNARYMANAGER_H
#define UI_DICTIONNARYMANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DictionnaryManager
{
public:
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QComboBox *dictionnaires;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QListWidget *mots;
    QListWidget *definitions;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DictionnaryManager)
    {
        if (DictionnaryManager->objectName().isEmpty())
            DictionnaryManager->setObjectName(QString::fromUtf8("DictionnaryManager"));
        DictionnaryManager->resize(403, 312);
        verticalLayout_5 = new QVBoxLayout(DictionnaryManager);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(10, 20, 10, 10);
        label = new QLabel(DictionnaryManager);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMargin(0);

        verticalLayout_4->addWidget(label);

        dictionnaires = new QComboBox(DictionnaryManager);
        dictionnaires->setObjectName(QString::fromUtf8("dictionnaires"));

        verticalLayout_4->addWidget(dictionnaires);


        horizontalLayout_3->addLayout(verticalLayout_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setContentsMargins(10, 10, 10, 10);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pushButton_4 = new QPushButton(DictionnaryManager);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout_3->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(DictionnaryManager);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout_3->addWidget(pushButton_5);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_5->addLayout(verticalLayout);

        label_2 = new QLabel(DictionnaryManager);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_5->addWidget(label_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        mots = new QListWidget(DictionnaryManager);
        mots->setObjectName(QString::fromUtf8("mots"));

        horizontalLayout_4->addWidget(mots);

        definitions = new QListWidget(DictionnaryManager);
        definitions->setObjectName(QString::fromUtf8("definitions"));

        horizontalLayout_4->addWidget(definitions);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer);

        pushButton_3 = new QPushButton(DictionnaryManager);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout_2->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(DictionnaryManager);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(DictionnaryManager);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);


        horizontalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_5->addLayout(horizontalLayout_4);

        buttonBox = new QDialogButtonBox(DictionnaryManager);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        verticalLayout_5->addWidget(buttonBox);


        retranslateUi(DictionnaryManager);

        QMetaObject::connectSlotsByName(DictionnaryManager);
    } // setupUi

    void retranslateUi(QDialog *DictionnaryManager)
    {
        DictionnaryManager->setWindowTitle(QApplication::translate("DictionnaryManager", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DictionnaryManager", "Choix du dictionnaire", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("DictionnaryManager", "Importer", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("DictionnaryManager", "Supprimer", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DictionnaryManager", "Mots du dictionnaire s\303\251l\303\251ctionn\303\251", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("DictionnaryManager", "Ajouter", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("DictionnaryManager", "Modifier", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("DictionnaryManager", "Supprimer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DictionnaryManager: public Ui_DictionnaryManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DICTIONNARYMANAGER_H
