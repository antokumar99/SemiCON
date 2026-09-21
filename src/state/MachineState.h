#ifndef MACHINE_STATE_H
#define MACHINE_STATE_H

class Machine;

class MachineState
{
    public:
    virtual ~MachineState() = default;

    virtual void start(Machine& machine) =0;
    virtual void stop(Machine& machine) = 0;
    virtual void reset(Machine& machine) = 0;


    virtual const char* getName() const =0;


};

#endif