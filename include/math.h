/**
 ** autor   Alexander K
 ** date    30.06.2012.21.56
 ** BRIEF   GEOMETRY UTIL
*/

#ifndef MATH_H
#define MATH_H
//=============================================================================
//=============================================================================
//=============================================================================

namespace Math
{
   bool equal(float A, float b, int maxulps=2);

   bool equal(double a, double b, int maxulps=2);

   bool equal(long double a, long double b, int maxulps=2);

   template <class T>
   void pairElementSort(const T& first, const T& second,
                              T* max,         T* min)
   {
      if ( first > second )
      {
         if ( *max < first ) *max = first;
         if ( *min > second ) *min = second;
      }
      else
      {
         if ( *max < second ) *max = second;
         if ( *min > first ) *min = first;
      }
   }

   template <class N>
   void maxMin( const N& first, const N& second,
                      N* max,         N* min)
   {
      if ( first > second )
      {
         *max = first;
         *min = second;
      }
      else
      {
         *max = second;
         *min = first;
      }
      return;
   }
   
   template <class T>
   class Polinom
   {
   pablic:
      Polinom();
      Polinom(const std::vector<T>& _coeff);
      
      compute(T arg);
      
   private;
      std::vector<T> m_coeff;
   };
} //end Math
#endif //MATH_H
