/**
 ** autor   Alexander K
 ** date    11.01.2013. 22.13
 ** BRIEF   probabilistic low
*/

#ifndef PROBABILISTIC_LOW_H
#define PROBABILISTIC_LOW_H
//=============================================================================
#include <vector>
//=============================================================================
//=============================================================================

namespace Math
{
   template class Vt
   class I_Prob_distrib
   {
   public:
      virtual Vt getIntencity(Vt arg);
      virtual Vt getIntegral(Vt start, Vt finish);
      
      Vt m_expectation;
   };
   
   template class Vt
   class Normal_distrib: public I_Prob_distribution<Vt>
   {
   public:
      Normal_distrib(Vt diviation, Vt expectation);
      
   private:
      Vt m_deviation;
   };
   
   template class Vt
   class Normal_linearised_distrib: public I_Prob_distribution<Vt>
   {
   public:
      Normal_linearised_distrib(Vt diviation, Vt expectation);
      
   private:
      static const Vt m_coeff[256];
   };
   
   Normal_linearised_distrib::m_coeff = 
   { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

} //end namespace Math

#endif // PROBABILISTIC_LOW_H
