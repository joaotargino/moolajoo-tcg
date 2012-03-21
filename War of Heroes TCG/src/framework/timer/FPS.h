/*
 * FPS.h
 *
 *  Created on: 31/01/2012
 *      Author: Aranha
 */

#ifndef FPS_H_
#define FPS_H_

#include <SDL/SDL.h>

class FPS {
private:
	int ONE_SECOND;

	long startTime;

	long lastTime;

	int deltaTime;

	int framesPerSecond;

	int frames;
public:
	FPS();
	virtual ~FPS();

	void onLoop();

	int getFPS();

	int getDeltaTime();
};

#endif /* FPS_H_ */
