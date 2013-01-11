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
   class I_Prob_distrib
   {
   public:
      virtual float getIntencity(float arg);
      virtual float getIntegral(float start, float finish);
   };
   
   class Normal_distrib: public I_Prob_distribution
   {
   public:
   Normal_distrib();
   Normal_distrib();
   private:
   };
   
   class Normal_linearised_distrib: public I_Prob_distribution
   {
   public:
    Normal_linearised_distrib(std::vector<float> coeff);
   private:
   };
} //end namespace Math
#endif // PROBABILISTIC_LOW_H
