#pragma once
#include "WindWheelReal.h"
#include "Things.h"
#include <vector>

// We connect softwareframework(GameEngine) to Game Appilication,the Game Appilication itself is a GameEngineObject(WindWheelRealApp) (inheritance is-a relationship)
class MyGameApp : public WWR::WindWheelRealApp {
public:
	virtual void OnUpdate() override;
	bool CollideX(const Things & one, const Things& another);
	bool CollideY(const Things& one, const Things& another);

private:
	Things Hero{ {"Assets/images/jimmy.png","Assets/images/sheen.png"}};
	std::vector<Things> Immovables;

	enum class HeroStates {STANDING,RUNNING,JUMPING } heroState{HeroStates::STANDING};
	enum class HeroDirections {LEFT,RIGHT} heroDirections{HeroDirections::RIGHT};

	// Speed is mesured in pixels per frame 
	int HorizontalSpeed{0};
	int VerticalSpeed{0};

};