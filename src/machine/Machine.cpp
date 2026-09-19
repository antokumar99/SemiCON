#include "Machine.h"

#include <iostream>

#include "../sensor/TemperatureSensor.h"
#include "../sensor/PressureSensor.h"
#include "../sensor/MotorSensor.h"

Machine::Machine()
    : status("IDLE")
{
    sensors.push_back(std::make_unique<TemperatureSensor>());
    sensors.push_back(std::make_unique<PressureSensor>());
    sensors.push_back(std::make_unique<MotorSensor>());
}

void Machine::start()
{
    status = "RUNNING";
}

void Machine::stop()
{
    status = "STOPPED";
}

void Machine::reset()
{
    status = "IDLE";
}

std::string Machine::getStatus() const
{
    return status;
}

void Machine::readSensors()
{
    std::cout << "\n--- Sensor Readings ---\n";

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