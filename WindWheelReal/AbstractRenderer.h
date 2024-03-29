#pragma once
#include "TwoDSprite.h"
#include "ShaderProgram.h"

namespace WWR {
	class AbstractRenderer {
	public:
		virtual void Draw(WWR::TwoDSprite& pic, int xCoord, int yCoord, int zCoord, WWR::ShaderProgram shader) = 0;
		virtual void ClearWindow() = 0;
		virtual void ClearWindowBasedOnColor(std::string color) = 0;
	};
}