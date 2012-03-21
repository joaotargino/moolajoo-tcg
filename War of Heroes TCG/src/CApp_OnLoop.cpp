//==============================================================================
#include "CApp.h"

#include <vector>
#include <iostream>
#include <stdio.h>

#include "game/readers/HeroReader.h"

//==============================================================================
void CApp::OnLoop() {
	ScreenManager::getInstance()->onLoop(fps.getDeltaTime());

	fps.onLoop();

	char buffer[255];
	sprintf(buffer, "%d", fps.getFPS());
	SDL_WM_SetCaption(buffer, buffer);

	HeroReader h;

	std::vector<Hero> heroes = h.findClasses("heroes.xml");
	for (unsigned int i = 0; i < heroes.size(); i++)
		std::cout << heroes[i].toString() << std::endl;
}

//==============================================================================
