/*
 * Music.cpp
 *
 *  Created on: 24/01/2012
 *      Author: Aranha
 */

#include "Music.h"

const static char* LABEL = "Music Class";

Mix_Music* music;
bool isPrepared;

void onCompletion() {
	isPrepared = false;
}

//Music::Music() {
//	music = NULL;
//	isPrepared = false;
//}

Music::Music(const char* filename) {
	music = NULL;
	music = Mix_LoadMUS(FileIO::getMusic(filename));
	if (!music)
		printf("%s: Mix_LoadMUS(\"%s\"): %s\n", LABEL, filename, Mix_GetError());
	isPrepared = true;
	Mix_HookMusicFinished(onCompletion);
}

Music::~Music() {
	music = NULL;
}

void Music::play() {
	if (!music)
		return;
	if (isPlaying())
		return;

	if (!isPrepared) {
		Mix_RewindMusic();
		isPrepared = true;
	}

	Mix_PlayMusic(music, -1);
}

void Music::stop() {
	Mix_HaltMusic();
	isPrepared = false;
}

void Music::pause() {
	if (isPlaying())
		Mix_PauseMusic();
}

void Music::setVolume(int volume) {
	Mix_VolumeMusic(volume);
}

bool Music::isPlaying() {
	return Mix_PlayingMusic();
}

bool Music::isStopped() {
	return !isPrepared;
}

void Music::dispose() {
	stop();

	if (music)
		Mix_FreeMusic(music);
	music = NULL;
}
