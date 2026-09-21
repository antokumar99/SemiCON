#ifndef RESET_COMMAND_H
#define RESET_COMMAND_H

#include "Command.h"

class Machine;

class ResetCommand : public Command
{
public:
    explicit ResetCommand(Machine& machine);

    void execute() override;

private:
    Machine& machine;
};

#endif