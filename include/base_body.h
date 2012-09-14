/**
 **autor   Alexander K
 **date    20.06.2012.23.33
*/

#ifndef BASE_BODY_H
#define BASE_BODY_H
//=============================================================================
#include <boost/shared_ptr.hpp>
//=============================================================================
#include "include/base_neuron.h"
#include "include/output_reaction.h"
#include "include/sense_agent.h"
//=============================================================================
namespace SimpleBody
{
	class I_Brain
	{
	public:
		virtual I_Brain(int , int agent_into, int input, int output);
		virtual void create(int, int, int);
		
		virtual void permitCycle();
		virtual void setSense(int direction, int val);
		virtual void setPain(int direction, int val);
		
	private:
	}

	
}
#endif //BASE_BODY_H
