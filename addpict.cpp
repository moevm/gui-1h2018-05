#include "addpict.h"
#include "ui_addpict.h"

AddPict::AddPict(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPict)
{
    ui->setupUi(this);
}

AddPict::~AddPict()
{
    delete ui;
}
