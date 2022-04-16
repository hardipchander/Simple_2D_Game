#pragma once

#include "WwrMacroDefinitions.h"
#include "AbstractShader.h"

namespace WWR {
	class WWR_API ShaderProgram
	{
	public:
		ShaderProgram(const std::string & vertexFile, const std::string & fragmentFile);

		void Bind();

	private:
		AbstractShader* implement;
	};
}


