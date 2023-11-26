#include <QRegExp>
#include "AuthorizationUtils.h"

bool IsLoginCorrect(const QString &login)
{
    QRegExp regExp("/^[a-z0-9_-]{3,16}$/");
    return regExp.exactMatch(login);
}

bool IsPasswordCorrect(const QString &password)
{
    QRegExp regExp("/^(?=.*[A-Z].*[A-Z])(?=.*[!@#$&*])(?=.*[0-9].*[0-9])(?=.*[a-z].*[a-z].*[a-z]).{8,}$/");
    return regExp.exactMatch(password);
}
