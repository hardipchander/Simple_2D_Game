#pragma once

namespace WWR {
	class AbstractShader {
	public :
		virtual void SetUniform3Ints(const std::string& nameOfUniform, int val1, int val2, int val3) =0;
		virtual void SetUniform2Ints(const std::string& nameOfUniform, int val1, int val2) =0;
		virtual void Bind() = 0;

	};
}