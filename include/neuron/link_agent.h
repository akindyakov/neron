/**
 **autor   Alexander K
 **date    27.12.2011.21.55
*/

#ifndef LINK_AGENT_H
#define LINK_AGENT_H
//=============================================================================
#include <iostream>
#include <vector>
#include <boost/shared_ptr.hpp>
//=============================================================================
#include "include/base_link.h"
#include "include/base_neuron.h"
//=============================================================================
namespace SimpleLink
{
	using boost::shared_ptr;
	using std::vector;
//	namespace SA = SimpleAgent;
	
	class SimpleAgentLink : public I_AgentLink
	{
	public:
   	//!default constructor
   	SimpleAgentLink(shared_ptr<SimpleAgent::I_BaseAgent> outAgent);
   	//!default destructer
    	~SimpleAgentLink();

    	//!return id conected agent
    	//unsigned long int get_id();

		//!methods for transmitting
		void transmite(int val);

		int* getCurrentKoeff();
		int getOutAgentState();
	private:

	//	unsigned long int m_id;
		int m_weightCoef;
		shared_ptr<SimpleAgent::I_BaseAgent> m_purposeAgent;
	};
}
#endif //LINK_AGENT_H
