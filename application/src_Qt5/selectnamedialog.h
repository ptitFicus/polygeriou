#ifndef SELECTNAMEDIALOG_H
#define SELECTNAMEDIALOG_H

#include <QDialog>

namespace Ui {
class SelectNameDialog;
}

class SelectNameDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SelectNameDialog(QWidget *parent = 0);
    ~SelectNameDialog();
    Ui::SelectNameDialog *getUi();
private:
    Ui::SelectNameDialog *ui;
};

#endif // SELECTNAMEDIALOG_H
