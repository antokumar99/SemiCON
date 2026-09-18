#include <iostream>

#include "machine/Machine.h"
using namespace std;


int main()
{
    Machine machine;

    cout << "Machine status: "
              << machine.getStatus()
              << '\n';

    machine.start();

    cout << "Machine status: "
              << machine.getStatus()
              << '\n';

    machine.stop();

    cout << "Machine status: "
              << machine.getStatus()
              << '\n';

    machine.reset();

    cout << "Machine status: "
              << machine.getStatus()
              << '\n';

    return 0;
}