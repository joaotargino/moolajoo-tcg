/*
 * FPS.cpp
 *
 *  Created on: 31/01/2012
 *      Author: Aranha
 */

#include "FPS.h"

FPS::FPS() {
	ONE_SECOND = 1000;

	startTime = lastTime = deltaTime = framesPerSecond = frames = 0;
}

FPS::~FPS() {
	// TODO Auto-generated destructor stub
}

void FPS::onLoop() {
	if ((unsigned long) (startTime + ONE_SECOND) < SDL_GetTicks()) {
		startTime = SDL_GetTicks();
		framesPerSecond = frames;
		frames = 0;
	}

	deltaTime = SDL_GetTicks() - lastTime;
	lastTime = SDL_GetTicks();
	frames++;
}

int FPS::getFPS() {
	return framesPerSecond;
}

int FPS::getDeltaTime() {
	return deltaTime;
}
