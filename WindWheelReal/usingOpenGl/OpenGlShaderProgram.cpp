#include "precompilehead.h"
#include "OpenGlShaderProgram.h"
#include "glad/glad.h"
#include "WwrMacroDefinitions.h"

namespace WWR {

	OpenGlShaderProgram::OpenGlShaderProgram(const std::string& vertexShader, const std::string& fragmentShader) {
		// Add vertex shader first -----------------------------------------------------------------
		unsigned int vertexShaderID;
		vertexShaderID = glCreateShader(GL_VERTEX_SHADER);

		// Reading the Fragment Shader line by line 
		std::string sourceCodeVertexShader;
		std::ifstream vertexShadeInput{vertexShader};

		while (vertexShadeInput) {
			std::string singleLine;
			std::getline(vertexShadeInput,singleLine);

			// store all lines of vertex shader into sourceCodeVertexShader variable 
			sourceCodeVertexShader = sourceCodeVertexShader + singleLine;
		}

		// Do not forget to close input stream
		vertexShadeInput.close();

		// Need this for function it needs a lvalue 
		const char* source= sourceCodeVertexShader.c_str();

		// Connect string of vertex shader with its ID
		glShaderSource(vertexShaderID, 1, &source, NULL);
		glCompileShader(vertexShaderID); // Compile the Vertex Shader

		// Error Checking for Vertex Shader 
		int good;
		char infoLog[512];
		glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &good);
		if (!good) {
			glGetShaderInfoLog(vertexShaderID, 512, NULL, infoLog);
			WWR_LOG("Error Vertex Shader does not compile");
		}

		// Adding the Fragment shader -----------------------------------------------------------

	}

	void OpenGlShaderProgram::Bind() {
		glUseProgram(ShaderProgramID);
	}
}