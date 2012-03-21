/*
 * Screen.h
 *
 *  Created on: 25/01/2012
 *      Author: Aranha
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL/SDL.h>

#include "../game/Game.h"

class Screen {
protected:
	Game game;
public:
	Screen();
	virtual ~Screen();

	virtual void onInit(Game game);
	virtual void onDispose();

	virtual void onLoop(float deltaTime);

	virtual void onRender();
};

#endif /* SCREEN_H_ */
