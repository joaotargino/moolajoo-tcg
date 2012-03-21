/*
 * ScreenFont.cpp
 *
 *  Created on: 25/01/2012
 *      Author: Arthur
 */

#include "ScreenFont.h"

ScreenFont::ScreenFont() {
	x = y = 0;
}

ScreenFont::~ScreenFont() {
	// TODO Auto-generated destructor stub
}

void ScreenFont::onInit(Game game) {
	Screen::onInit(game);

	time = SDL_GetTicks();
	timer = 0;
}

void ScreenFont::onDispose() {
}

void ScreenFont::onLoop(float deltaTime) {
	if ((unsigned int) (time + 1000) <= SDL_GetTicks()) {
		time = SDL_GetTicks();
		if (game.getInput().isKeyPressed(SDLK_DOWN))
			if ((y += 16) > game.getGraphic().getHeight() - 20) y = game.getGraphic().getHeight() - 20;
		if (game.getInput().isKeyPressed(SDLK_UP))
			if ((y -= 16) < 0) y = 0;
		if (game.getInput().isKeyPressed(SDLK_RIGHT))
			if (++x > game.getGraphic().getWidth() - 11 * 20) x = game.getGraphic().getWidth() - 11 * 20;
		if (game.getInput().isKeyPressed(SDLK_LEFT))
			if (--x < 0) x = 0;

		std::vector<KeyEvent> keyEvents = game.getInput().getKeyEvents();
		for (unsigned int i = 0; i < keyEvents.size(); i++) {
			if (keyEvents[i].type == KeyEvent::KEY_UP)
				string.concat(String(keyEvents[i].keyChar));
		}

		timer++;
	}
}

void ScreenFont::onRender() {
	System::getInstance()->setColor(255, 255, 255);
	game.getGraphic().clear(System::getInstance()->getColor());
	System::getInstance()->setColor(0, 0, 255);
	game.getGraphic().drawText("Test Screen", x, y);

	game.getGraphic().drawText(string.toCharArray(), 0, 30);
	game.getGraphic().drawText(String(timer).toCharArray(), 0, 100);
}
