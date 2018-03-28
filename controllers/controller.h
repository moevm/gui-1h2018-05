#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QFileDialog>

#include "models/databaseadapter.h"


class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();

protected:
    DataBaseAdapter* dataBaseAdapter;

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
};

#endif // CONTROLLER_H
