#include "DB.h"

DB* DB::_instance = nullptr;
DBSettings DB::_settings = {};

void DB::Configure(DBSettings settings)
{
    DB::_settings = std::move(settings);
}

DB* DB::GetInstance()
{
    if(!_instance)
    {
        _instance = new DB();
    }
    return _instance;
}

const QSqlDatabase& DB::GetQSqlDatabase()
{
    auto i = GetInstance();
    return i->_db;
}

bool DB::IsOpen() const
{
    return _db.isOpen();
}

std::optional<QSqlRecord> DB::MakeQuery(const QString& queryStr)
{
    if(_query.exec(queryStr))
        return _query.record();
    else return std::nullopt;
}

DB::DB()
{
    CreateConnection();
}

bool DB::CreateConnection()
{
    _db = QSqlDatabase::addDatabase("QMYSQL");
    _db.setDatabaseName(_settings.Name);
    _db.setUserName(_settings.UserName);
    _db.setHostName(_settings.HostName);
    _db.setPassword(_settings.Password);
    _db.setPort(_settings.Port);
    return _db.open();
}
