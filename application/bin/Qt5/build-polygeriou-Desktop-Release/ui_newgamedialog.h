/********************************************************************************
** Form generated from reading UI file 'newgamedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWGAMEDIALOG_H
#define UI_NEWGAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewGameDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFormLayout *formLayout;
    QLabel *hauteurLabel;
    QSpinBox *spinBox;
    QLabel *largeurLabel;
    QSpinBox *largeurSpinBox;
    QLabel *label_2;
    QListWidget *listWidget;

    void setupUi(QDialog *NewGameDialog)
    {
        if (NewGameDialog->objectName().isEmpty())
            NewGameDialog->setObjectName(QStringLiteral("NewGameDialog"));
        NewGameDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(NewGameDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(NewGameDialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 361, 220));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        hauteurLabel = new QLabel(verticalLayoutWidget);
        hauteurLabel->setObjectName(QStringLiteral("hauteurLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, hauteurLabel);

        spinBox = new QSpinBox(verticalLayoutWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBox);

        largeurLabel = new QLabel(verticalLayoutWidget);
        largeurLabel->setObjectName(QStringLiteral("largeurLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, largeurLabel);

        largeurSpinBox = new QSpinBox(verticalLayoutWidget);
        largeurSpinBox->setObjectName(QStringLiteral("largeurSpinBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, largeurSpinBox);


        verticalLayout->addLayout(formLayout);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        listWidget = new QListWidget(verticalLayoutWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(listWidget);


        retranslateUi(NewGameDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewGameDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewGameDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewGameDialog);
    } // setupUi

    void retranslateUi(QDialog *NewGameDialog)
    {
        NewGameDialog->setWindowTitle(QApplication::translate("NewGameDialog", "Dialog", 0));
        label->setText(QApplication::translate("NewGameDialog", "Dimensions de la grille :", 0));
        hauteurLabel->setText(QApplication::translate("NewGameDialog", "Hauteur", 0));
        largeurLabel->setText(QApplication::translate("NewGameDialog", "Largeur", 0));
        label_2->setText(QApplication::translate("NewGameDialog", "Choix des dictionnaires :", 0));
    } // retranslateUi

};

namespace Ui {
    class NewGameDialog: public Ui_NewGameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWGAMEDIALOG_H
