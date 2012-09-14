/**
 **autor   Alexander K
 **date    27.12.2011.21.55
*/
//=============================================================================
#include <iostream>
#include <cstdlib>
//=============================================================================
#include "include/link_agent.h"
//=============================================================================

namespace SA = SimpleAgent;

//=====class agentLink
SA::SimpleAgentLink::SimpleAgentLink(shared_ptr<I_BaseAgent> outAgent)
{
    m_weightCoef = rand();
}

SA::SimpleAgentLink::~SimpleAgentLink()
{}

void SA::SimpleAgentLink::transmite(int val)
{
	m_purposeAgent->toSum(val);	
}

int* SA::SimpleAgentLink::getCurrentKoeff()
{
	return &m_weightCoef; 
}


int SA::SimpleAgentLink::getOutAgentState()
{
	return m_purposeAgent->checkActivate();
}
