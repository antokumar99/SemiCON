#include "TemperatureSensor.h"

#include <random>
using namespace std;

TemperatureSensor::TemperatureSensor()
    : Sensor("Temperature", "°C"),
      temperature(25.0)
{
}

double TemperatureSensor::read()
{
    random_device rd;
    mt19937 generator(rd());

    uniform_real_distribution<double> distribution(-0.5, 0.5);

    temperature += distribution(generator);

    return temperature;
}