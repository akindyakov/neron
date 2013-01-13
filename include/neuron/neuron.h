/*
**autor     Alexander K
**date      27.12.2011.22.07
**BRIEF     implementation of general class neuron
*/

#ifndef NEURON_H
#define NEURON_H
//=============================================================================
#include <iostream>
#include <vector>
#include <boost/shared_ptr.hpp>
//=============================================================================
#include "include/base_link.h"
#include "include/base_neuron.h"
//=============================================================================
namespace SimpleAgent
{

	using boost::shared_ptr;
	using std::vector;
   
	class SimpleAgent : public I_BaseAgent
   {
   public:
      //!default constructor
      SimpleAgent();

      void toSum(int val);

      void permit();

      int checkActivate()const;

      void createLink(shared_ptr<I_BaseAgent> connected_agent);

		
		int getTreshold()const;
		int getStateValue()const;
   private:

      int status;

      int sumVal;
      int stateVal;

      std::vector< shared_ptr<SimpleLink::I_AgentLink> > links;

      void transmit();
   };

}//end SimpleAgent
#endif //NEURON_H
