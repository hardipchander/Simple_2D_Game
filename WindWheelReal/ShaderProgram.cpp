#include "precompilehead.h"
#include "ShaderProgram.h"
#include "usingOpenGl/OpenGlShaderProgram.h"

namespace WWR {

	ShaderProgram::ShaderProgram(const std::string& vertexFile, const std::string& fragmentFile) {
#if WWR_OPENGL
		implement = new OpenGlShaderProgram{vertexFile ,fragmentFile};
#else 
		#Only_OpenGl_is_supported_for_now
#endif
	}

	void ShaderProgram::SetUniform3Ints(const std::string& nameOfUniform, int val1, int val2, int val3) {
		implement->SetUniform3Ints(nameOfUniform,val1,val2,val3);
	}

	void ShaderProgram::SetUniform2Ints(const std::string& nameOfUniform, int val1, int val2) {
		implement->SetUniform2Ints(nameOfUniform, val1, val2);
	}

	void ShaderProgram::Bind() {
		implement->Bind();
	}
}
