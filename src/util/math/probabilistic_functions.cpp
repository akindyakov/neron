/**
 ** autor   Alexander K
 ** date    14.01.2013. 23.37
 ** BRIEF   probabilistic low realisation
*/

//=============================================================================
#include <cmath>
//=============================================================================
#include "include/util/math/probabilistic_functions.h"
#include "include/util/math/math.h"
//=============================================================================

namespace M = Math;

M::Solid_probabilistic_law::Solid_probabilistic_law (float diviation, float expectation)
{
   m_width = 3*diviation;
}

float M::Solid_probabilistic_law::getDencity(float arg)
{
   if ( std::abs(arg-m_expectation) < m_width )
      return 1/(2*m_width);
   else
      return 0;
}

float M::Solid_probabilistic_law::getIntegral(float start, float finish)
{
   if ( finish < start )
      throw (M::Math_error("(Solid_probabilistic_law::getIntegral) probabilistic must not be negative"));
   return (finish - start)/(2*m_width);
}

M::Triangle_probabilistic_law::Triangle_probabilistic_law (float diviation, float expectation)
{
   m_width = 3*diviation;
}

float M::Triangle_probabilistic_law::getDencity(float arg)
{
   float local_coord = arg - m_expectation;
   if ( std::abs(local_coord) < m_width )
   {
      float hight = 1/m_width;
      return (m_width - std::abs(local_coord))*hight/m_width;
   }
   else
      return 0;

}

float M::Triangle_probabilistic_law::getIntegral(float start, float finish)
{
    return 0;
}

M::Trapezoid_probabilistic_law::Trapezoid_probabilistic_law (float diviation, float expectation)
{

}

float M::Trapezoid_probabilistic_law::getDencity(float arg)
{
    return 0;
}

float M::Trapezoid_probabilistic_law::getIntegral(float start, float finish)
{
    return 0;
}

