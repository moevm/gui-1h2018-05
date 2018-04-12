#ifndef DATABASEADAPTER_H
#define DATABASEADAPTER_H

#include <QObject>
#include <QtSql>
#include <QMessageBox>

class DataBaseAdapter : public QObject
{
    Q_OBJECT
public:
    explicit DataBaseAdapter(QString path, QObject *parent = nullptr);
    ~DataBaseAdapter();

    void open();

protected:
    QSqlDatabase db;

signals:
    void databaseIsOpen();
    void databaseIsNotOpen();
    void databaseStateIsChanged();

public slots:
    QStringList readFromTable(QString data, QString tableName);
    QStringList readFromTable(QString data, QString tableName, QString condition);
    void insertData(QString column, QString value, QString tableName);

    QSqlQuery runSQL(QString request);
};

#endif // DATABASEADAPTER_H
