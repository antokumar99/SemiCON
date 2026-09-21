#include "ResetCommand.h"

#include "../machine/Machine.h"

ResetCommand::ResetCommand(Machine& machine)
    : machine(machine)
{
}

void ResetCommand::execute()
{
    machine.reset();
}