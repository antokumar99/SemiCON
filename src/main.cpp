#include <chrono>
#include <iostream>
#include <thread>

#include "controller/MachineController.h"

int main()
{
    std::cout << "====================================\n";
    std::cout << " Semiconductor Equipment Simulator\n";
    std::cout << "====================================\n";

    MachineController controller;

    std::cout << "\nInitial machine state: "
              << controller.getMachineStatus()
              << '\n';

    // -------------------------------
    // START MACHINE
    // -------------------------------

    std::cout << "\nStarting machine...\n";

    controller.startMachine();

    std::cout << "Machine state: "
              << controller.getMachineStatus()
              << '\n';

    std::this_thread::sleep_for(
        std::chrono::seconds(5)
    );

    // -------------------------------
    // STOP MACHINE
    // -------------------------------

    std::cout << "\nStopping machine...\n";

    controller.stopMachine();

    std::cout << "Machine state: "
              << controller.getMachineStatus()
              << '\n';

    std::this_thread::sleep_for(
        std::chrono::seconds(2)
    );

    // -------------------------------
    // RESET MACHINE
    // -------------------------------

    std::cout << "\nResetting machine...\n";

    controller.resetMachine();

    std::cout << "Machine state: "
              << controller.getMachineStatus()
              << '\n';

    std::cout << "\n====================================\n";
    std::cout << " Program finished successfully\n";
    std::cout << "====================================\n";

    return 0;
}