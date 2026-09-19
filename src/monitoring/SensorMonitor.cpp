#include "SensorMonitor.h"

#include <chrono>
#include <iostream>

#include "../sensor/TemperatureSensor.h"
#include "../sensor/PressureSensor.h"
#include "../sensor/MotorSensor.h"

SensorMonitor::SensorMonitor()
    : running(false)
{
    sensors.push_back(
        std::make_unique<TemperatureSensor>()
    );

    sensors.push_back(
        std::make_unique<PressureSensor>()
    );

    sensors.push_back(
        std::make_unique<MotorSensor>()
    );
}

SensorMonitor::~SensorMonitor()
{
    stop();
}

void SensorMonitor::start()
{
    if (running)
    {
        return;
    }

    running = true;

    monitoringThread =
        std::thread(
            &SensorMonitor::monitoringLoop,
            this
        );
}

void SensorMonitor::stop()
{
    if (!running)
    {
        return;
    }

    running = false;

    condition.notify_all();

    if (monitoringThread.joinable())
    {
        monitoringThread.join();
    }
}

void SensorMonitor::monitoringLoop()
{
    while (running)
    {
        {
            std::lock_guard<std::mutex> lock(dataMutex);

            std::cout << "\n--- Sensor Readings ---\n";

            for (const auto& sensor : sensors)
            {
                double value = sensor->read();

                std::cout << sensor->getName()
                          << ": "
                          << value
                          << " "
                          << sensor->getUnit()
                          << '\n';
            }
        }

        std::unique_lock<std::mutex> lock(dataMutex);

        condition.wait_for(
            lock,
            std::chrono::seconds(1),
            [this]()
            {
                return !running.load();
            }
        );
    }

    std::cout << "\nMonitoring thread stopped.\n";
}