/*
 * ScreenManager.h
 *
 *  Created on: 25/01/2012
 *      Author: Aranha
 */

#ifndef SCREENMANAGER_H_
#define SCREENMANAGER_H_

#include "Screen.h"

#include "../game/Game.h"

class ScreenManager {
private:
	static ScreenManager* instance;
	bool running;

	Game game;

	Screen* currentScreen;

	ScreenManager();
public:
	static ScreenManager* getInstance();
	virtual ~ScreenManager();

	void onInit(Game game);
	void onDispose();

	bool isRunning();

	void onExit();

	void onLoop(float deltaTime);

	void onRender();

	void setCurrentScreen(Screen* screen);
};

#endif /* SCREENMANAGER_H_ */
