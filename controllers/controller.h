#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QFileDialog>

#include <chrono>

#include "models/databaseadapter.h"


class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();

protected:
    DataBaseAdapter* dataBaseAdapter;
    std::mt19937 m_random_generator;

signals:
    void dataBaseIsConnected();
    void dataBaseIsDisconnected();

public slots:
    void onDataBaseConnected();
    void onDataBaseDisconnected();
    void openDataBase();

    QStringList getAllStyles();
    QStringList getArtistsByStyle(QString style);
    QStringList getPicturesImagesByArtist(QString artist);
    QStringList getPicturesNamesByArtist(QString artist);
    QString getPictureImageName(QString artist, QString title);
    QString getPictureYear(QString artist, QString title);
    QList< std::pair<QString, QString> > getAllAdmins();
    QStringList getAllArtists();

    void addArtist(QString style, QString fio);
    void addPicture(QString title, QString author, QString code, QString year, QString originPath);
};

#endif // CONTROLLER_H
