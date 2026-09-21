#include "Machine.h"

#include <iostream>

#include "../sensor/TemperatureSensor.h"
#include "../sensor/PressureSensor.h"
#include "../sensor/MotorSensor.h"

#include "../state/IdleState.h"

Machine::Machine()
{
    currentState = std::make_unique<IdleState>();

    sensors.push_back(
        std::make_unique<TemperatureSensor>()
    );

    sensors.push_back(
        std::make_unique<PressureSensor>()
    );

    sensors.push_back(
        std::make_unique<MotorSensor>()
    );
}

void Machine::start()
{
    currentState->start(*this);
}

void Machine::stop()
{
    currentState->stop(*this);
}

void Machine::reset()
{
    currentState->reset(*this);
}

std::string Machine::getStatus() const
{
    return currentState->getName();
}

void Machine::changeState(
    std::unique_ptr<MachineState> newState
)
{
    currentState = std::move(newState);
}

void Machine::readSensors()
{
    std::cout << "\n--- Machine Sensor Readings ---\n";

    for (const auto& sensor : sensors)
    {
        double value = sensor->read();

        std::cout << sensor->getName()
                  << ": "
                  << value
                  << " "
                  << sensor->getUnit()
                  << '\n';
    }
}