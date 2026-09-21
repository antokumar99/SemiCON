#include "MachineController.h"

#include "../command/ResetCommand.h"
#include "../command/StartCommand.h"
#include "../command/StopCommand.h"

MachineController::MachineController()
{
}

void MachineController::executeCommand(Command& command)
{
    command.execute();

    synchronizeMonitoring();
}

void MachineController::startMachine()
{
    StartCommand command(machine);

    executeCommand(command);
}

void MachineController::stopMachine()
{
    StopCommand command(machine);

    executeCommand(command);
}

void MachineController::resetMachine()
{
    ResetCommand command(machine);

    executeCommand(command);
}

std::string MachineController::getMachineStatus() const
{
    return machine.getStatus();
}

void MachineController::synchronizeMonitoring()
{
    if (machine.getStatus() == "RUNNING")
    {
        monitor.start();
    }
    else
    {
        monitor.stop();
    }
}