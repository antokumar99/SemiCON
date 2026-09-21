#ifndef STOPPED_STATE_H
#define STOPPED_STATE_H

#include "MachineState.h"

class StoppedState : public MachineState
{
public:
    void start(Machine& machine) override;
    void stop(Machine& machine) override;
    void reset(Machine& machine) override;

    const char* getName() const override;
};

#endif