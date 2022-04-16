#pragma once
#include "AbstractShader.h"

namespace WWR {
	class OpenGlShaderProgram :public AbstractShader {
	public:
		OpenGlShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);
		virtual void SetUniform3Ints(const std::string& nameOfUniform, int val1, int val2, int val3) override;
		virtual void SetUniform2Ints(const std::string& nameOfUniform, int val1, int val2) override;
		virtual void Bind() override;
	
	private:
		// Shader Program ID member
		unsigned int ShaderProgramID;
	};
}


