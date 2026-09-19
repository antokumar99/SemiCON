#ifndef PRESSURE_SENSOR_H
#define PRESSURE_SENSOR_H

#include "Sensor.h"

class PressureSensor : public Sensor
{
public:
    PressureSensor();

    double read() override;

private:
    double pressure;
};

#endif