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
	const std::vector<std::string> picturesForHero{ "Assets/images/SpiderStanding.png","Assets/images/SpiderUp1.png", "Assets/images/SpiderUp2.png", "Assets/images/SpiderUp3.png",
		"Assets/images/SpiderUp4.png", "Assets/images/SpiderUp5.png", "Assets/images/SpiderRight1.png","Assets/images/SpiderRight2.png",
		"Assets/images/SpiderRight3.png", "Assets/images/SpiderRight4.png","Assets/images/SpiderRight5.png","Assets/images/SpiderRight6.png", "Assets/images/SpiderRight7.png",
		"Assets/images/SpiderDown1.png","Assets/images/SpiderDown2.png", "Assets/images/SpiderDown3.png", "Assets/images/SpiderDown4.png", "Assets/images/SpiderDown5.png",
		"Assets/images/SpiderDown6.png", "Assets/images/SpiderDown7.png", "Assets/images/SpiderDown8.png", "Assets/images/SpiderDown9.png","Assets/images/SpiderDown10.png", 
		"Assets/images/SpiderLeft.png"};
	Things Hero{picturesForHero};

	// Store important indices of the Hero Entity for animations 
	const int STARTINDEXFORUP = 1;
	const int ENDINDEXFORUP = 5;

	const int STARTINDEXFORRIGHT = 6;
	const int ENDINDEXFORRIGHT = 12;

	const int STARTINDEXFORDOWN = 13;
	const int ENDINDEXFORDOWN = 22;

	// Variables used to alternate between sprites so the animations can occur for movement
	int counterForUpMovement = 1;
	int delayForMovement = 1;

	int counterForRightMovement = 6;
	int delayForRightMovement = 1;

	int counterForDownMovement = 13;
	int delayForDownMovement = 1;

	std::vector<Things> enemies{ {{"Assets/images/enemy2.png"}} };

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
	Things BackGround{ {"Assets/images/Background.png","Assets/images/BackgroundTwo.png"}};
};

