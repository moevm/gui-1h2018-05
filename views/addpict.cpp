#include "addpict.h"
#include "ui_addpict.h"

AddPict::AddPict(Controller *controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPict),
    m_controller(controller),
    m_imagePath("")
{
    ui->setupUi(this);

    ui->comboBox->addItems(m_controller->getAllArtists());
}

AddPict::~AddPict()
{
    delete ui;
}

void AddPict::on_backGame_clicked()
{
    std::random_device rd;
    std::mt19937 random(rd());

    std::uniform_int_distribution<int> uid(1, INT32_MAX);
    QString code = QString::number(uid(random));
    m_controller->addPicture(ui->titleLineEdit->text(),
                             ui->comboBox->currentText(),
                             code,
                             ui->yearTextEdit->toPlainText(),
                             m_imagePath);
}

void AddPict::on_pushButton_clicked()
{
    m_imagePath =  QFileDialog::getOpenFileName( this, "Выберите изображение" ,
                                                 "", "Все файлы (*.jpg)" );
    qDebug() << m_imagePath;
}
