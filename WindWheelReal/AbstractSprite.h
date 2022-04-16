#pragma once

namespace WWR {
	class AbstractSprite {
	public:
		virtual int GetWidth() const =0;
		virtual int GetHeight() const =0;
		virtual void Bind() =0;
		virtual bool BoundOrNot() const = 0;
	private:

	};
}