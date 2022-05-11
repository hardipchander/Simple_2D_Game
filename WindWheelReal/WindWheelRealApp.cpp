#include "precompilehead.h"

#include "WindWheelRealApp.h"
#include "WinForGame.h"
#include "TwoDSprite.h"
#include "ShaderProgram.h"
#include "SingleRenderer.h"
#include "InputEvents.h"
#include "CodesForKeys.h"

namespace WWR {
	void WindWheelRealApp::Run() {
		// WWR_LOG is a macro used for debug printing it only works in the Debug Build
		WWR_LOG("WindWheelReal is runnning");

		// Create Window with singelton 
		WWR::WinForGame::Init();
		const std::string WindowName = "Screen For Game";
		WWR::WinForGame::GetWinForGame()->CreateWindow(900, 900, WindowName);

		// Creating the Renderer Singleton
		SingleRenderer::Init();

		WWR::TwoDSprite character{"../WindWheelReal/Assets/SpritesOrImages/heart.png"};
		int x{0}, y{0};

		// When next frame should be displayed now time + frameDuration 
		nextFrameTime = std::chrono::steady_clock::now()+frameDuration;

		auto keyEvent = [&x, &y](const WWR::KeyPressedEvent& event) {
			if (event.GetKeyCode() == WWR_KEY_LEFT) {
				x -= 5;
			}
			else if (event.GetKeyCode() == WWR_KEY_RIGHT) {
				x += 5;
			}
			else if (event.GetKeyCode() == WWR_KEY_UP) {
				y += 5;
			}
			else if (event.GetKeyCode() == WWR_KEY_DOWN) {
				y -= 5;
			}
		};

		auto keyReleased = [](const WWR::KeyReleasedEvent& Releasedevent) { 

		};
		SetKeyPressedCallBack(keyEvent);
		SetKeyReleasedCallBack(keyReleased);
		
		// In this loop I will get user input and update the frame 
		while (!WWR::WinForGame::GetWinForGame()->ShouldWindowClose()) {
			// OnUpdate on what happens on each run of the game or each loop of the game  
			OnUpdate();

			// Sets the Color of the Screen 
			SingleRenderer::ClearWindow();
		
			SingleRenderer::Draw(character, x, y, 1);

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