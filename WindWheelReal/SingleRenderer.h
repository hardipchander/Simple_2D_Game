#pragma once
#include "TwoDSprite.h"
#include "ShaderProgram.h"
#include "AbstractRenderer.h"
#include "usingOpenGl/OpenGLRend.h"

namespace WWR {
	class SingleRenderer {
	public:
		static void Init();
		static void Draw(WWR::TwoDSprite& pic, int xCoord, int yCoord, int zCoord);

	private:
		// Make Renderer (SingleRenderer a singleton)
		inline static SingleRenderer *instance{nullptr};

		AbstractRenderer* implementation{nullptr};

		SingleRenderer();

		WWR::ShaderProgram shader;
	};
}


