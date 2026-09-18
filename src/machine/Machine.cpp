#include "Machine.h"

void Machine::start()
{
    status = "RUNNING";
}

void Machine::stop()
{
    status = "STOPPED";
}

void Machine::reset()
{
    status = "IDLE";
}

std::string Machine::getStatus() const
{
    return status;
}