/*
 * Sound.cpp
 *
 *  Created on: 24/01/2012
 *      Author: Arthur
 */

#include "Sound.h"

const static char* LABEL = "Sound Class";
Mix_Chunk* sound;

Sound::Sound(const char* filename) {
	sound = NULL;
	sound = Mix_LoadWAV(FileIO::getSound(filename));

	if (!sound)
		printf("%s: Mix_LoadWAV(\"%s\"): %s\n", LABEL, filename, Mix_GetError());
}

Sound::~Sound() {
	sound = NULL;
}

void Sound::play() {
	Mix_PlayChannel(-1, sound, 0);
}

void Sound::play(int volume) {
	Mix_VolumeChunk(sound, volume);
	Mix_PlayChannel(-1, sound, 0);
}

void Sound::dispose() {
	if (sound)
		Mix_FreeChunk(sound);
	sound = NULL;
}
