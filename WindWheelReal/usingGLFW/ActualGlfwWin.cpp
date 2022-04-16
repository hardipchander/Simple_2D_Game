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

		// Error checking for Glad and it is after glfwMakeContextCurrent statement 
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			WWR_LOG("Glad failed to intialize");
		}

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

}
