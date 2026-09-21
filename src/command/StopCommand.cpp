#include "StopCommand.h"

#include "../machine/Machine.h"

StopCommand::StopCommand(Machine& machine)
    : machine(machine)
{
}

void StopCommand::execute()
{
    machine.stop();
}