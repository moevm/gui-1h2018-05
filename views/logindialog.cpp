#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(Controller *controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog),
    m_controller(controller)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_buttonBox_accepted()
{
    QString login = ui->loginLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    bool accept = false;
    QList< std::pair<QString, QString> > admins = m_controller->getAllAdmins();
    for(auto admin : admins)
    {
        if((admin.first == login) && (admin.second == password))
        {
            accept = true;
            break;
        }
    }
    if(accept)
    {
        AdminDialog(m_controller, this).exec();
    }
    else
    {
        QMessageBox(QMessageBox::Information, "Информация", "Доступ запрещен").exec();
    }
}
