/**
 ** autor   Alexander K
 ** date    30.06.2012.22.08
 ** BRIEF   MATH FLOAT EQUAL
*/

//=============================================================================
#include <cmath>
//=============================================================================
#include "include/util/math/math.h"
//=============================================================================
bool Math::equal(float A, float B, int maxUlps)

{
   // Make sure maxUlps is non-negative and small enough that the
   // default NAN won't compare as equal to anything.
   //assert(maxUlps > 0 && maxUlps < 4 * 1024 * 1024);
   int aInt = *(int*)&A;
   // Make aInt lexicographically ordered as a twos-complement int
   if (aInt < 0)
      aInt = 0x80000000 - aInt;

   // Make bInt lexicographically ordered as a twos-complement int
   int bInt = *(int*)&B;
   if (bInt < 0)
      bInt = 0x80000000 - bInt;

   int intDiff = std::abs(aInt - bInt);

   if (intDiff <= maxUlps)
      return true;

   return false;
}

bool Math::equal(double A, double B, int maxUlps)
{
   // Make sure maxUlps is non-negative and small enough that the
   // default NAN won't compare as equal to anything.
   //assert(maxUlps > 0 && maxUlps < 4 * 1024 * 1024);
   int aInt = *(int*)&A;
   // Make aInt lexicographically ordered as a twos-complement int
   if (aInt < 0)
      aInt = 0x8000000000000000 - aInt;

   // Make bInt lexicographically ordered as a twos-complement int
   int bInt = *(int*)&B;
   if (bInt < 0)
      bInt = 0x8000000000000000 - bInt;

   int intDiff = std::abs(aInt - bInt);

   if (intDiff <= maxUlps)
      return true;

   return false;
}

bool Math::equal(long double A, long double B, int maxUlps)
{
   // Make sure maxUlps is non-negative and small enough that the
   // default NAN won't compare as equal to anything.
   //assert(maxUlps > 0 && maxUlps < 4 * 1024 * 1024);
   int aInt = *(int*)&A;
   // Make aInt lexicographically ordered as a twos-complement int
   if (aInt < 0)
      aInt = 0x8000000000000000 - aInt;

   // Make bInt lexicographically ordered as a twos-complement int
   int bInt = *(int*)&B;
   if (bInt < 0)
      bInt = 0x8000000000000000 - bInt;

   int intDiff = std::abs(aInt - bInt);

   if (intDiff <= maxUlps)
      return true;

   return false;
}
