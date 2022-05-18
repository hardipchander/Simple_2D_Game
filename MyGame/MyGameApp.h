#pragma once
#include "WindWheelReal.h"
#include "Things.h"
#include <vector>

// We connect softwareframework(GameEngine) to Game Appilication,the Game Appilication itself is a GameEngineObject(WindWheelRealApp) (inheritance is-a relationship)
class MyGameApp : public WWR::WindWheelRealApp {
public:
	// In constructor set up the key
	MyGameApp();

	virtual void OnUpdate() override;
	bool Collide(const Things & one, const Things& another);


private:
	Things Hero{ {"Assets/images/jimmy.png","Assets/images/sheen.png"}};
	std::vector<Things> enemies{ {{"Assets/images/enemy.png"}} };

	//Enemy orginally moving down 
	int enemyVerticalSpeed{-5};

	// Speed is mesured in pixels per frame 
	int HorizontalSpeed{0};

};

