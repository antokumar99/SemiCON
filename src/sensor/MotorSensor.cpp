#include "MotorSensor.h"

#include <random>

MotorSensor::MotorSensor()
    : Sensor("Motor Speed", "RPM"),
      speed(1200.0)
{
}

double MotorSensor::read()
{
    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_real_distribution<double> distribution(-20.0, 20.0);

    speed += distribution(generator);

    if (speed < 0)
    {
        speed = 0;
    }

    return speed;
}