#ifndef START_COMMAND_H
#define START_COMMAND_H

#include "Command.h"

class Machine;

class StartCommand : public Command
{
public:
    explicit StartCommand(Machine& machine);

    void execute() override;

private:
    Machine& machine;
};

#endif