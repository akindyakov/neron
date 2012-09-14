/**
 **autor   Alexander K
 **date    01.01.2012.22.27
*/
#include "include/sense_agent.h"

//=====class textAgent
bool SimpleAgent::textAgent::sendVal(char val)
{
    float outputVal = 0;
    if ( val == key )
        outputVal = 1;

    for ( unsigned int i = 0; i < links.size(); i++ )
    {
        links[i].sendVal(outputVal);
    }
    return outputVal;
}
