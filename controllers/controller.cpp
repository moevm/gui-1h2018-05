#include "controller.h"

Controller::Controller(QObject *parent) :
    QObject(parent)
{
    //QString path = QFileDialog::getOpenFileName(this, "Open DataBase", "");
    dataBaseAdapter = new DataBaseAdapter("/Qt/ArtistGallery/database.db", this);

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

QList<std::pair<QString, QString> > Controller::getAllAdmins()
{
    QList<std::pair<QString, QString> > result;
    QStringList logins = dataBaseAdapter->readFromTable("login", "Users");
    QStringList passwords = dataBaseAdapter->readFromTable("password", "Users");
    size_t length = std::min(logins.size(), passwords.size());
    for(size_t i = 0; i < length; i++)
    {
        std::pair<QString, QString> tmp = std::make_pair(logins[i], passwords[i]);
        result.push_back(tmp);
    }
    return result;
}

QStringList Controller::getAllArtists()
{
    return dataBaseAdapter->readFromTable("fio", "Artists");
}

void Controller::addArtist(QString style, QString fio)
{
    dataBaseAdapter->insertData("fio", fio, "Artists");
    QString request = "INSERT INTO ArtistsAndStyles (artist, style) VALUES ('" + fio + "', " + "'" + style + "');";
    dataBaseAdapter->runSQL(request);
}

void Controller::addPicture(QString title, QString author, QString code, QString year, QString originPath)
{
    qDebug() << QFile::copy(originPath, QDir::currentPath() + "/images/" + code + ".jpg");

    QString request = QString("INSERT INTO Pictures (title, author, path, code, year) VALUES ('" +
            title + "', '" + author + "', '" + code + ".jpg', " + code + ", '" + year + "');");
    dataBaseAdapter->runSQL(request);
}
