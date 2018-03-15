#ifndef ADDPICTURE_H
#define ADDPICTURE_H

#include <QMainWindow>

namespace Ui {
class AddPicture;
}

class AddPicture : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddPicture(QWidget *parent = 0);
    ~AddPicture();

private:
    Ui::AddPicture *ui;
};

#endif // ADDPICTURE_H
