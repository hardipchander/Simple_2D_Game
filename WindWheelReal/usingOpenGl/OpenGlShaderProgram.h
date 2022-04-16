#pragma once
#include "AbstractShader.h"

namespace WWR {
	class OpenGlShaderProgram :public AbstractShader {
	public:
		OpenGlShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);
		virtual void Bind() override;
	
	private:
		// Shader Program ID memeber 
		unsigned int ShaderProgramID;
	};
}


