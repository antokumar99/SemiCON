cmake_minimum_required(VERSION 3.20)

project(SemiconductorEquipmentSimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    simulator

    src/main.cpp

    # Machine
    src/machine/Machine.cpp

    # Sensors
    src/sensor/Sensor.cpp
    src/sensor/TemperatureSensor.cpp
    src/sensor/PressureSensor.cpp
    src/sensor/MotorSensor.cpp

    # Monitoring
    src/monitoring/SensorMonitor.cpp

    # State Pattern
    src/state/IdleState.cpp
    src/state/RunningState.cpp
    src/state/StoppedState.cpp

    # Command Pattern
    src/command/StartCommand.cpp
    src/command/StopCommand.cpp
    src/command/ResetCommand.cpp

    # Controller
    src/controller/MachineController.cpp
)