#include "KeyboardInput.h"

#include <iostream>

void KeyboardInput::Perform(InputType t)
{
	InputBase::Perform(t);
}

void EscapeInput::Perform(InputType t)
{
	//KeyboardInput::Perform(t);

    if (this->type != t)
    {
        std::cout << "Escape Input :: Je ne peux pas me déclencher" << std::endl;

        return;
    }
	
    std::cout << "Escape Input Performing !! " << std::endl;
	
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = 27;
    input.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
    ::SendInput(1, &input, sizeof(INPUT));

    // right up
    ::ZeroMemory(&input, sizeof(INPUT));
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    ::SendInput(1, &input, sizeof(INPUT));
}
