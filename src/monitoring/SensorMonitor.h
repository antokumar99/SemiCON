#ifndef SENSOR_MONITOR_H
#define SENSOR_MONITOR_H

#include <atomic>
#include <condition_variable>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

#include "../sensor/Sensor.h"

class SensorMonitor
{
public:
    SensorMonitor();
    ~SensorMonitor();

    void start();
    void stop();

private:
    void monitoringLoop();

    std::thread monitoringThread;

    std::mutex dataMutex;
    std::condition_variable condition;

    std::atomic<bool> running;

    std::vector<std::unique_ptr<Sensor>> sensors;
};

#endif