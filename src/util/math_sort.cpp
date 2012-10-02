/**
 ** autor   Alexander K
 ** date    29.09.2012.22.53
 ** BRIEF   MATH SORT TOOLS
*/

//=============================================================================
#include <cmath>
//=============================================================================
#include "include/math.h"
//=============================================================================
namespace M = Math;
template <class T>
void M::pairElementSort(const T& first, const T& second,
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
void M::maxMin( const N& first, const N& second,
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
/*
void M::maxMin( const float& first, const float& second,
                      float* max,         float* min)
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
}*/
