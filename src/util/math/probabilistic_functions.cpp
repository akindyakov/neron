/**
 ** autor   Alexander K
 ** date    14.01.2013. 23.37
 ** BRIEF   probabilistic low realisation
*/

//=============================================================================
//=============================================================================
//=============================================================================

namespace M = Math;

// TODO carry out this constants to math header
double const InverseSqrtTwoPi = 0.39894228040143; // 1/(sqrt(2*pi))

template class Vt
M::Normal_distrib(Vt diviation, Vt expectation)
   :  m_diviation(diviation)
{
   m_expectation(expectation);
}

template class Vt
Vt M::Normal_distrib::getDencity(Vt arg)
{
   Vt cmp_temp = (arg - m_expectation) / m_diviation;
   cmp_temp *= cmp_temp/2;
   return ( InverseTwoPi/(m_deviation) ) * exp( -cmp_temp);
}

template class Vt
Vt M::Normal_distrib::getIntegral(Vt start, Vt finish)
{
  //think about it 
}

template class Vt
Solid_probabilistic_law (Vt diviation, Vt expectation)
{
   
}
  
template class Vt
Vt M::::getDencity(Vt arg)
{
   
}

template class Vt
Vt M::::getIntegral(Vt start, Vt finish)
{
   
}

template class Vt
M::Triangle_probabilistic_law::Triangle_probabilistic_law (Vt diviation, Vt expectation)
{
   
}
  
template class Vt
Vt M::Triangle_probabilistic_law::getDencity(Vt arg)
{
   
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

