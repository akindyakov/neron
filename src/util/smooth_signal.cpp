/**
 **autor		Alexander K
 **date 		20.06.2012.01.16
 **/

//==================================================================
//==================================================================
#include "include/smooth_signal.h"
//==================================================================
void Util::moving_average(int smooth_coef, int inputVal, int* oldVal)
{
	*oldVal = ((smooth_coef-1)*inputVal + oldVal)/smooth_coef;
}
