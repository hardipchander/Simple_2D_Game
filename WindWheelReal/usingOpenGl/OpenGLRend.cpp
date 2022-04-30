#include "precompilehead.h"
#include "OpenGLRend.h"
#include "WinForGame.h"
#include "glad/glad.h"

namespace WWR {
	void OpenGLRend::Draw(WWR::TwoDSprite& pic, int xCoord, int yCoord, int zCoord, WWR::ShaderProgram shader) {
		// Getting the size of the window from WinforGame Singleton
		int winWidth{ WinForGame::GetWinForGame()->getWidth() };
		int winHeight{ WinForGame::GetWinForGame()->getHeight() };

		shader.Bind();
		pic.Bind();

		shader.SetUniform2Ints("windowSize", winWidth, winHeight);
		shader.SetUniform3Ints("spriteCoord", xCoord, yCoord, zCoord);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	//Sets the color of the Screen Window
	void OpenGLRend::ClearWindow() {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}