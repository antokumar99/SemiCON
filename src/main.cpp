#include <iostream>

#include "machine/Machine.h"
using namespace std;


int main()
{
    Machine machine;

    cout << "====================================\n";
    cout << " Semiconductor Equipment Simulator\n";
    cout << "====================================\n";

    cout << "Machine status: "
              << machine.getStatus()
              << '\n';

    machine.start();

    cout << "Machine status: "
              << machine.getStatus()
              << '\n';

    for (int i = 0; i < 5; ++i)
    {
        machine.readSensors();
    }

    machine.stop();

    cout << "Machine status: "
              << machine.getStatus()
              << '\n';


    return 0;
}