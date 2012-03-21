/*
 * Sound.h
 *
 *  Created on: 24/01/2012
 *      Author: Arthur
 */

#ifndef SOUND_H_
#define SOUND_H_

#include <SDL/SDL_mixer.h>

#include "../fileIO/FileIO.h"

class Sound {
public:
	Sound(const char* filename);
	virtual ~Sound();

	void play();
	void play(int volume);

	void dispose();
};

#endif /* SOUND_H_ */
