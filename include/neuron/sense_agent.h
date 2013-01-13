/**
 **autor   Alexander K
 **date    01.01.2012.20.10
*/

#ifndef SENSE_AGENT_H
#define SENSE_AGENT_H
//==========================================================================
#include <iostream>
#include <vector>
#include <boost/shared_ptr.hpp>
//==========================================================================
#include "include/base_link.h"
#include "include/base_neuron.h"
//==========================================================================
class textAgent : public I_BaseAgent
{
public:
    bool sendVal(char val);
private:

    unsigned long int id;
    std::vector< shared_ptr< SimpleLink::I_AgentLink> > links;
    char key;
};

#endif // SENSE_AGENT_H
