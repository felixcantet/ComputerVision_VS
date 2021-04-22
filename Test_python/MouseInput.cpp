#include "MouseInput.h"

#include <iostream>

void MouseInput::Perform(InputType t)
{
	InputBase::Perform(t);
	
}

void MouseLeftInput::Perform(InputType t)
{
	//MouseInput::Perform(t);

    if (this->type != t)
    {
        std::cout << "Mouse left Input :: Je ne peux pas me déclencher" << std::endl;

        return;
    }
	
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    ::SendInput(1, &input, sizeof(INPUT));

    // left up
    ::ZeroMemory(&input, sizeof(INPUT));
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    ::SendInput(1, &input, sizeof(INPUT));
}

void MouseRightInput::Perform(InputType t)
{
    //MouseInput::Perform(t);

    if (this->type != t)
    {
        std::cout << "Mouse Right Input :: Je ne peux pas me déclencher" << std::endl;

        return;
    }
	
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
    ::SendInput(1, &input, sizeof(INPUT));

    // left up
    ::ZeroMemory(&input, sizeof(INPUT));
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
    ::SendInput(1, &input, sizeof(INPUT));
}
