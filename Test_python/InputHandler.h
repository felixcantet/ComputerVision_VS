#ifndef COMPUTERVISION_INPUTHANDLER_H
#define COMPUTERVISION_INPUTHANDLER_H

#include <opencv2/core/types.hpp>



class HandDetection;
enum InputType;
class InputBase;

class InputHandler2
{
private:
    static InputHandler2* instance;
    std::vector<std::shared_ptr<InputBase>> inputs;
    InputHandler2() = default;
	
public:
    InputHandler2(const InputHandler2& ih) = delete;

	~InputHandler2()
	{
		delete instance;
	};
	
	static InputHandler2* getInstance()
	{
        return instance;
	}

	void RegisterNewInput(std::shared_ptr<InputBase> i)
	{
        inputs.push_back(i);
	}

	void PerformInputs(InputType t);

	static InputType GetInputTypeFromHand(const HandDetection& hd);
	static void MoveCursor(const cv::Point& dir);
	static void SetCursorPosition(const cv::Point& pos);
	
};

#endif //COMPUTERVISION_INPUTHANDLER_H
