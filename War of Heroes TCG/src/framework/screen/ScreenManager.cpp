/*
 * ScreenManager.cpp
 *
 *  Created on: 25/01/2012
 *      Author: Aranha
 */

#include "ScreenManager.h"

ScreenManager* ScreenManager::instance;

ScreenManager* ScreenManager::getInstance() {
	if (instance == NULL)
		instance = new ScreenManager();
	return instance;
}

ScreenManager::ScreenManager() {
	currentScreen = NULL;

	running = false;
}

ScreenManager::~ScreenManager() {
	// TODO Auto-generated destructor stub
}

void ScreenManager::onInit(Game game) {
	this->game = game;
	running = true;
}

void ScreenManager::onDispose() {
	if (currentScreen)
		currentScreen->onDispose();
	currentScreen = NULL;

	game.onDispose();

	onExit();
}

bool ScreenManager::isRunning() {
	return running;
}

void ScreenManager::onExit() {
	if (currentScreen)
		currentScreen->onDispose();
//	SDL_Delay(500);
	running = false;
}

void ScreenManager::onLoop(float deltaTime) {
	if (currentScreen)
		currentScreen->onLoop(deltaTime);
}

void ScreenManager::onRender() {
	if (currentScreen)
		currentScreen->onRender();
}

void ScreenManager::setCurrentScreen(Screen* screen) {
	if (currentScreen)
		currentScreen->onDispose();

	currentScreen = screen;

	if (currentScreen)
		currentScreen->onInit(game);
}
