#include "precompilehead.h"
#include "WindWheelRealApp.h"

namespace WWR {
	void WindWheelRealApp::Run() {
		WWR_LOG("WindWheelReal is running");
		while (true) {
			
			OnUpdate();
		}
	}

	void WindWheelRealApp::OnUpdate() {

	}
}