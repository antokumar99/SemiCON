#include "PressureSensor.h"

#include <random>
using namespace std;


PressureSensor::PressureSensor()
    : Sensor("Pressure", "Torr"),
      pressure(1.0)
{
}

double PressureSensor::read()
{
    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_real_distribution<double> distribution(-0.05, 0.05);

    pressure += distribution(generator);

    if (pressure < 0.1)
    {
        pressure = 0.1;
    }

    return pressure;
}