#pragma once

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include "DBSettings.h"
#include <optional>
#include "memory"

class DB
{
public:
    static void Configure(DBSettings settings);
    static DB* GetInstance();
    static const QSqlDatabase& GetQSqlDatabase();

    DB(const DB& other) = delete;
    DB(DB&& other) = delete;

    DB& operator=(const DB& other) = delete;
    DB& operator=(DB&& other) = delete;

    bool IsOpen() const;

    std::optional<QSqlRecord> MakeQuery(const QString& queryStr);

protected:
    DB();
    bool CreateConnection();

protected:
    static DB* _instance;
    static DBSettings _settings;

    QSqlDatabase _db;
    QSqlQuery _query;
};

