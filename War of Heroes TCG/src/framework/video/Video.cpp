/*
 * Video.cpp
 *
 *  Created on: 25/01/2012
 *      Author: Aranha
 */

#include "Video.h"

Video::Video() {
	screen = NULL;
	icon = NULL;

	fullscreen = false;
}

Video::~Video() {
	screen = NULL;
	icon = NULL;
}

void Video::createWindow() {
	if (fullscreen) {
		if ((screen = SDL_SetVideoMode(600, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN)) == NULL)
			printf("ERRO");
	} else {
		if ((screen = SDL_SetVideoMode(600, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
			printf("ERRO");
	}
}

void Video::onInit() {
	createWindow();
}

void Video::onDispose() {
	if (screen)
		SDL_FreeSurface(screen);
	if (icon)
		SDL_FreeSurface(icon);

	screen = NULL;
	icon = NULL;
}

void Video::onRender() {
	SDL_Flip(screen);
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
}

void Video::setFullscreen(bool fullscreen) {
	this->fullscreen = fullscreen;
	createWindow();
}

void Video::toggleFullscreen() {
	setFullscreen(!fullscreen);
}

SDL_Surface* Video::getScreen() {
	return screen;
}
