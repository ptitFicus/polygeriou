#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog( QWidget * parent) :
QDialog(parent),
ui(new Ui::AboutDialog) {

    ui->setupUi(this);

    // perform additional setup here ...
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

Ui::AboutDialog* AboutDialog::getUi()
{
    return ui;
}
