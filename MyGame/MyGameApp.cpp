#include "MyGameApp.h"

// In constructor of GameApp set up key
MyGameApp::MyGameApp() {
	SetKeyPressedCallBack([this](const WWR::KeyPressedEvent & e) {
		// I can make it more than 2 directions, here it is 2 directions Uniqueness here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		switch (e.GetKeyCode()) 
		{
		case WWR_KEY_LEFT:
			// Setting up for moving left 
			HorizontalSpeed = -5;
			Hero.SetIndexOfCurrentImage(1);  // Change the parameter from number to variable !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			break;

		case WWR_KEY_RIGHT:
			// Setting up for moving right
			HorizontalSpeed = 5;
			Hero.SetIndexOfCurrentImage(0); // Change the parameter from number to variable !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			break;
		}
	});

	// If you not pressing anything then hero does not move 
	SetKeyReleasedCallBack([this](const WWR::KeyReleasedEvent& e) {
		HorizontalSpeed = 0;
	});

	// Set up Enemy coordinates for the screen
	enemies[0].SetX(400);
	enemies[0].SetY(400);
}

// Called before drawing every frame 
void MyGameApp::OnUpdate() {
	// Updating the new coordinates of hero
	Hero.SetX(Hero.GetX() + HorizontalSpeed);

	// If you have many enemies then you need a loop here 
	// Logic makes sure the enemy does not move out of the screen 
	if (enemies[0].GetY() <= 0) {
		enemyVerticalSpeed *= -1;
	}
	else if (enemies[0].GetY() > WWR::WinForGame::GetWinForGame()->getHeight() - enemies[0].GetHeight()) {
		enemyVerticalSpeed *= -1;
	}

	// Update coordinates of enemy 
	enemies[0].SetY(enemies[0].GetY() + enemyVerticalSpeed);

	// Check if collison occurs and then exit close window
	if (Collide(Hero, enemies[0])) {
		exit(0);
	}

	Hero.Draw();
	enemies[0].Draw();
}

// Checks if collisons occur between 2 sprites on x and y axis
bool MyGameApp::Collide(const Things& one, const Things& another) {
	int oneLeft{one.GetX()};
	int oneRight{one.GetX()+one.GetWidth()};
	int anotherLeft{ another.GetX() };
	int anotherRight{ another.GetX() + another.GetWidth() };

	int oneBottom{one.GetY()};
	int oneTop{ one.GetY() + one.GetHeight() };
	int anotherBottom{ another.GetY() };
	int anotherTop{another.GetY() + another.GetHeight()};

	bool collideOnX{false};
	bool collideOnY{false};

	if ((oneLeft <= anotherLeft and anotherLeft <= oneRight) or (anotherLeft <= oneLeft and oneLeft <= anotherRight)) {
		collideOnX = true;
	}

	if ((oneBottom <= anotherBottom and anotherBottom <= oneTop) or (anotherBottom <= oneBottom and oneBottom <= anotherTop)) {
		collideOnY = true;
	}

	return collideOnX and collideOnY;
}


