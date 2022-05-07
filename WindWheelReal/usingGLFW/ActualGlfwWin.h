#pragma once
#include "AbstractWindow.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h" 
#include "InputEvents.h"

namespace WWR {
	class ActualGlfwWin : public AbstractWindow {
	public:
		ActualGlfwWin();
		virtual bool CreateWindow(int width, int height, const std::string& nameForWindow) override;

		virtual void UpdateBuffers() override;
		virtual void TakeEvents() override;

		virtual int getWidth() const override;
		virtual int getHeight() const override;

		~ActualGlfwWin();

		virtual void SetKeyPressedCallBack(std::function<void(const KeyPressedEvent&)> keyPressedCallBack) override;
		virtual void SetKeyReleasedCallBack(std::function<void(const KeyReleasedEvent&)> keyReleasedCallBack) override;
		virtual bool ShouldWindowClose() override;

	private:
		// For handling input keyboard events 
		struct CallBacks {
			// Giving keyPressedCallBack and keyReleasedCallBack default values so the program can work even they are assigend any values
			std::function<void(const KeyPressedEvent&)> keyPressedCallBack{ [](const KeyPressedEvent&) {} };
			std::function<void(const KeyReleasedEvent&)> keyReleasedCallBack{ [](const KeyReleasedEvent&) {} };
		} mCallBacks;

		GLFWwindow* ActualWindow{nullptr};
	};
}

