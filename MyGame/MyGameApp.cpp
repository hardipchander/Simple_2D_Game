#include "MyGameApp.h"
#include <cmath>

// In constructor of GameApp set up key and the coordinates 
MyGameApp::MyGameApp() {
	SetKeyPressedCallBack([this](const WWR::KeyPressedEvent & e) {
		switch (e.GetKeyCode()) 
		{
		case WWR_KEY_LEFT:
			HorizontalSpeed = -5;
			Hero.SetIndexOfCurrentImage(picturesForHero.size()-1);
			break;

		case WWR_KEY_RIGHT:
			HorizontalSpeed = 5;
			// Logic for the animation for 7 images 
			if (counterForRightMovement == ENDINDEXFORRIGHT+1) {
				counterForRightMovement = STARTINDEXFORRIGHT;
			}
			Hero.SetIndexOfCurrentImage(counterForRightMovement);

			// Slow so the animation can happen slowly 
			if (delayForRightMovement <= 4) {
				delayForRightMovement++;
			}
			else if (delayForRightMovement > 4) {
				counterForRightMovement++;
				delayForRightMovement = 1;
			}

			break;

		case WWR_KEY_UP:
			VerticalSpeed = 5;
			// Logic for the animation for 5 images 
			if (counterForUpMovement == ENDINDEXFORUP+1) {
				counterForUpMovement = STARTINDEXFORUP;
			}
			Hero.SetIndexOfCurrentImage(counterForUpMovement);

			// Slow so the animation can happen slowly 
			if (delayForMovement <= 4) {
				delayForMovement++;
			}
			else if (delayForMovement > 4) {
				counterForUpMovement++;
				delayForMovement = 1;
			}

			break;

		case WWR_KEY_DOWN:
			VerticalSpeed = -5;
			// Logic for the animation for 10 images 
			if (counterForDownMovement == ENDINDEXFORDOWN + 1) {
				counterForDownMovement = STARTINDEXFORDOWN;
			}

			Hero.SetIndexOfCurrentImage(counterForDownMovement);

			// Slow so the animation can happen slowly 
			if (delayForDownMovement <= 5) {
				delayForDownMovement++;
			}
			else if (delayForDownMovement > 5) {
				counterForDownMovement++;
				delayForDownMovement = 1;
			}
			break;

		case WWR_KEY_SPACE:
			// If the space key is pressed when the game is over then the game resets 
			if (GameOver == true) {
				Reset();
			}
			// If the space key is pressed when the game user decides to first start playing the game 
			if (GameStart == true) {
				GameStart = false;
				delayForLogo = 1; // make sure reset the delay for the Spider Logos for the end of the Game  
			}
			break;

		}

	});

	// If you not pressing anything then hero does not move 
	SetKeyReleasedCallBack([this](const WWR::KeyReleasedEvent& e) {
		Hero.SetIndexOfCurrentImage(0);
		HorizontalSpeed=0;
		VerticalSpeed=0;
		
	});

	// Set up Enemy coordinates for the screen for the center of the screen 
	enemies[0].SetX((WWR::WinForGame::GetWinForGame()->getWidth() / 2) - (enemies[0].GetWidth() / 2));
	enemies[0].SetY((WWR::WinForGame::GetWinForGame()->getHeight() / 2) - (enemies[0].GetHeight() / 2));

	// Make sure that random numbers are generated not pseudorandom numbers
	srand(time(0));

	// Set Coordinates for the Background Entity for all Background Images
	BackGround.SetX(0); // (0,0) is the left most corner
	BackGround.SetY(0);

	// Have the Spider Logos Coordinates set for when the game is over 
	SpiderLogos[0].SetX(0); // Bottom left corner logo
	SpiderLogos[0].SetY(0);

	SpiderLogos[1].SetX(0);  // Top left corner logo
	SpiderLogos[1].SetY(WWR::WinForGame::GetWinForGame()->getHeight()- SpiderLogos[1].GetHeight());

	SpiderLogos[2].SetX(WWR::WinForGame::GetWinForGame()->getWidth() - SpiderLogos[2].GetWidth());  // Top right corner logo
	SpiderLogos[2].SetY(WWR::WinForGame::GetWinForGame()->getHeight() - SpiderLogos[2].GetHeight());

	SpiderLogos[3].SetX(WWR::WinForGame::GetWinForGame()->getWidth() - SpiderLogos[3].GetWidth());  // Bottom right corner logo
	SpiderLogos[3].SetY(0);
	
	// Setting the Coordinates for the Begin Entity
	Begin.SetX((WWR::WinForGame::GetWinForGame()->getWidth() / 2) - (Begin.GetWidth() / 2));
	Begin.SetY((WWR::WinForGame::GetWinForGame()->getHeight() / 2) - (Begin.GetHeight() / 2));
}

