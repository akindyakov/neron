/**
 **autor   Alexander K
 **date    15.12.2012.23.57
*/

//=============================================================================
#include <boost/shared_ptr.hpp>
//=============================================================================
#include "include/base_neuron.h"
//=============================================================================

template<class T>
Math::Polinom::Polinom()
{
}
Math::Polinom::Polinom(const std::vector<T>& _coeff)
      :m_coeff(_coeff)
{}
      
Math::Polinom::compute(T arg)
{}
