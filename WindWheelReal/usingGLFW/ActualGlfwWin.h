#pragma once
#include "AbstractWindow.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h" //GLFW-> library that creates a game window or a graphic window I fixed the error

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

		virtual void SetKeyPressedCallBack(const std::function<void(const KeyPressedEvent&)>& keyPressedCallBack) override;

	private:
		// For handling events 
		struct CallBacks {
			std::function<void(const KeyPressedEvent&)> keyPressedCallBack;
		} mCallBacks;

		GLFWwindow* ActualWindow{nullptr};
	};
}

