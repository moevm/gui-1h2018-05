#include "controller.h"

Controller::Controller(QObject *parent) :
    QObject(parent)
{
    //QString path = QFileDialog::getOpenFileName(this, "Open DataBase", "");
    dataBaseAdapter = new DataBaseAdapter("/Qt/gui22/database.db", this);

    connect(dataBaseAdapter, SIGNAL(databaseIsOpen()), this, SLOT(onDataBaseConnected()));
    connect(dataBaseAdapter, SIGNAL(databaseIsNotOpen()), this, SLOT(onDataBaseDisconnected()));
}

Controller::~Controller()
{
    delete dataBaseAdapter;
}

void Controller::onDataBaseConnected()
{
    emit dataBaseIsConnected();
}

void Controller::onDataBaseDisconnected()
{
    emit dataBaseIsDisconnected();
}

void Controller::openDataBase()
{
    dataBaseAdapter->open();
}

QStringList Controller::getAllStyles()
{
    return dataBaseAdapter->readFromTable("title", "Styles");
}

QStringList Controller::getArtistsByStyle(QString style)
{
    QString condition = "style = '" + style + "'";
    return dataBaseAdapter->readFromTable("artist", "ArtistsAndStyles", condition);
}

QStringList Controller::getPicturesImagesByArtist(QString artist)
{
    QString condition = "author = '" + artist + "'";
    return dataBaseAdapter->readFromTable("path", "Pictures", condition);
}

QStringList Controller::getPicturesNamesByArtist(QString artist)
{
    QString condition = "author = '" + artist + "'";
    return dataBaseAdapter->readFromTable("title", "Pictures", condition);
}

QString Controller::getPictureImageName(QString artist, QString title)
{
    QString condition = "author = '" + artist + "' AND title = '" + title + "'";
    return dataBaseAdapter->readFromTable("path", "Pictures", condition).operator [](0);
}

QString Controller::getPictureYear(QString artist, QString title)
{
    QString condition = "author = '" + artist + "' AND title = '" + title + "'";
    return dataBaseAdapter->readFromTable("year", "Pictures", condition).operator [](0);
}
