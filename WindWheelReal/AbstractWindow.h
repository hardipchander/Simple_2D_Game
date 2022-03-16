#pragma once
#include "precompilehead.h"

namespace WWR {
	class AbstractWindow {
	public:
		virtual bool CreateWindow(int width, int height, const std::string& nameForWindow) = 0;
		virtual void UpdateBuffers() = 0;
		virtual void TakeEvents() = 0;
		virtual int getWidth() const = 0;
		virtual int getHeight() const = 0;

	private:

	};
}
