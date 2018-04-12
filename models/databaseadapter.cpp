#include "databaseadapter.h"

DataBaseAdapter::DataBaseAdapter(QString path, QObject *parent) :
    QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
}

DataBaseAdapter::~DataBaseAdapter()
{
    db.close();
}

void DataBaseAdapter::open()
{
    if(!db.open())
    {
        qDebug() << "db is not open";
        emit databaseIsNotOpen();
    }
    else
    {
        qDebug() << "db is open";
        emit databaseIsOpen();
    }
}

QStringList DataBaseAdapter::readFromTable(QString data, QString tableName)
{
    QStringList response;
    QString request = "SELECT " + data + " FROM " + tableName + ";";
    //qDebug() << request;
    QSqlQuery query;
    if(query.prepare(request))
    {
        if(query.exec())
        {
            if(query.lastError().text() != " ")
            {
                qDebug() << query.lastError().text();
            }
            while (query.next())
            {
                QString parametr = query.value(0).toString();
                response.push_back(parametr);
            }
        }
        else
        {
            QMessageBox(QMessageBox::Warning, "Ошибка", "Не могу выполнить запрос!");
        }
    }
    else
    {
        QMessageBox(QMessageBox::Warning, "Ошибка", "Не могу подготовить запрос!");
    }
    return response;
}

QStringList DataBaseAdapter::readFromTable(QString data, QString tableName, QString condition)
{
    QStringList response;
    QString request = "SELECT " + data + " FROM " + tableName + " WHERE " + condition + ";";
    qDebug() << request;
    QSqlQuery query;
    if(query.prepare(request))
    {
        if(query.exec())
        {
            if(query.lastError().text() != " ")
            {
                qDebug() << query.lastError().text();
            }
            while (query.next())
            {
                QString parametr = query.value(0).toString();
                response.push_back(parametr);
            }
        }
        else
        {
            QMessageBox(QMessageBox::Warning, "Ошибка", "Не могу выполнить запрос!");
        }
    }
    else
    {
        QMessageBox(QMessageBox::Warning, "Ошибка", "Не могу подготовить запрос!");
    }
    return response;
}

void DataBaseAdapter::insertData(QString column, QString value, QString tableName)
{
    QStringList response;
    QString request = "INSERT INTO " + tableName + " (" + column + ") VALUES ('" + value + "');";
    qDebug() << request;
    QSqlQuery query;
    if(query.prepare(request))
    {
        if(query.exec())
        {
            if(query.lastError().text() != " ")
            {
                qDebug() << query.lastError().text();
            }
            while (query.next())
            {
                QString parametr = query.value(0).toString();
                response.push_back(parametr);
            }
        }
        else
        {
            QMessageBox(QMessageBox::Warning, "Ошибка", "Не могу выполнить запрос!");
        }
    }
    else
    {
        QMessageBox(QMessageBox::Warning, "Ошибка", "Не могу подготовить запрос!");
    }
    qDebug() << "response" << response;
}

QSqlQuery DataBaseAdapter::runSQL(QString request)
{
    qDebug() << request;
    QString tmp = request;
    QSqlQuery query;
    if(query.prepare(tmp))
    {
        if(query.exec())
        {
            if(query.lastError().text() != " ")
            {
                qDebug() << query.lastError().text();
            }
        }
        else
        {
            QMessageBox(QMessageBox::Warning, "Ошибка", "Не могу выполнить запрос!");
        }
    }
    else
    {
        QMessageBox(QMessageBox::Warning, "Ошибка", "Не могу подготовить запрос!");
    }
    emit databaseStateIsChanged();
    return query;
}
