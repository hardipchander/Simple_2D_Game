#pragma once
#include "AbstractWindow.h"
#include "WwrMacroDefinitions.h"
#include "InputEvents.h"

// Game Window for my game and it is a singleton (1 game = 1 game window) in the namespace WWR
namespace WWR {
	class WWR_API WinForGame {
	public:
		static void Init();
		static WinForGame* GetWinForGame();

		bool CreateWindow(int width, int height, const std::string& nameForWindow);
		void UpdateBuffers();
		void TakeEvents();

		int getWidth() const;
		int getHeight() const;
		void SetKeyPressedCallBack(const std::function<void(const KeyPressedEvent&)>& keyPressedCallBack);
		void SetKeyReleasedCallBack(const std::function<void(const KeyReleasedEvent&)>& keyReleasedCallBack);

		// Handles the case if user presses x on screen window then the screen window should close 
		bool ShouldWindowClose();

	private:
		inline static WinForGame* instant{nullptr};
		WinForGame();

		// AbstractWindow is an abstract class with no implementations have pure virtual functions  
		AbstractWindow* window{nullptr};
	};
}

