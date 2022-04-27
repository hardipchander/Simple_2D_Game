#pragma once
#include "AbstractRenderer.h"

namespace WWR {
	class OpenGLRend :public AbstractRenderer {
	public:
		OpenGLRend();
		virtual void Draw(WWR::TwoDSprite& pic, int xCoord, int yCoord, int zCoord, WWR::ShaderProgram shader) override;

	private:

	};
}