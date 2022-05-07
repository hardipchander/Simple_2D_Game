#include "precompilehead.h"
#include "ActualGlfwWin.h"
#include "WwrMacroDefinitions.h"

namespace WWR {
	//Constructor for Glfw Window
	ActualGlfwWin::ActualGlfwWin() {
		// Error Checking checks if window loaded correctly 
		if (!glfwInit()) {
			WWR_LOG("Error !!!!!! GLFW failed to intialize");
		}
	}

	// Method creates the window itself 
	bool ActualGlfwWin::CreateWindow(int width, int height, const std::string& nameForWindow) {
		ActualWindow = glfwCreateWindow(width, height, nameForWindow.c_str(), NULL, NULL);

		if (ActualWindow == nullptr) {
			WWR_LOG("Error GLFW Window failed to create");
			return false;
		}

		// Before you can use OpenGL API you must have a current OpenGL Context
		glfwMakeContextCurrent(ActualWindow);

		// Function delays swap buffer so swapping occurs when buffer is ready 
		glfwSwapInterval(1);

		// Error checking for Glad and it is after glfwMakeContextCurrent statement 
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			WWR_LOG("Glad failed to intialize");
		}

		// Setting up the button(keyboard) input 
		// Set user pointer of the window to my mCallBacks object
		glfwSetWindowUserPointer(ActualWindow, &mCallBacks);

		glfwSetKeyCallback(ActualWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				// Can change the logic here later now press button is the same as holding the button down
				if (action == GLFW_PRESS || action == GLFW_REPEAT) {

					// Cast user ptr to CallBacks* because it is originally a void pointer that can point to anything
					CallBacks* userPtr{ (CallBacks*)glfwGetWindowUserPointer(window) };

					KeyPressedEvent event{ key };
					userPtr->keyPressedCallBack(event);
				}
				else if (action == GLFW_RELEASE) {
					// Cast user ptr to CallBacks* because it is originally a void pointer that can point to anything
					CallBacks* userPtr{ (CallBacks*)glfwGetWindowUserPointer(window) };

					KeyReleasedEvent event{key};
					userPtr->keyReleasedCallBack(event);
				}
			}

		);

		return true;
	}

	// Hides glfwSwapBuffers
	void ActualGlfwWin::UpdateBuffers() {
		glfwSwapBuffers(ActualWindow);
	}

	// Hides glfwPollEvents
	void ActualGlfwWin::TakeEvents() {
		glfwPollEvents();
	}

	// Getter Method for the width of the window 
	int ActualGlfwWin::getWidth() const {
		int width, height;
		glfwGetWindowSize(ActualWindow, &width, &height);
		return width;
	}

	// Getter Method for the height of the window 
	int ActualGlfwWin::getHeight() const {
		int width, height;
		glfwGetWindowSize(ActualWindow, &width, &height);
		return height;
	}

	// Destructor for Glfw window
	ActualGlfwWin::~ActualGlfwWin() {
		if (ActualWindow != nullptr) {
			glfwDestroyWindow(ActualWindow);
		}

		glfwTerminate();
	}

	// Handles Key Press Event
	void ActualGlfwWin::SetKeyPressedCallBack(std::function<void(const KeyPressedEvent&)> keyPressedCallBack) {
		mCallBacks.keyPressedCallBack=keyPressedCallBack;

	}
	
	// Handles Key Release Event 
	void ActualGlfwWin::SetKeyReleasedCallBack(std::function<void(const KeyReleasedEvent&)> keyReleasedCallBack) {
		mCallBacks.keyReleasedCallBack = keyReleasedCallBack;

	}

	// Handles the case if user presses x on screen window then the screen window should close 
	bool ActualGlfwWin::ShouldWindowClose() {
		return glfwWindowShouldClose(ActualWindow);
	}

}
