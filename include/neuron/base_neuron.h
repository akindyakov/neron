/**
 ** autor   Alexander K
 ** date    28.12.2011.00.37
 ** BRIEF   interfase class for base agent
*/

#ifndef BASE_NEURON_H
#define BASE_NEURON_H
//=============================================================================
//=============================================================================
//=============================================================================

namespace SimpleAgent
{

   class I_BaseAgent
   {
   public:
      virtual unsigned long int get_id()const=0;

      virtual void toSum(int val){};

      virtual void permit(){};

      virtual int checkActivate()const=0;

      virtual void createLink(shared_ptr<I_BaseAgent>){};
      
      virtual int getTreshold()const;
      virtual int getStateValue()const;

   private:
      unsigned long int id;
   };

} //end SimpleAgent
#endif //BASE_NEURON_H
