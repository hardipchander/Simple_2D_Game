#include "precompilehead.h"
#include "TwoDSprite.h"
#include "usingOpenGl/TwoDSpriteOpenGl.h"

namespace WWR {

	// Constructor for Sprite
	TwoDSprite::TwoDSprite(const std::string& name) {
#if WWR_OPENGL
		 implement=new TwoDSpriteOpenGl{name};
#else 
	     #Only_OpenGl_is_supported_for_now
#endif
	}
     
	// Getter function for Width
	int TwoDSprite::GetWidth() const {
		return implement->GetWidth();
		
	}

	// Getter function for Height
	int TwoDSprite::GetHeight() const {
		return implement->GetHeight();
	
	}

	// the fcuntion Binds Vertex Buffer 
	void TwoDSprite::Bind() {
		implement->Bind(); 
	}
}