// Called before drawing every frame 
void MyGameApp::OnUpdate() {
	// If at the starting screen of the game, the game user hasn't pressed the space button yet to play  
	if (GameStart == true) {
		// Have the starting screen change colors between Red and Blue 
		int randBackGroundColor = rand() % 200 + 1;
		if (randBackGroundColor < 5) {
			WWR::SingleRenderer::ClearWindowBasedOnColor("Red");
			previousColor = "Red";
		}
		else if(randBackGroundColor < 10) {
			WWR::SingleRenderer::ClearWindowBasedOnColor("Blue");
			previousColor = "Blue";

		}
		else {
			// The background color stays the same 
			WWR::SingleRenderer::ClearWindowBasedOnColor(previousColor);
		}

		// Draw beginning Entity
		Begin.Draw();

		// Drawing the spider logos and updating the index by incrementing it
		SpiderLogos[0].Draw();
		SpiderLogos[1].Draw();
		SpiderLogos[2].Draw();
		SpiderLogos[3].Draw();

		// Slower the rotation animation by adding a delay
		if (delayForLogo < 15) {
			delayForLogo++;
		}
		else if (delayForLogo >= 15) {
			SpiderLogos[0].SetIndexOfCurrentImage((SpiderLogos[0].GetIndexOfCurrentImage() + 1) % 4);
			SpiderLogos[1].SetIndexOfCurrentImage((SpiderLogos[1].GetIndexOfCurrentImage() + 1) % 4);
			SpiderLogos[2].SetIndexOfCurrentImage((SpiderLogos[2].GetIndexOfCurrentImage() + 1) % 4);
			SpiderLogos[3].SetIndexOfCurrentImage((SpiderLogos[3].GetIndexOfCurrentImage() + 1) % 4);

			delayForLogo = 1;
		}
	}
	else { // The game user has pressed the space key to play the game for the first time 

		// On every on update draw the background but need randomness to have many backgrounds
		int numRandom = rand() % 200 + 1;
		if (numRandom <= 1 && !GameOver) {
			BackGround.SetIndexOfCurrentImage(0);
			BackGround.Draw();
		}
		else if (numRandom <= 2 && !GameOver) {
			BackGround.SetIndexOfCurrentImage(1);
			BackGround.Draw();
		}
		else {
			//The Background stays the same
			BackGround.Draw();
		}


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
			if (numRandom <= 5) {
				enemyMovement = ModeOFMovement::VERTICAL;
			}
			else if (numRandom <= 10) {
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
				Ending.SetX((WWR::WinForGame::GetWinForGame()->getWidth() / 2) - (Ending.GetWidth() / 2));
				Ending.SetY((WWR::WinForGame::GetWinForGame()->getHeight() / 2) - (Ending.GetHeight() / 2));
			}

			Hero.Draw();
			enemies[0].Draw();
		}
		else {
			// Draw the Ending Entity and the Background Entity because the Game is over at this point 
			BackGround.Draw();
			Ending.Draw();

			// Drawing the spider logos and updating the index by incrementing it
			SpiderLogos[0].Draw();
			SpiderLogos[1].Draw();
			SpiderLogos[2].Draw();
			SpiderLogos[3].Draw();

			// Slower the rotation animation by adding a delay
			if (delayForLogo < 15) {
				delayForLogo++;
			}
			else if (delayForLogo >= 15) {
				SpiderLogos[0].SetIndexOfCurrentImage((SpiderLogos[0].GetIndexOfCurrentImage() + 1) % 4);
				SpiderLogos[1].SetIndexOfCurrentImage((SpiderLogos[1].GetIndexOfCurrentImage() + 1) % 4);
				SpiderLogos[2].SetIndexOfCurrentImage((SpiderLogos[2].GetIndexOfCurrentImage() + 1) % 4);
				SpiderLogos[3].SetIndexOfCurrentImage((SpiderLogos[3].GetIndexOfCurrentImage() + 1) % 4);

				delayForLogo = 1;
			}

		}
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

// Resets the game if the user decides to play the game again after he or she died 
void MyGameApp::Reset() {
	// Game is back on
	GameOver = false;

	// Reset coordinates of Hero and Enemy 
	enemies[0].SetX((WWR::WinForGame::GetWinForGame()->getWidth() / 2) - (enemies[0].GetWidth() / 2));
	enemies[0].SetY((WWR::WinForGame::GetWinForGame()->getHeight() / 2) - (enemies[0].GetHeight() / 2));

	Hero.SetX(0);
	Hero.SetY(0);
}


