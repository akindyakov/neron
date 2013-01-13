/**
 **autor 	Alexander K
 **date		19.06.2012.23.50
*/

#ifndef SMOOTH_SIGNAL_H
#define SMOOTH_SIGNAL_H
//==================================================================
//==================================================================
//==================================================================
namespace Util
{

	void moving_average(int smooth_coef, int inputVal, int* oldVal);

} // end Util
#endif //SMOOTH_SIGNAL_H
