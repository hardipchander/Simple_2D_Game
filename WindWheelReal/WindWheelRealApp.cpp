#include "precompilehead.h"

#include "WindWheelRealApp.h"
#include "WinForGame.h"
//#include "GLFW/glfw3.h"   // for window screen 
#include "glad/glad.h"    // for OpenGl and drawing 
#include "TwoDSprite.h"

namespace WWR {
	void WindWheelRealApp::Run() {
		// WWR_LOG is a macro used for debug printing it only works in the Debug Build
		WWR_LOG("WindWheelReal is runnning");

		// Create Window with singelton 
		WWR::WinForGame::Init();
		const std::string WindowName = "Screen For Game";
		WWR::WinForGame::GetWinForGame()->CreateWindow(900, 900, WindowName);


		//Adding Shaders Now
		const char * vertexShader= R"(
			#version 330 core
			layout (location=0) in vec2 rawCoords;
			layout (location=1) in vec2 tCoordInput;
			
			out vec2 TexturePoints;

			void main()
			{
				gl_Position=vec4(rawCoords.x, rawCoords.y, 0.0f, 1.0f);
				TexturePoints= tCoordInput;
			} 
		)";

		const char* fragmentShader = R"(
			#version 330 core
			out vec4 FragColor;
			
			in vec2 TexturePoints;

			uniform sampler2D picture;

			void main()
			{
				FragColor=texture(picture, TexturePoints);
				// FragColor= vec4(1.0f, 0.0f, 0.0f, 1.0f);
			} 
		)";

		// Creating the vertex shader with its ID
		unsigned int vertexShadeID = glCreateShader(GL_VERTEX_SHADER);

		// Connect string of vertex shader with its ID
		glShaderSource(vertexShadeID, 1, &vertexShader, NULL);
		glCompileShader(vertexShadeID); // Compile the Vertex Shader

		// Error Checking for Vertex Shader 
		int good;
		char infoLog[512];
		glGetShaderiv(vertexShadeID,GL_COMPILE_STATUS,&good);
		if (!good) {
			glGetShaderInfoLog(vertexShadeID,512,NULL, infoLog);
			WWR_LOG("Error Vertex Shader does not compile");
		}

		//-----------------------------------------------------------------------------------------
		// Creating the fragment shader with its ID
		unsigned int fragmentShadeID = glCreateShader(GL_FRAGMENT_SHADER);

		// Connect string of vertex shader with its ID
		glShaderSource(fragmentShadeID, 1, &fragmentShader, NULL);
		glCompileShader(fragmentShadeID); // Compile the Fragment Shader

		// Error Checking for Vertex Shader 
		glGetShaderiv(fragmentShadeID, GL_COMPILE_STATUS, &good);
		if (!good) {
			glGetShaderInfoLog(fragmentShadeID, 512, NULL, infoLog);
			WWR_LOG("Error Fragment Shader does not compile");
		}

		// Linking the shaders 
		unsigned int shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShadeID);
		glAttachShader(shaderProgram, fragmentShadeID);
		glLinkProgram(shaderProgram);

		// Error checking for linking shaders
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &good);
		if (!good) {
			glGetProgramInfoLog(shaderProgram,512, NULL,infoLog);
			WWR_LOG("Error in linking the vertex shader and fragment shader");
		}

		// Deleting the shaders after 
		glDeleteShader(vertexShadeID);
		glDeleteShader(fragmentShadeID);

		WWR::TwoDSprite sprite{"../WindWheelReal/Assets/Flash.png"};

		while (true) {
			// in this loop I will get user input and update the frame 
			// OnUpdate on what happens on each run of the game or each loop of the gamse  
			OnUpdate();

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glUseProgram(shaderProgram);
			sprite.Bind();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			
			// Swap Buffers and Poll events for Glfw Window
			WWR::WinForGame::GetWinForGame()->UpdateBuffers();
			WWR::WinForGame::GetWinForGame()->TakeEvents();
		}
	}

	void WindWheelRealApp::OnUpdate() {

	}
}