#include "newgamedialog.h"
#include "ui_newgamedialog.h"

NewGameDialog::NewGameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGameDialog)
{
    ui->setupUi(this);

    width_box = ui->largeurSpinBox;
    height_box = ui->spinBox;


    width_box->setValue(3);
    height_box->setValue(3);

    width_box->setMinimum(3);
    height_box->setMinimum(3);

    QDialogButtonBox* buttonBox = ui->buttonBox;
    validation_button = buttonBox->button(QDialogButtonBox::Ok);
    cancel_button = buttonBox->button(QDialogButtonBox::Cancel);
    validation_button->setEnabled(false);
}

Ui::NewGameDialog* NewGameDialog::getUi()
{
    return ui;
}

QListWidget* NewGameDialog::getDictionnaryList()
{
    return ui->listWidget;
}

QSpinBox* NewGameDialog::getHeightBox()
{
    return height_box;
}

QSpinBox* NewGameDialog::getWidthBox()
{
    return width_box;
}

NewGameDialog::~NewGameDialog()
{
    delete ui;
}
