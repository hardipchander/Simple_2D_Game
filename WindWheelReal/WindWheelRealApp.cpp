#include "precompilehead.h"

#include "WindWheelRealApp.h"
#include "WinForGame.h"
//#include "GLFW/glfw3.h"   // for window screen 
#include "TwoDSprite.h"
#include "ShaderProgram.h"
#include "SingleRenderer.h"

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

		WWR::TwoDSprite sprite{"../WindWheelReal/Assets/SpritesOrImages/heart.png"};

		// Start sprite outside of the screen by making it negative 
		int posX{-sprite.GetWidth() };

		// When next frame should be displayed now time + frameDuration 
		nextFrameTime = std::chrono::steady_clock::now()+frameDuration;

		// In this loop I will get user input and update the frame 
		while (true) {
			// OnUpdate on what happens on each run of the game or each loop of the game  
			OnUpdate();

			SingleRenderer::ClearWindow();

			SingleRenderer::Draw(sprite, posX, 20, 1);
			posX = posX + 5;

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

	void WindWheelRealApp::SetKeyPressedCallBack(const std::function<void(const KeyPressedEvent&)>& keyPressedCallBack) {
		WinForGame::GetWinForGame()->SetKeyPressedCallBack(keyPressedCallBack);
	}
}