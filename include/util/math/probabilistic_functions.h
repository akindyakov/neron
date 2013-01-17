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
      virtual float getDencity(float arg)=0;
      virtual float getIntegral(float start, float finish)=0;

      float m_expectation;
   };

   class Normal_probabilistic_law: public I_Prob_distrib
   {
   public:
      Normal_probabilistic_law(float diviation, float expectation);

      float getDencity(float arg);
      float getIntegral(float start, float finish);
   private:
      float m_deviation;
   };

   class Solid_probabilistic_law: public I_Prob_distrib
   {
   public:
      Solid_probabilistic_law (float diviation, float expectation);

      float getDencity(float arg);
      float getIntegral(float start, float finish);
   private:
      float m_width;
   };

   class Triangle_probabilistic_law: public I_Prob_distrib
   {
   public:
      Triangle_probabilistic_law (float diviation, float expectation);

      float getDencity(float arg);
      float getIntegral(float start, float finish);
   private:
      float m_width;
   };

   class Trapezoid_probabilistic_law: public I_Prob_distrib
   {
   public:
      Trapezoid_probabilistic_law (float diviation, float expectation);

      float getDencity(float arg);
      float getIntegral(float start, float finish);

   private:
      float m_low_width;
      float m_hi_width;
   };
} //end namespace Math

#endif // PROBABILISTIC_LOW_H
