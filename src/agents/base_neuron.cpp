/*
**autor   Alexander K
**date    27.12.2011.21.55
**BRIEF   implementation of interface base agent
*/
//=============================================================================
//=============================================================================
#include "include/base_neuron.h"
//=============================================================================

namespace SA = SimpleAgent;

//=====class base neuron
unsigned long int SA::I_BaseAgent::get_id()const
{
    return id;
}

