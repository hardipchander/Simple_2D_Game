#pragma once
#include "AbstractSprite.h"
#include "WwrMacroDefinitions.h"

namespace WWR {
	class WWR_API TwoDSprite {
	public:
		TwoDSprite(const std::string& name);

		int GetWidth() const;
		int GetHeight() const;

		void Bind();

	private:
		// I want to hide and bury glad (OpenGl) from here just I did with glfw
		AbstractSprite * implement;
	};
}


