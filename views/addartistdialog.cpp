#include "addartistdialog.h"
#include "ui_addartistdialog.h"

AddArtistDialog::AddArtistDialog(Controller *controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddArtistDialog),
    m_controller(controller)
{
    ui->setupUi(this);

    ui->styleComboBox->addItems(m_controller->getAllStyles());
}

AddArtistDialog::~AddArtistDialog()
{
    delete ui;
}

void AddArtistDialog::on_buttonBox_accepted()
{
    m_controller->addArtist(ui->styleComboBox->currentText(), ui->artistLineEdit->text());
}
