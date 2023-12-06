#include "ChainCommandRunner.h"

ChainCommandRunner::ChainCommandRunner(QObject* parent) :
    ICommandRunner(parent),
    _commands(),
    _currTaskIndex(-1),
    _deleteOnFinish(false)
{
    connect(this, &ChainCommandRunner::Finished, this,
            [this]()
    {
        if(_deleteOnFinish)
            this->deleteLater();
    });
}

void ChainCommandRunner::SetDeleteOnFinished(bool val)
{
    _deleteOnFinish = val;
}

void ChainCommandRunner::AddCommand(ICommandShp cmd)
{
    _commands.push_back(std::move(cmd));
}

void ChainCommandRunner::WriteLog(ILogger& logger)
{
    for(const auto& c : qAsConst(_commands))
        c->WriteLog(logger);
}

void ChainCommandRunner::Run()
{
    if(_commands.empty())
    {
        Reset();
        emit Finished();
    }
    else
    {
        SetCurrentCommand(0);
    }
}

void ChainCommandRunner::Reset()
{
    _currTaskIndex = -1;
    _commands.clear();
}

void ChainCommandRunner::OnCommandFinished()
{
    int nextTask = _currTaskIndex + 1;
    auto cmd = _commands.at(_currTaskIndex);
    if(nextTask < _commands.count())
    {
        SetCurrentCommand(nextTask);
    }
    else
    {
        emit Finished();
    }
}

void ChainCommandRunner::OnCommandFailed()
{
    auto cmd = _commands.at(_currTaskIndex);
    emit Failed(cmd);
}

void ChainCommandRunner::SetCurrentCommand(int idx)
{
    if(idx >= _commands.size())
        return;
    if(idx <= -1)
    {
        _currTaskIndex = idx;
        return;
    }

    _currTaskIndex = idx;
    const auto& cmd = _commands.at(idx);
    if(cmd.isNull())
        return;
    if(!cmd->Validate())
    {
        OnCommandFailed();
        return;
    }
    connect(cmd.data(), &ICommand::Finished, this, &ChainCommandRunner::OnCommandFinished);
    connect(cmd.data(), &ICommand::Failed, this, &ChainCommandRunner::OnCommandFailed);
    cmd->Do();
}
