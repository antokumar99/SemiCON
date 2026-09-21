#include "IdleState.h"

#include "../machine/Machine.h"
#include "RunningState.h"

void IdleState::start(Machine& machine)
{
    machine.changeState(
        std::make_unique<RunningState>()
    );
}

void IdleState::stop(Machine& machine)
{
    // Already idle, so nothing to do.
}

void IdleState::reset(Machine& machine)
{
    // Already idle.
}

const char* IdleState::getName() const
{
    return "IDLE";
}