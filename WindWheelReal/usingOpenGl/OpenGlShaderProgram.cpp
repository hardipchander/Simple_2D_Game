#include "precompilehead.h"
#include "OpenGlShaderProgram.h"
#include "glad/glad.h"
#include "WwrMacroDefinitions.h"

namespace WWR {

	OpenGlShaderProgram::OpenGlShaderProgram(const std::string& vertexShader, const std::string& fragmentShader) {
		// Add vertex shader first -----------------------------------------------------------------
		unsigned int vertexShaderID;
		vertexShaderID = glCreateShader(GL_VERTEX_SHADER);

		// Reading the Vertex Shader line by line 
		std::string sourceCodeShader;
		std::ifstream vertexShadeInput{vertexShader};

		while (vertexShadeInput) {
			std::string singleLine;
			std::getline(vertexShadeInput,singleLine);
			singleLine.append("\n");
			// store all lines of vertex shader into sourceCodeVertexShader variable 
			sourceCodeShader = sourceCodeShader + singleLine;
		}

		// Do not forget to close input stream
		vertexShadeInput.close();

		// Need this for function it needs a lvalue 
		const char* source= sourceCodeShader.c_str();

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
		// Creating the fragment shader with its ID
		unsigned int fragmentShadeID; 
		fragmentShadeID=glCreateShader(GL_FRAGMENT_SHADER);

		// Reading the Fragment Shader line by line 
		sourceCodeShader.clear();
		std::ifstream FragmentShadeInput{fragmentShader};

		while (FragmentShadeInput) {
			std::string singleLine;
			std::getline(FragmentShadeInput, singleLine);
			singleLine.append("\n");

			// store all lines of vertex shader into sourceCodeVertexShader variable 
			sourceCodeShader = sourceCodeShader + singleLine;
		}

		// Do not forget to close input stream
		FragmentShadeInput.close();
		const char* fragmentsource = sourceCodeShader.c_str();

		// Connect string of vertex shader with its ID
		glShaderSource(fragmentShadeID, 1, &fragmentsource, NULL);
		glCompileShader(fragmentShadeID); // Compile the Fragment Shader

		// Error Checking for Vertex Shader 
		glGetShaderiv(fragmentShadeID, GL_COMPILE_STATUS, &good);
		if (!good) {
			glGetShaderInfoLog(fragmentShadeID, 512, NULL, infoLog);
			WWR_LOG("Error Fragment Shader does not compile");
		}

		// Linking the shaders 
		ShaderProgramID = glCreateProgram();
		glAttachShader(ShaderProgramID, vertexShaderID);
		glAttachShader(ShaderProgramID, fragmentShadeID);
		glLinkProgram(ShaderProgramID);

		// Error checking for linking shaders
		glGetProgramiv(ShaderProgramID, GL_LINK_STATUS, &good);
		if (!good) {
			glGetProgramInfoLog(ShaderProgramID, 512, NULL, infoLog);
			WWR_LOG("Error in the linking of the vertex shader and fragment shader");
		}

		// Deleting the shaders after 
		glDeleteShader(vertexShaderID);
		glDeleteShader(fragmentShadeID);

	}

	void OpenGlShaderProgram::SetUniform3Ints(const std::string& nameOfUniform, int val1, int val2, int val3) {
		int uniformLocation{ glGetUniformLocation(ShaderProgramID,nameOfUniform.c_str())};
		glUseProgram(ShaderProgramID);
		glUniform3i(uniformLocation,val1,val2,val3);
	}

	void OpenGlShaderProgram::SetUniform2Ints(const std::string& nameOfUniform, int val1, int val2) {
		int uniformLocation{ glGetUniformLocation(ShaderProgramID,nameOfUniform.c_str()) };
		glUseProgram(ShaderProgramID);
		glUniform2i(uniformLocation, val1, val2);
	}

	void OpenGlShaderProgram::Bind() {
		// Activate the Shader 
		glUseProgram(ShaderProgramID);
	}
}