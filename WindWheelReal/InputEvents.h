#pragma once

namespace WWR {
	class KeyPressedEvent {
	public:
		KeyPressedEvent(int codeOfKey);
		KeyPressedEvent() = delete;

		int GetKeyCode() const;

	private:
		int keyCode;
	};

	class KeyReleasedEvent {
	public:
		KeyReleasedEvent(int codeOfKey);
		KeyReleasedEvent() = delete;

		int GetKeyCode() const;

	private:
		int keyCode;
	};
}

