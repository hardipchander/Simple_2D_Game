#include "precompilehead.h"
#include "WinForGame.h"
#include "usingGLFW/ActualGlfwWin.h"

namespace WWR {

	void WinForGame::Init() {
		if (instant == nullptr) {
			instant = new WinForGame;
		}
	}

	WinForGame* WinForGame::GetWinForGame() {
		// assert checks if instant is nullptr and assert is only in debug build not release build 
		assert(instant);
		return instant;
	}

	bool WinForGame::CreateWindow(int width, int height, const std::string& nameForWindow) {
		return window->CreateWindow(width, height, nameForWindow.c_str());
	}

	void WinForGame::UpdateBuffers() {
		window->UpdateBuffers();
	}

	void WinForGame::TakeEvents() {
		window->TakeEvents();
	}

	int WinForGame::getWidth() const {
		return window->getWidth();
	}

	int WinForGame::getHeight() const {
		return window->getHeight();
	}

	WinForGame::WinForGame() {
#ifdef WWR_WINDOWS  
		window = new ActualGlfwWin;
#elif defined WWR_MACOS
		window = new ActualGlfwWin;
#elif defined WWR_LINUX
		window = new ActualGlfwWin;
#else 
		#Unsupported_platform
#endif

	}


}

