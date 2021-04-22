#ifndef COMPUTERVISION_MouseInput_H
#define COMPUTERVISION_MouseInput_H

#include "InputBase.h"

class MouseInput : public InputBase
{
	
public:
	MouseInput() : InputBase()
	{
		//base_input_type = INPUT_MOUSE;
	}

	MouseInput(const MouseInput& mi) : InputBase(mi) {}

	/*MouseInput& operator=(MouseInput mi)
	{
		InputBase::swap(mi);
		return *this;
	}*/
	
	virtual void Perform(InputType t) override;
};

class MouseLeftInput : public MouseInput
{
public:
	MouseLeftInput() : MouseInput()
	{
		type = LEFT_CLICK;
	}
	virtual void Perform(InputType t) override final;
};

class MouseRightInput : public MouseInput
{
public:
	MouseRightInput() : MouseInput()
	{
		type = RIGHT_CLICK;
	}
	virtual void Perform(InputType t) override final;
};
#endif