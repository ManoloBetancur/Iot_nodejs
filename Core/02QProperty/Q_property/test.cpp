#include "test.h"


Test::Test(QObject *parent)
    : QObject{parent}
{

}

QString Test::msg() const
{
    return m_msg;
}

void Test::setMsg(const QString &msg)
{
    m_msg = msg;
    emit msgChanged(m_msg);
}
