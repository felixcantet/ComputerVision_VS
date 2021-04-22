#include "InputBase.h"

#include <iostream>

void InputBase::swap(InputBase& ib)
{
	std::swap(input, ib.input);
	//std::swap(base_input_type, ib.base_input_type);
	std::swap(type, ib.type);
}

void InputBase::Perform(InputType t)
{
	if(this->type != t)
	{
		std::cout << "InputBase :: Je ne peux pas me déclencher" << std::endl;
		
		return;
	}
}
