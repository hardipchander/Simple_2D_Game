#pragma once
#include "precompilehead.h"
#include "glad/glad.h"
#include "AbstractSprite.h"

namespace WWR {
	class TwoDSpriteOpenGl : public AbstractSprite {
	public:
		TwoDSpriteOpenGl(const std::string & pathForFile);
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		virtual void Bind() override;
		virtual bool BoundOrNot() const override;

	private:
		//IDs for Vertex Bufer Object, Vertex Array Object, and EBO which is for the edges used for Rectangle
		unsigned int VertexBufferObject;
		unsigned int VertexArrayObject;
		unsigned int EdgesBufferObject;

		// Texture data members
		unsigned int textureID;
		int width{0};
		int height{0};

	};
}