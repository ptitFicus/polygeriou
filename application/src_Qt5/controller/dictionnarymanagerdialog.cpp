#include <QListWidget>
#include <QComboBox>
#include <QTableWidget>
#include <QTableWidgetItem>

#include "dictionnarymanagerdialog.h"
#include "ui_dictionnarymanagerdialog.h"

DictionnaryManagerDialog::DictionnaryManagerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DictionnaryManagerDialog)
{
    ui->setupUi(this);
}

DictionnaryManagerDialog::~DictionnaryManagerDialog()
{
    delete ui;
}

Ui::DictionnaryManagerDialog* DictionnaryManagerDialog::getUi(void){
    return ui;
}
