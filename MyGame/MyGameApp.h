#pragma once
#include "WindWheelReal.h"
#include "Things.h"
#include <vector>
#include <cstdlib>
#include <ctime>

// We connect softwareframework(GameEngine) to Game Appilication,the Game Appilication itself is a GameEngineObject(WindWheelRealApp) (inheritance is-a relationship)
class MyGameApp : public WWR::WindWheelRealApp {
public:
	// In constructor set up the key
	MyGameApp();

	virtual void OnUpdate() override;
	bool Collide(const Things & one, const Things& another);


private:
	Things Hero{ {"Assets/images/jimmy.png","Assets/images/sheen.png"}};
	std::vector<Things> enemies{ {{"Assets/images/enemy.png"}}};
	enum class ModeOFMovement{VERTICAL, HORIZONTAL} enemyMovement{ModeOFMovement::VERTICAL};

	//Enemy orginally moving down or moving left
	int enemyVerticalSpeed{-5};
	int enemyHorizontalSpeed{-5};

	// Speed is mesured in pixels per frame 
	int HorizontalSpeed{0};
	int VerticalSpeed{0};

	// Ending Entity 
	Things Ending{ {"Assets/images/Ending.png"} };

	// Boolean to see if game is over 
	bool GameOver{false};

	// Background Entity 
	Things BackGround{ {"Assets/images/Background.png"}};
};

