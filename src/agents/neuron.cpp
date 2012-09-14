/*
** autor     Alexander K
** date      27.12.2011.21.19
*/
//=============================================================================
//=============================================================================
#include "include/neuron.h"
#include "include/smooth_signal.h"
//=============================================================================

namespace SA = SimpleAgent;
namespace SL = SimpleLink;

SA::SimpleAgent::SimpleAgent()
{}

void SA::SimpleAgent::toSum(int val)
{
	m_sumVal += val;
}

void SA::SimpleAgent::permit(short unsigned int smooth)
{
	Util::moving_average(smooth, m_sumVal, &m_stateVal); 
	m_sumVal = 0; //set summator to null
	int transmiteVal = 0;

	if (m_sumVal >= m_activateTreshold)
	{
		m_status = 1;
		transmiteVal = m_stateVal;
	}
	else
	{
		m_status = 0;
	}
	
	for (vector<shared_ptr<SL::I_AgentLink> >::iterator linkItr =
																		m_links.begin();
	     linkItr != m_links.end();
		  linkItr++)
	{
		linkItr->transmite(transmiteVal);
	}
}

void SA::SimpleAgent::transmit()
{
   for (std::vector< shared_ptr<SL::I_AgentLink> >::iterator linkIt =
																		m_links.begin();
         linkIt != links.end(); ++linkIt)
   {
      linkIt->transmite(stateVal);
   }
}

int SA::SimpleAgent::checkActivate()const
{
   return status;
}

void SA::SimpleAgent::createLinks(shared_ptr<SA::I_BaseAgent>
connected_agent) 
{

}

int SA::SimpleAgent::getTreshold()const
{
	return m_activateTreshold;
}
int SA::SimpleAgent::getStateValue()const;
{
	return stateVal;
}	
