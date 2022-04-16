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

	void ShaderProgram::Bind() {
		implement->Bind();
	}
}
