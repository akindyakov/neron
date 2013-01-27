/*
autor     Alexander K
date      01.01.2012.23.09
*/
#ifndef OUTPUT_REACTION_H
#define OUTPUT_REACTION_H
//==================================================================
#include <iostream>
#include <vector>
//==================================================================
#include "include/base_link.h"
#include "include/base_neuron.h"
//==================================================================
namespace SimleAgent
{
	class textOut : public I_BaseAgent
	{
	public:
    	//!default constructor
    	textOut(){};
    	//!default destructor
    	~textOut(){};

    	unsigned long int get_id()const;

    	void input(float val);

    	float permit();

    	void endSum();

	private:

    	float activateVal;
    	float sumatorVal;
    	float endsumVal;

   	char key;
	};
}//end SimpleAgent
#endif //OUTPUT_REACTION_H
