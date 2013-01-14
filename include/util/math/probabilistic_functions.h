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
   class Normal_probabilistic_law: public I_Prob_distribution<Vt>
   {
   public:
      Normal_probabilistic_law(Vt diviation, Vt expectation);
      
      Vt getDencity(Vt arg);
      Vt getIntegral(Vt start, Vt finish);
   private:
      Vt m_deviation;
   };
   
   template class Vt
   class Solid_probabilistic_law: public I_Prob_distribution<Vt>
   {
   public:
      Solid_probabilistic_law (Vt diviation, Vt expectation);
      
   private:
      Vt m_width;
   };
   
   template class Vt
   class Triangle_probabilistic_law: public I_Prob_distribution<Vt>
   {
   public:
      Solid_probabilistic_law (Vt diviation, Vt expectation);
      
   private:
      Vt m_width;
   };
   
   template class Vt
   class Trapezoid_probabilistic_law: public I_Prob_distribution<Vt>
   {
   public:
      Solid_probabilistic_law (Vt diviation, Vt expectation);
      
   private:
      Vt m_low_width;
      Vt m_hi_width;
   };
} //end namespace Math

#endif // PROBABILISTIC_LOW_H
