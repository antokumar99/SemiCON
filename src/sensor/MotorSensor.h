#ifndef MOTOR_SENSOR_H
#define MOTOR_SENSOR_H

#include "Sensor.h"

class MotorSensor : public Sensor
{
public:
    MotorSensor();

    double read() override;

private:
    double speed;
};

#endif