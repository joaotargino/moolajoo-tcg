/*
 * Music.h
 *
 *  Created on: 24/01/2012
 *      Author: Aranha
 */

#ifndef MUSIC_H_
#define MUSIC_H_

#include <SDL/SDL_mixer.h>

#include "../fileIO/FileIO.h"

class Music {
public:
//	Music();
	Music(const char* filename);
	virtual ~Music();

	void play();

	void stop();

	void pause();

	void setVolume(int volume);

	bool isPlaying();

	bool isPaused();

	bool isStopped();

	void dispose();
};

#endif /* MUSIC_H_ */
