/*
 * Game.h
 *
 *  Created on: 25/01/2012
 *      Author: Aranha
 */

#ifndef GAME_H_
#define GAME_H_

#include "../audio/Audio.h"
#include "../graphic/Graphic.h"
#include "../input/Input.h"
#include "../input/InputManager.h"

class Game {
private:
	Audio audio;

	Graphic graphic;

	Input input;
public:
	Game();
	virtual ~Game();

	void onInit(SDL_Surface* surface, InputManager* inputManager);

	void onDispose();

	Audio getAudio();

	Graphic getGraphic();

	Input getInput();
};

#endif /* GAME_H_ */
