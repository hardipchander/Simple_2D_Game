#pragma once
#include "AbstractRenderer.h"

namespace WWR {
	class OpenGLRend :public AbstractRenderer {
	public:
		virtual void Draw(WWR::TwoDSprite& pic, int xCoord, int yCoord, int zCoord, WWR::ShaderProgram shader) override;
		virtual void ClearWindow() override;
		virtual void ClearWindowBasedOnColor(std::string color) override;


	private:

	};
}