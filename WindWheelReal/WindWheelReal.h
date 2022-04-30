#pragma once
#include "WindWheelRealApp.h"
#include "WinForGame.h"
#include "TwoDSprite.h"
#include "ShaderProgram.h"
#include "SingleRenderer.h"

#define WWR_BEGIN_APP(gameapp) \
\
int main()\
{\
	gameapp game;\
	game.Run();\
}