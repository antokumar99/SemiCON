#include "StoppedState.h"

#include "../machine/Machine.h"
#include "IdleState.h"
#include "RunningState.h"

void StoppedState::start(Machine& machine)
{
    machine.changeState(
        std::make_unique<RunningState>()
    );
}

void StoppedState::stop(Machine& machine)
{
    // Already stopped.
}

void StoppedState::reset(Machine& machine)
{
    machine.changeState(
        std::make_unique<IdleState>()
    );
}

const char* StoppedState::getName() const
{
    return "STOPPED";
}