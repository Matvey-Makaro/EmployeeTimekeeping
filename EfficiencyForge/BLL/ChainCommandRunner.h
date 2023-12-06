#pragma once

#include "ICommandRunner.h"

class ChainCommandRunner : public ICommandRunner
{
    Q_OBJECT
public:
    ChainCommandRunner(QObject* parent = nullptr);
    ~ChainCommandRunner() = default;

    void SetDeleteOnFinished(bool);
    void AddCommand(ICommandShp);
    void WriteLog(ILogger&) override;
    void Run() override;
    void Reset() override;

private slots:
    void OnCommandFinished();
    void OnCommandFailed();
    void SetCurrentCommand(int);

private:
    QVector<ICommandShp> _commands;
    int _currTaskIndex;
    bool _deleteOnFinish;
};
using ChainCommandRunnerShp = QSharedPointer<ChainCommandRunner>;
