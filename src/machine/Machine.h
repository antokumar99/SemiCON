#ifndef MACHINE_H
#define MACHINE_H

#include <memory>
#include <string>
#include <vector>

#include "../sensor/Sensor.h"
#include "../state/MachineState.h"

class Machine
{
public:
    Machine();

    void start();
    void stop();
    void reset();

    std::string getStatus() const;

    void readSensors();

    void changeState(std::unique_ptr<MachineState> newState);

private:
    std::unique_ptr<MachineState> currentState;

    std::vector<std::unique_ptr<Sensor>> sensors;
};

#endif