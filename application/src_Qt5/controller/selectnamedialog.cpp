#include "selectnamedialog.h"
#include "ui_selectnamedialog.h"

SelectNameDialog::SelectNameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectNameDialog)
{
    ui->setupUi(this);
}

SelectNameDialog::~SelectNameDialog()
{
    delete ui;
}

Ui::SelectNameDialog* SelectNameDialog::getUi(){
    return ui;
}
