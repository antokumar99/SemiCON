#include "RunningState.h"

#include "../machine/Machine.h"
#include "IdleState.h"
#include "StoppedState.h"

void RunningState::start(Machine& machine)
{
    // Already running.
}

void RunningState::stop(Machine& machine)
{
    machine.changeState(
        std::make_unique<StoppedState>()
    );
}

void RunningState::reset(Machine& machine)
{
    machine.changeState(
        std::make_unique<IdleState>()
    );
}

const char* RunningState::getName() const
{
    return "RUNNING";
}