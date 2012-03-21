//============================================================================
// Name        : Hero.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "CApp.h"

#include "game/screens/IntroScreen.h"
#include "game/screens/ScreenFont.h"
#include "game/screens/NewGameScreen.h"

int main(int argc, char **argv) {
	CApp app;
	app.setStartScreen(new IntroScreen());
	app.setStartScreen(new NewGameScreen());

	return app.OnExecute();
}
