#include "admindialog.h"
#include "ui_admindialog.h"

AdminDialog::AdminDialog(Controller *controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminDialog),
    m_controller(controller)
{
    ui->setupUi(this);
}

AdminDialog::~AdminDialog()
{
    delete ui;
}

void AdminDialog::on_addPicturePushButton_clicked()
{
    AddPict(m_controller, this).exec();
}

void AdminDialog::on_addArtistPushButton_clicked()
{
    AddArtistDialog(m_controller, this).exec();
}
