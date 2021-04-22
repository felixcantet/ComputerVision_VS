#pragma once
#ifndef COMPUTERVISION_INPUTBASE_H
#define COMPUTERVISION_INPUTBASE_H

#include <Windows.h>

enum InputType {
	NONE,
	MOVE,
	LEFT_CLICK,
	RIGHT_CLICK,
	QUIT
};

class InputBase
{
protected:
	INPUT input;
	//DWORD base_input_type;
	InputType type;

	void swap(InputBase& ib);
	
public:
	InputBase() : type(InputType::NONE) {}
	InputBase(const InputBase& ib) : input(ib.input), type(ib.type) {}

	~InputBase() = default;
	
	InputBase& operator=(InputBase ib)
	{
		swap(ib);
		return *this;
	}
	
	virtual void Perform(InputType t);
};

#endif