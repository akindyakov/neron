/**
 **autor   Alexander K
 **date    01.01.2012.22.27
*/
#include "include/output_reaction.h"
namespace SA = SimpleAgent;
//=====class textOut
void SA::textOut::input(float val)
{
    sumatorVal += val;
    return;
}

float SA::textOut::permit()
{
    endSum();

    if (endsumVal > activateVal)
    {
        std::cout << key;
    }

    return endsumVal;
}

void SA::textOut::endSum()
{
    endsumVal = sumatorVal;
    sumatorVal = 0;
    return;
}
