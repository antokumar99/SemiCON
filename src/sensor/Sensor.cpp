#include "Sensor.h"
using namespace std;

Sensor::Sensor(const string& name, const string& unit)
    : name(name), unit(unit)
{
}

string Sensor::getName() const
{
    return name;
}

string Sensor::getUnit() const
{
    return unit;
}