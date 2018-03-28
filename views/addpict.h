#ifndef ADDPICT_H
#define ADDPICT_H

#include <QDialog>

namespace Ui {
class AddPict;
}

class AddPict : public QDialog
{
    Q_OBJECT

public:
    explicit AddPict(QWidget *parent = 0);
    ~AddPict();

private:
    Ui::AddPict *ui;
};

#endif // ADDPICT_H
