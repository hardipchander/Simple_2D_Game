#include "WindWheelReal.h"
// We connect softwareframework(GameEngine) to Game Appilication 
// The Game Appilication itself is a GameEngineObject(WindWheelRealApp) (inheritance is-a relationship)

class MyGameApp : public WWR::WindWheelRealApp {

};

// Macro below has a main function that creates a MYGameApp object and calls its Run Function (Run Function calls OnUpdate Function in it)
// MyGameApp object is basically a child of the WindWheelApp object and it stands for MYGame Appication 
WWR_BEGIN_APP(MyGameApp);