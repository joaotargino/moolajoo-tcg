/*
 * Audio.h
 *
 *  Created on: 24/01/2012
 *      Author: Aranha
 */

#ifndef AUDIO_H_
#define AUDIO_H_

#include "Sound.h"
#include "Music.h"

class Audio {
public:
	Audio();
	virtual ~Audio();

	Music newMusic(const char* filename);

	Sound newSound(const char* filename);
};

#endif /* AUDIO_H_ */
