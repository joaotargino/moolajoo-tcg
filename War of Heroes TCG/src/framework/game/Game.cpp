/*
 * Game.cpp
 *
 *  Created on: 25/01/2012
 *      Author: Aranha
 */

#include "Game.h"

#include <stdio.h>

Game::Game() {
	// TODO Auto-generated constructor stub

}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

void Game::onInit(SDL_Surface* surface, InputManager* inputManager) {
	graphic.onInit(surface);
	input.onInit(inputManager);
}

void Game::onDispose() {
	graphic.onDispose();
	input.onDispose();
}

Audio Game::getAudio() {
	return audio;
}

Graphic Game::getGraphic() {
	return graphic;
}

Input Game::getInput() {
	return input;
}
