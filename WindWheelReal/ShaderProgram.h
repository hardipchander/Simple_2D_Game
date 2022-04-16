#pragma once

#include "WwrMacroDefinitions.h"
#include "AbstractShader.h"

namespace WWR {
	class WWR_API ShaderProgram
	{
	public:
		ShaderProgram(const std::string & vertexFile, const std::string & fragmentFile);
		void SetUniform3Ints(const std::string & nameOfUniform, int val1, int val2, int val3);
		void SetUniform2Ints(const std::string& nameOfUniform, int val1, int val2);
		void Bind();

	private:
		AbstractShader* implement;
	};
}


