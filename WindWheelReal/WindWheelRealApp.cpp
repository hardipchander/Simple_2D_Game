#include "precompilehead.h"

#include "WindWheelRealApp.h"
#include "WinForGame.h"
//#include "GLFW/glfw3.h"   // for window screen 
#include "glad/glad.h"    // for OpenGl and drawing 
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

		WWR::TwoDSprite sprite{"../WindWheelReal/Assets/SpritesOrImages/moon.png"};

		while (true) {
			// in this loop I will get user input and update the frame 
			// OnUpdate on what happens on each run of the game or each loop of the gamse  
			OnUpdate();

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			SingleRenderer::Draw(sprite, 50, 20, 1);
			
			// Swap Buffers and Poll events for Glfw Window
			WWR::WinForGame::GetWinForGame()->UpdateBuffers();
			WWR::WinForGame::GetWinForGame()->TakeEvents();
		}
	}

	void WindWheelRealApp::OnUpdate() {

	}
}