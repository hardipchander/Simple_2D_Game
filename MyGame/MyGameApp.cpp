#include "MyGameApp.h"

// Called before drawing every frame 
void MyGameApp::OnUpdate() {
	switch (heroState) 
	{
	case HeroStates::STANDING:
		break;

	case HeroStates::RUNNING:
		// no negative speed 
	}
}

// Checks if collisons occur on x axis between 2 sprites  
bool MyGameApp::CollideX(const Things& one, const Things& another) {
	int oneLeft{one.GetX()};
	int oneRight{one.GetX()+one.GetWidth()};
	int anotherLeft{ another.GetX() };
	int anotherRight{ another.GetX() + another.GetWidth() };


	if ((anotherLeft <= oneLeft and oneLeft <= anotherRight) or
		(anotherLeft <= oneRight and oneRight <= anotherRight) or
		(oneLeft <= anotherLeft and anotherLeft <= oneRight))
		return true;
	else
		return false;

}

// Checks if collisons occur on y axis between 2 sprites  
bool MyGameApp::CollideY(const Things& one, const Things& another) {
	int oneBottom{one.GetY()};
	int oneTop{ one.GetY() + one.GetHeight() };
	int anotherBottom{ another.GetY() };
	int anotherTop{another.GetY() + another.GetHeight()};


	if ((anotherBottom <= oneBottom and oneBottom <= anotherTop) or
		(anotherBottom <= oneTop and oneTop <= anotherTop) or
		(oneBottom <= anotherBottom and anotherBottom <= oneTop))
		return true;
	else
		return false;
}
