#include "MyGameApp.h"
#include <cmath>

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

		case WWR_KEY_UP:
			VerticalSpeed = 5;
			Hero.SetIndexOfCurrentImage(0);
			break;

		case WWR_KEY_DOWN:
			VerticalSpeed = -5;
			Hero.SetIndexOfCurrentImage(1);
			break;

		}

	});

	// If you not pressing anything then hero does not move 
	SetKeyReleasedCallBack([this](const WWR::KeyReleasedEvent& e) {
		HorizontalSpeed=0;
		VerticalSpeed=0;
	});

	// Set up Enemy coordinates for the screen
	enemies[0].SetX(400);
	enemies[0].SetY(400);

	// Make sure that random numbers are generated not pseudorandom numbers
	srand(time(0));

	// Set Coordinates for the Backgorund Entity
	BackGround.SetX(0);
	BackGround.SetY(0);

}

// Called before drawing every frame 
void MyGameApp::OnUpdate() {
	// On every on update draw the background
	BackGround.Draw();

	// Check if the Game is Over, did the Hero collide with enemy, if not continue Game   
	if (!GameOver) {
		// Updating the new coordinates of hero and making sure Hero can go around all 4 borders of the game wall
		if ((Hero.GetX() + HorizontalSpeed) < 0) {
			Hero.SetX((Hero.GetX() + HorizontalSpeed) + WWR::WinForGame::GetWinForGame()->getWidth());
		}
		if ((Hero.GetY() + VerticalSpeed < 0)) {
			Hero.SetY((Hero.GetY() + VerticalSpeed) + WWR::WinForGame::GetWinForGame()->getHeight());
		}

		Hero.SetX((abs(Hero.GetX() + HorizontalSpeed)) % WWR::WinForGame::GetWinForGame()->getWidth());
		Hero.SetY((abs(Hero.GetY() + VerticalSpeed)) % WWR::WinForGame::GetWinForGame()->getHeight());

		// Random Enemy Movement
		// Play with numDetermineMovmentOfEnemy to more randomness 
		int numDetermineMovementOfEnemy = rand() % 200 + 1;
		if (numDetermineMovementOfEnemy <= 5) {
			enemyMovement = ModeOFMovement::VERTICAL;
		}
		else if (numDetermineMovementOfEnemy <= 10) {
			enemyMovement = ModeOFMovement::HORIZONTAL;
		}
		else {
			//The Mode of Movement stays the same 
		}

		// Move the enemy based on the mode of movement 
		if (enemyMovement == ModeOFMovement::VERTICAL) {
			if (enemies[0].GetY() <= 0) {
				enemyVerticalSpeed *= -1;
			}
			else if (enemies[0].GetY() > WWR::WinForGame::GetWinForGame()->getHeight() - enemies[0].GetHeight()) {
				enemyVerticalSpeed *= -1;
			}

			// Update coordinates of enemy based on mode of movement 
			enemies[0].SetY(enemies[0].GetY() + enemyVerticalSpeed);
		}
		else {
			if (enemies[0].GetX() <= 0) {
				enemyHorizontalSpeed *= -1;
			}
			else if (enemies[0].GetX() > WWR::WinForGame::GetWinForGame()->getWidth() - enemies[0].GetWidth()) {
				enemyHorizontalSpeed *= -1;
			}

			// Update coordinates of enemy based on mode of movement 
			enemies[0].SetX(enemies[0].GetX() + enemyHorizontalSpeed);
		}


		// Check if collison occurs and then set GameOver to true
		if (Collide(Hero, enemies[0])) {
			GameOver = true;

			//Set coordinates of Ending Entity to the center of the screen
			Ending.SetX((WWR::WinForGame::GetWinForGame()->getWidth() / 2)- (Ending.GetWidth()/2));
			Ending.SetY((WWR::WinForGame::GetWinForGame()->getHeight() / 2) -(Ending.GetHeight()/2));
		}

		Hero.Draw();
		enemies[0].Draw();
	}
	else {
		// Draw the Ending Entity and the Background Entity 
		BackGround.Draw();
		Ending.Draw();
	}
	
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

	if ((oneLeft <= anotherLeft && anotherLeft <= oneRight) || (anotherLeft <= oneLeft && oneLeft <= anotherRight)) {
		collideOnX = true;
	}

	if ((oneBottom <= anotherBottom && anotherBottom <= oneTop) || (anotherBottom <= oneBottom && oneBottom <= anotherTop)) {
		collideOnY = true;
	}

	return collideOnX && collideOnY;
}


