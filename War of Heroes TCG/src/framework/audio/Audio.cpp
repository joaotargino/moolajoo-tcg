/*
 * Audio.cpp
 *
 *  Created on: 24/01/2012
 *      Author: Aranha
 */

#include "Audio.h"

Audio::Audio() {
	// TODO Auto-generated constructor stub

}

Audio::~Audio() {
	// TODO Auto-generated destructor stub
}

Music Audio::newMusic(const char* filename) {
	Music temp(filename);
	return temp;
}

Sound Audio::newSound(const char* filename) {
	Sound temp(filename);
	return temp;
}
