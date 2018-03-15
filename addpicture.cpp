#include "addpicture.h"
#include "ui_addpicture.h"

AddPicture::AddPicture(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddPicture)
{
    ui->setupUi(this);
}

AddPicture::~AddPicture()
{
    delete ui;
}
