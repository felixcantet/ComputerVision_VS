#ifndef COMPUTERVISION_KeyboardInput_H
#define COMPUTERVISION_KeyboardInput_H

#include "InputBase.h"

class KeyboardInput : public InputBase
{

public:
	KeyboardInput() : InputBase()
	{
		//base_input_type = INPUT_KEYBOARD;
	}

	KeyboardInput(const KeyboardInput& mi) : InputBase(mi) {}

	KeyboardInput& operator=(KeyboardInput mi)
	{
		InputBase::swap(mi);
		return *this;
	}

	virtual void Perform(InputType t) override;
};

class EscapeInput : public KeyboardInput
{
public:
	EscapeInput() : KeyboardInput()
	{
		type = QUIT;
	}
	void Perform(InputType t) override final;
};
#endif
