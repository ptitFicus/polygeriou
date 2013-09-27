/********************************************************************************
** Form generated from reading UI file 'selectnamedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTNAMEDIALOG_H
#define UI_SELECTNAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_SelectNameDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SelectNameDialog)
    {
        if (SelectNameDialog->objectName().isEmpty())
            SelectNameDialog->setObjectName(QStringLiteral("SelectNameDialog"));
        SelectNameDialog->resize(400, 62);
        horizontalLayout = new QHBoxLayout(SelectNameDialog);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(SelectNameDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        buttonBox = new QDialogButtonBox(SelectNameDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        retranslateUi(SelectNameDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SelectNameDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SelectNameDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SelectNameDialog);
    } // setupUi

    void retranslateUi(QDialog *SelectNameDialog)
    {
        SelectNameDialog->setWindowTitle(QApplication::translate("SelectNameDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class SelectNameDialog: public Ui_SelectNameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTNAMEDIALOG_H
