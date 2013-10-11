#ifndef DictionnaryManagerDialog_H
#define DictionnaryManagerDialog_H

#include <QDialog>

namespace Ui {
class DictionnaryManagerDialog;
}

class DictionnaryManagerDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit DictionnaryManagerDialog(QWidget *parent = 0);
    ~DictionnaryManagerDialog();
    Ui::DictionnaryManagerDialog* getUi(void);

private:
    Ui::DictionnaryManagerDialog *ui;
};

#endif // DictionnaryManagerDialog_H
