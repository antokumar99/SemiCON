#ifndef RUNNING_STATE_H
#define RUNNING_STATE_H

#include "MachineState.h"

class RunningState : public MachineState
{
public:
    void start(Machine& machine) override;
    void stop(Machine& machine) override;
    void reset(Machine& machine) override;

    const char* getName() const override;
};

#endif