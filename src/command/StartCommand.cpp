#include "StartCommand.h"

#include "../machine/Machine.h"

StartCommand::StartCommand(Machine& machine)
    : machine(machine)
{
}

void StartCommand::execute()
{
    machine.start();
}