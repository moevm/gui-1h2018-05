#ifndef ADDARTISTDIALOG_H
#define ADDARTISTDIALOG_H

#include <QDialog>

#include "controllers/controller.h"

namespace Ui {
class AddArtistDialog;
}

class AddArtistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddArtistDialog(Controller* controller, QWidget *parent = 0);
    ~AddArtistDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddArtistDialog *ui;
    Controller* m_controller;
};

#endif // ADDARTISTDIALOG_H
