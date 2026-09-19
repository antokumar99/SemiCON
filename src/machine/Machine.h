#ifndef MACHINE_H
#define MACHINE_H

#include <memory>
#include <string>
#include <vector>

#include "../sensor/Sensor.h"

class Machine
{
public:
    Machine();

    void start();
    void stop();
    void reset();

    std::string getStatus() const;

    void readSensors();

private:
    std::string status;

    std::vector<std::unique_ptr<Sensor>> sensors;
};

#endif