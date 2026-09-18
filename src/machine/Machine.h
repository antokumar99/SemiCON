#ifndef MACHINE_H
#define MACHINE_H

#include <string>
using namespace std;

class Machine
{
public:

    void start();

    void stop();

    void reset();

    string getStatus() const;

private:

    string status = "IDLE";
};

#endif