#include "precompilehead.h"

#include "WindWheelRealApp.h"
#include "WinForGame.h"
#include "TwoDSprite.h"
#include "ShaderProgram.h"
#include "SingleRenderer.h"
#include "InputEvents.h"
#include "CodesForKeys.h"

namespace WWR {
	WindWheelRealApp::WindWheelRealApp() {
		// WWR_LOG is a macro used for debug printing it only works in the Debug Build
		WWR_LOG("WindWheelReal is runnning");

		// Create Window with singelton 
		WWR::WinForGame::Init();
		const std::string WindowName = "The Game";
		WWR::WinForGame::GetWinForGame()->CreateWindow(1000, 980, WindowName);

		// Creating the Renderer Singleton
		SingleRenderer::Init();
	}

	void WindWheelRealApp::Run() {

		// When next frame should be displayed now time + frameDuration 
		nextFrameTime = std::chrono::steady_clock::now()+frameDuration;
		
		// In this loop I will get user input and update the frame 
		while (!WWR::WinForGame::GetWinForGame()->ShouldWindowClose()) {
			// Sets the Color of the Screen 
			SingleRenderer::ClearWindow();

			// OnUpdate on what happens on each run of the game or each loop of the game  
			OnUpdate();
		
			// Ask loop to sleep until next time 
			std::this_thread::sleep_until(nextFrameTime);

			// Swap Buffers(replace front buffer with back buffer where everything is written on back buffer) and Poll events for Glfw Window
			WWR::WinForGame::GetWinForGame()->UpdateBuffers();
			WWR::WinForGame::GetWinForGame()->TakeEvents();

			// Update nextFrameTime but can be a problem because what if we don't finish all work before nextFrameTime
			nextFrameTime += frameDuration;
		}
	}

	void WindWheelRealApp::OnUpdate() {

	}

	void WindWheelRealApp::SetKeyPressedCallBack(std::function<void(const KeyPressedEvent&)> keyPressedCallBack) {
		// WWR App passes it to WinForGame (Game Window Singleton) 
		WinForGame::GetWinForGame()->SetKeyPressedCallBack(keyPressedCallBack);
	}

	void WindWheelRealApp::SetKeyReleasedCallBack(std::function<void(const KeyReleasedEvent&)> keyReleasedCallBack) {
		// WWR App passes it to WinForGame (Game Window Singleton) 
		WinForGame::GetWinForGame()->SetKeyReleasedCallBack(keyReleasedCallBack);
	}


}