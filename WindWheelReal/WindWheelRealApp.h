#pragma once
#include "WwrMacroDefinitions.h"
#include "precompilehead.h"
#include "InputEvents.h"

// 60 fps 60 frames in a second 
#define WWR_FRAMERATE 60

namespace WWR {
	class WWR_API WindWheelRealApp {
	public:
		// It creates the GameWindow singleton and Renderer Singleton 
		WindWheelRealApp();

		void Run();
		virtual void OnUpdate();

		void SetKeyPressedCallBack(std::function<void(const KeyPressedEvent &)>  keyPressedCallBack);
		void SetKeyReleasedCallBack(std::function<void(const KeyReleasedEvent&)>  keyReleasedCallBack);

	private:

		// How long each frame should be in terms of milliseconds 
		// frameDuration = 1,000 ms / 60 frames because in one second there are 1,000 ms and 60 frames 
		std::chrono::milliseconds frameDuration{1000/WWR_FRAMERATE};

		// Use a time point to record the time for the next Frame 
		std::chrono::steady_clock::time_point nextFrameTime;
	};
}


