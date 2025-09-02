#ifndef SQLTOOLS_H
#define SQLTOOLS_H

#include <QObject>

class SqlTools : public QObject
{
    Q_OBJECT
public:

    static int user_id;
    static QString name;
    static QString pwd;
    static QString email;
    static QString phone;
    static QString nickname;
    static QString role;

    explicit SqlTools(QObject *parent = nullptr);
    static bool connectDataBase();
    static bool queryData(QString name);
    static bool queryData(QString name,QString pass);
    static int insertData(QString name,QString pass,QString email,QString phone,QString nickname,QString role = "user");
    static bool updateData(QString name,QString email_phone,QString pwd);

signals:

};

#endif // SQLTOOLS_H
