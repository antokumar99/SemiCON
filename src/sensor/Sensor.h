#ifndef SENSOR_H
#define SENSOR_H

#include <string>
using namespace std;

class Sensor
{
public:
    Sensor(const string& name, const string& unit);

    virtual ~Sensor() = default;

    virtual double read() = 0;

    string getName() const;
    string getUnit() const;

protected:
    string name;
    string unit;
};

#endif