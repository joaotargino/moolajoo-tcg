/*
 * ScreenGame.cpp
 *
 *  Created on: 25/01/2012
 *      Author: Aranha
 */

#include "ScreenGame.h"

ScreenGame::ScreenGame() {
}

ScreenGame::~ScreenGame() {
}

void ScreenGame::onInit(Game game) {
	Screen::onInit(game);
	image = game.getGraphic().newImage((char*)"background.png");
}

void ScreenGame::onDispose() {
	image.onDispose();
}

void ScreenGame::onLoop(float deltaTime) {
}

void ScreenGame::onRender() {
	game.getGraphic().drawImage(image, 0, 0);
	game.getGraphic().drawImage(image, 100, 100, 0, 0, 20, 20);
}
