#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "Sensor.h"

class TemperatureSensor : public Sensor
{
public:
    TemperatureSensor();

    double read() override;

private:
    double temperature;
};

#endif