#include "precompilehead.h"
#include "SingleRenderer.h"
#include "WinForGame.h"

namespace WWR {
	void SingleRenderer::Init(){
		if (instance == nullptr) {
			instance=new SingleRenderer;
		}
	}

	void SingleRenderer::Draw(WWR::TwoDSprite& pic, int xCoord, int yCoord, int zCoord) {
		// Error Checking make sure that renderer was created before drawing 
		assert(instance != nullptr);

		instance->implementation->Draw(pic,xCoord, yCoord, zCoord, instance->shader);
	}

	SingleRenderer::SingleRenderer() : shader("../WindWheelReal/Assets/Shaders/defaultVertexShader.glsl", "../WindWheelReal/Assets/Shaders/defaultFragmentShader.glsl") {
#if WWR_OPENGL
		implementation = new OpenGLRend;
#else 
		#Only_OpenGl_is_supported_for_now
#endif
	}
}