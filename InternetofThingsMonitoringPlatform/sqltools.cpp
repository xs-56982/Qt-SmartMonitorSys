#include "sqltools.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlError>
int SqlTools::user_id = 0;
QString SqlTools::name = "";
QString SqlTools::pwd = "";
QString SqlTools::email = "";
QString SqlTools::phone = "";
QString SqlTools::nickname = "";
QString SqlTools::role = "";

SqlTools::SqlTools(QObject *parent) : QObject(parent)
{

}

bool SqlTools::connectDataBase()
{
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("D:/Program Files (x86)/sqlite/system.db");
    return database.open();
}

bool SqlTools::queryData(QString name)
{

    QSqlQuery query;
    query.prepare("select * from users where username = ?");
    query.addBindValue(name);
    query.exec();
    return !query.next();
}

bool SqlTools::queryData(QString name,QString pass)
{

    QSqlQuery query;
    query.prepare("select * from users where username = ? and password = ?");
    query.addBindValue(name);
    query.addBindValue(pass);
    query.exec();
    if(!query.next()){
        return false;
    }
    SqlTools::user_id = query.value("id").toInt();
    SqlTools::name = query.value("username").toString();
    SqlTools::pwd = query.value("password").toString();
    SqlTools::email = query.value("email").toString();
    SqlTools::phone = query.value("phone").toString();
    SqlTools::nickname = query.value("nickname").toString();
    SqlTools::role = query.value("role").toString();

    return true;
}

int SqlTools::insertData(QString name, QString pass, QString email, QString phone, QString nickname, QString role)
{

    QSqlQuery query;
    query.prepare("insert into users(username,password,email,phone,nickname,role) values (?,?,?,?,?,?)");
    query.addBindValue(name);
    query.addBindValue(pass);
    query.addBindValue(email);
    query.addBindValue(phone);
    query.addBindValue(nickname);
    query.addBindValue(role);

    if(!query.exec()){
        QSqlError error = query.lastError();
        if(error.text().contains("username")){
            return 0;
        }else if(error.text().contains("email")){
            return -1;
        }else if(error.text().contains("phone")){
            return -2;
        }
    }

    return 1;
}

bool SqlTools::updateData(QString name, QString email_phone, QString pwd)
{
    QSqlQuery query;
    if(email_phone.contains("@")){
        query.prepare("update users set password = ? where username = ? and email = ?");
    }else{
        query.prepare("update users set password = ? where username = ? and phone = ?");
    }
    query.addBindValue(pwd);
    query.addBindValue(name);
    query.addBindValue(email_phone);
    return query.exec();
}

