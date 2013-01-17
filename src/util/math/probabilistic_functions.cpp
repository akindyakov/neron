/**
 ** autor   Alexander K
 ** date    14.01.2013. 23.37
 ** BRIEF   probabilistic low realisation
*/

//=============================================================================
//=============================================================================
#include "include/util/math/probabilistic_functions.h"
//=============================================================================

namespace M = Math;

// TODO carry out this constants to math header
double const InverseSqrtTwoPi = 0.39894228040143; // 1/(sqrt(2*pi))

template <class Vt>
M::Normal_distrib(Vt diviation, Vt expectation)
   :  m_diviation(diviation)
{
   m_expectation(expectation);
}

template <class Vt>
Vt M::Normal_distrib::getDencity(Vt arg)
{
   Vt cmp_temp = (arg - m_expectation) / m_diviation;
   cmp_temp *= cmp_temp/2;
   return ( InverseTwoPi/(m_deviation) ) * exp( -cmp_temp);
}

template <class Vt>
Vt M::Normal_distrib::getIntegral(Vt start, Vt finish)
{
  //think about it
}

template <class Vt>
M::Solid_probabilistic_law::Solid_probabilistic_law (Vt diviation, Vt expectation)
{
   m_width = 3*diviation;
}

template <class Vt>
Vt M::Solid_probabilistic_law::getDencity(Vt arg)
{
   if ( abs(arg-m_expectation) < m_width )
      return 1/(2*m_width);
   else
      return 0;
}

template <class Vt>
Vt M::Solid_probabilistic_law::getIntegral(Vt start, Vt finish)
{
   if ( finish < start )
      throw (M::Math_error("(Solid_probabilistic_law::getIntegral) probabilistic must not be negative"));
   return (finish - start)/(2*m_width);
}

template <class Vt>
M::Triangle_probabilistic_law::Triangle_probabilistic_law (Vt diviation, Vt expectation)
{
   m_width = 3*diviation;
}

template <class Vt>
Vt M::Triangle_probabilistic_law::getDencity(Vt arg)
{
   Vt local_coord = arg - m_expectation;
   if ( abs(local_coord) < m_width )
   {
      Vt hight = 1/m_width;
      return (m_width - abs(local_coord))*hight/m_width;
   }
   else
      return 0;

}

template class Vt
Vt M::Triangle_probabilistic_law::getIntegral(Vt start, Vt finish)
{

}

template class Vt
M::Trapezoid_probabilistic_law::Trapezoid_probabilistic_law (Vt diviation, Vt expectation)
{

}

template class Vt
Vt M::Trapezoid_probabilistic_law::getDencity(Vt arg)
{

}

template class Vt
Vt M::Trapezoid_probabilistic_law::getIntegral(Vt start, Vt finish)
{

}

