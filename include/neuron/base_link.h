/**
 **autor   Alexander K
 **date    27.12.2011.21.55
*/

#ifndef BASE_LINK_H
#define BASE_LINK_H
//=============================================================================
#include <boost/shared_ptr.hpp>
//=============================================================================
#include "include/base_neuron.h"
//=============================================================================
namespace SimpleLink
{
   using boost::shared_ptr;

   class I_AgentLink
   {
   public:
      I_AgentLink(){};
      //!default destruct
      virtual ~I_AgentLink(){};

      //!return id conected agent
    //   virtual unsigned long int get_id();

      //!methods for coonect agent
      virtual unsigned long int setPurpose(shared_ptr<I_BaseAgent> outAgent);

      //!methods for transmitting
      virtual void transmite(int val);

      //!methods for link learning
      //virtual void learn(int globalFeeling);
      virtual int* getCurrentKoeff();
      virtual int getOutAgentState();
   };
} //endnamespace SimpleLink
#endif //BASE_LINK_H
