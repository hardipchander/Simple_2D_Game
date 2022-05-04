#include "precompilehead.h"
#include "InputEvents.h"

namespace WWR {
	KeyPressedEvent::KeyPressedEvent(int codeOfKey): keyCode(codeOfKey) {
	}

	int KeyPressedEvent::GetKeyCode() const {
		return keyCode;
	}

	KeyReleasedEvent::KeyReleasedEvent(int codeOfKey) : keyCode(codeOfKey) {
	}

	int KeyReleasedEvent::GetKeyCode() const {
		return keyCode;
	}
}