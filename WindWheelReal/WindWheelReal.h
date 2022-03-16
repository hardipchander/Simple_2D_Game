#pragma once
#include "WindWheelRealApp.h"

#define WWR_BEGIN_APP(gameapp) \
\
int main()\
{\
	gameapp game;\
	game.Run();\
}