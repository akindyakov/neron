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
   bool equal(float A, float b, int maxUlps=2);

   bool equal(double a, double b, int maxulps=2);

   bool equal(long double a, long double b, int maxulps=2);

   template <class T>
   void pairElementSort(const T& first, const T& second,
                              T* max,         T* min);
   template <class N>
   void maxMin( const N& first, const N& second,
                      N* max,         N* min);
   /*void maxMin( const float& first, const float& second,
                      float* max,         float* min);*/

} //end Math
#endif //MATH_H
