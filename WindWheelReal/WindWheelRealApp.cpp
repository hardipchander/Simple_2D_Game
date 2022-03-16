#include "precompilehead.h"

#include "WindWheelRealApp.h"
#include "WinForGame.h"
#include "GLFW/glfw3.h"

namespace WWR {
	void WindWheelRealApp::Run() {
		// WWR_LOG is a macro used for debug printing it only works in the Debug Build
		WWR_LOG("WindWheelReal is runnning");

		// Create Window with singelton 
		WWR::WinForGame::Init();
		const std::string WindowName = "Screen For Game";
		WWR::WinForGame::GetWinForGame()->CreateWindow(900, 900, WindowName);

		while (true) {
			// in this loop I will get user input and update the frame 
			// OnUpdate on what happens on each run of the game or each loop of the gamse  
			OnUpdate();

			// Swap Buffers and Poll events 
			WWR::WinForGame::GetWinForGame()->UpdateBuffers();
			WWR::WinForGame::GetWinForGame()->TakeEvents();
		}
	}

	void WindWheelRealApp::OnUpdate() {

	}
}