#ifndef MACHINE_CONTROLLER_H
#define MACHINE_CONTROLLER_H

#include <memory>

#include "../command/Command.h"
#include "../machine/Machine.h"
#include "../monitoring/SensorMonitor.h"

class MachineController
{
public:
    MachineController();

    void executeCommand(Command& command);

    void startMachine();
    void stopMachine();
    void resetMachine();

    std::string getMachineStatus() const;

private:
    void synchronizeMonitoring();

    Machine machine;
    SensorMonitor monitor;
};

#endif