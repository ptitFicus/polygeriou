#ifndef NEWGAMEDIALOG_H
#define NEWGAMEDIALOG_H

#include <QDialog>
#include <QSpinBox>
#include <QAbstractButton>
#include <QDialogButtonBox>
#include <QObject>
#include <QListWidget>
#include <QPushButton>

namespace Ui {
class NewGameDialog;
}

class NewGameDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit NewGameDialog(QWidget *parent = 0);
    ~NewGameDialog();
    inline QPushButton* getCancelButton(){return cancel_button;}
    inline QPushButton* getValidationButton(){return validation_button;}
    QSpinBox* getWidthBox();
    QSpinBox* getHeightBox();
    QListWidget* getDictionnaryList();
    Ui::NewGameDialog* getUi();

private:
    Ui::NewGameDialog *ui;
    QSpinBox* width_box;
    QSpinBox* height_box;
    QPushButton* validation_button;
    QPushButton* cancel_button;
};

#endif // NEWGAMEDIALOG_H
