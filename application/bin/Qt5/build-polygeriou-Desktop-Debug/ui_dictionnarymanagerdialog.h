/********************************************************************************
** Form generated from reading UI file 'dictionnarymanagerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DICTIONNARYMANAGERDIALOG_H
#define UI_DICTIONNARYMANAGERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DictionnaryManagerDialog
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
    QPushButton *boutonImporter;
    QPushButton *boutonSupprimer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *definitions;
    QLineEdit *lineEdit;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *createDictionnary;
    QPushButton *addWord;
    QPushButton *deleteWord;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DictionnaryManagerDialog)
    {
        if (DictionnaryManagerDialog->objectName().isEmpty())
            DictionnaryManagerDialog->setObjectName(QStringLiteral("DictionnaryManagerDialog"));
        DictionnaryManagerDialog->resize(403, 312);
        verticalLayout_5 = new QVBoxLayout(DictionnaryManagerDialog);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(10, 20, 10, 10);
        label = new QLabel(DictionnaryManagerDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setMargin(0);

        verticalLayout_4->addWidget(label);

        dictionnaires = new QComboBox(DictionnaryManagerDialog);
        dictionnaires->setObjectName(QStringLiteral("dictionnaires"));

        verticalLayout_4->addWidget(dictionnaires);


        horizontalLayout_3->addLayout(verticalLayout_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setContentsMargins(10, 10, 10, 10);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        boutonImporter = new QPushButton(DictionnaryManagerDialog);
        boutonImporter->setObjectName(QStringLiteral("boutonImporter"));

        verticalLayout_3->addWidget(boutonImporter);

        boutonSupprimer = new QPushButton(DictionnaryManagerDialog);
        boutonSupprimer->setObjectName(QStringLiteral("boutonSupprimer"));

        verticalLayout_3->addWidget(boutonSupprimer);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_5->addLayout(verticalLayout);

        label_2 = new QLabel(DictionnaryManagerDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_5->addWidget(label_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        definitions = new QTableWidget(DictionnaryManagerDialog);
        if (definitions->columnCount() < 2)
            definitions->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        definitions->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        definitions->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        definitions->setObjectName(QStringLiteral("definitions"));
        definitions->verticalHeader()->setVisible(false);

        verticalLayout_6->addWidget(definitions);

        lineEdit = new QLineEdit(DictionnaryManagerDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout_6->addWidget(lineEdit);


        horizontalLayout_4->addLayout(verticalLayout_6);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        createDictionnary = new QPushButton(DictionnaryManagerDialog);
        createDictionnary->setObjectName(QStringLiteral("createDictionnary"));

        verticalLayout_2->addWidget(createDictionnary);

        addWord = new QPushButton(DictionnaryManagerDialog);
        addWord->setObjectName(QStringLiteral("addWord"));

        verticalLayout_2->addWidget(addWord);

        deleteWord = new QPushButton(DictionnaryManagerDialog);
        deleteWord->setObjectName(QStringLiteral("deleteWord"));

        verticalLayout_2->addWidget(deleteWord);


        horizontalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_5->addLayout(horizontalLayout_4);

        buttonBox = new QDialogButtonBox(DictionnaryManagerDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        buttonBox->setCenterButtons(true);

        verticalLayout_5->addWidget(buttonBox);


        retranslateUi(DictionnaryManagerDialog);

        QMetaObject::connectSlotsByName(DictionnaryManagerDialog);
    } // setupUi

    void retranslateUi(QDialog *DictionnaryManagerDialog)
    {
        DictionnaryManagerDialog->setWindowTitle(QApplication::translate("DictionnaryManagerDialog", "Dialog", 0));
        label->setText(QApplication::translate("DictionnaryManagerDialog", "Choix du dictionnaire", 0));
        boutonImporter->setText(QApplication::translate("DictionnaryManagerDialog", "Importer", 0));
        boutonSupprimer->setText(QApplication::translate("DictionnaryManagerDialog", "Supprimer", 0));
        label_2->setText(QApplication::translate("DictionnaryManagerDialog", "Mots du dictionnaire s\303\251l\303\251ctionn\303\251", 0));
        QTableWidgetItem *___qtablewidgetitem = definitions->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DictionnaryManagerDialog", "Mots", 0));
        QTableWidgetItem *___qtablewidgetitem1 = definitions->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("DictionnaryManagerDialog", "D\303\251finitions", 0));
        createDictionnary->setText(QApplication::translate("DictionnaryManagerDialog", "Creer dictionnaire", 0));
        addWord->setText(QApplication::translate("DictionnaryManagerDialog", "Ajouter", 0));
        deleteWord->setText(QApplication::translate("DictionnaryManagerDialog", "Supprimer", 0));
    } // retranslateUi

};

namespace Ui {
    class DictionnaryManagerDialog: public Ui_DictionnaryManagerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DICTIONNARYMANAGERDIALOG_H
