#ifndef STOP_COMMAND_H
#define STOP_COMMAND_H

#include "Command.h"

class Machine;

class StopCommand : public Command
{
public:
    explicit StopCommand(Machine& machine);

    void execute() override;

private:
    Machine& machine;
};

#endif