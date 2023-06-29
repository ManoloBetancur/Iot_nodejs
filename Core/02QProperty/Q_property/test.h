#ifndef TEST_H
#define TEST_H

#include <QObject>

class Test : public QObject
{
    Q_OBJECT
    QString m_msg; //Private attribute
public:
    explicit Test(QObject *parent = nullptr);

    //Q_PROPERTY(type name READ name WRITE setName NOTIFY nameChanged)
    //Property, getter,and  setter respectively

    Q_PROPERTY(QString property_name READ msg WRITE setMsg NOTIFY msgChanged);

    QString msg() const;
    void setMsg(const QString &msg);

signals:
    void msgChanged(QString msg);
};

#endif // TEST_H
