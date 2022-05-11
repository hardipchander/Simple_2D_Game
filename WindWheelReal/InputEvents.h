#pragma once

#include "WwrMacroDefinitions.h"

namespace WWR {
	class WWR_API KeyPressedEvent {
	public:
		KeyPressedEvent(int codeOfKey);
		KeyPressedEvent() = delete;

		int GetKeyCode() const;

	private:
		int keyCode;
	};

	class WWR_API KeyReleasedEvent {
	public:
		KeyReleasedEvent(int codeOfKey);
		KeyReleasedEvent() = delete;

		int GetKeyCode() const;

	private:
		int keyCode;
	};
}

