#pragma once
#include "WindWheelRealApp.h"
#include "WinForGame.h"

#define WWR_BEGIN_APP(gameapp) \
\
int main()\
{\
	gameapp game;\
	game.Run();\
}