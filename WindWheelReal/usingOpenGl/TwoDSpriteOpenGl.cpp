#include "precompilehead.h"
#include "TwoDSpriteOpenGl.h"
#include "WwrMacroDefinitions.h"
#include "stb_image.h"

namespace WWR {

	TwoDSpriteOpenGl::TwoDSpriteOpenGl(const std::string& pathForFile) {

		// Invert Image of Texture to not make it look upside down
		stbi_set_flip_vertically_on_load(true);

		// Data for Texture 
		int numChannels;
		unsigned char* data = stbi_load(pathForFile.c_str(), &width, &height, &numChannels, 0);

		// Error Checking for Texture where the data for image of Tetxure does not load 
		if (data == NULL) {
			WWR_LOG("Error the data for texture does not load");
		}

		// Array for Vertices 
		float points[] = {
			0.0f,  0.0f,                  0.0f, 0.0f,    // bottom left
			0.0f, float(height),          0.0f, 1.0f,    // top left
			float(width), float(height),  1.0f, 1.0f,	 // top right
			float(width), 0.0f,           1.0f, 0.0f,	 // bottom right 
		};

		// Specify Edges
		unsigned int edges[] = {
			0,1,2,     // upper left triangle
			0,2,3      // bottom left triangle
		};


		// Generate the IDs for Vertex Buffer Object, Vertex Array Object, and EBO which is for the edges 
		glGenVertexArrays(1, &VertexArrayObject);
		glGenBuffers(1, &VertexBufferObject);
		glGenBuffers(1, &EdgesBufferObject);

		// Activate Vertex Array Object it is an umbrella for everything 
		glBindVertexArray(VertexArrayObject);

		// Take the vertices array and copy it into Vertex Buffer Object(VBO) load it for GPU
		glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject);
		glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW); //GL_STATIC_DRAW tells opengl how to keep drawing without changing

		// Take the edges array and copy it into the EBO load it for GPU
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EdgesBufferObject);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(edges), edges, GL_STATIC_DRAW); //GL_STATIC_DRAW tells opengl how to keep drawing without changing

		// Each portion of the vertex array in the beginning is called an attribute, we have 2 attributes for the coordinates of rectangle and texture  
		// 1st parameter is 0 meaning the first attribute 
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		// For the Texture Coordinates attribute 
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)8);
		glEnableVertexAttribArray(1);

		// Now the code for Texture -------------------------------------------------------------------------------------------------------------------
		
		// Generate the texture with the textureID and then bind it 
		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);

		// Just need the four lines of code below to establish the texture wrapping/filtering options
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(data);

		// Enable Blending for texture over the rectangle  
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	}

	int TwoDSpriteOpenGl::GetWidth() const{
		return width;
	}

	int TwoDSpriteOpenGl::GetHeight() const {
		return height;
	}

	// Binding VAO and texture IDs
	void TwoDSpriteOpenGl::Bind() {
		glBindVertexArray(VertexArrayObject);
		glBindTexture(GL_TEXTURE_2D, textureID);
	}

	bool TwoDSpriteOpenGl::BoundOrNot() const {
		return false;
	}

}