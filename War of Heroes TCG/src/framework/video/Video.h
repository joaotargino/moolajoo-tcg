/*
 * Video.h
 *
 *  Created on: 25/01/2012
 *      Author: Aranha
 */

#ifndef VIDEO_H_
#define VIDEO_H_

#include <SDL/SDL.h>

class Video {
private:
	bool fullscreen;

	SDL_Surface* screen;

	SDL_Surface* icon;

	void createWindow();
public:
	Video();
	virtual ~Video();

	void onInit();
	void onDispose();

	void onRender();

	void setFullscreen(bool fullscreen);

	void toggleFullscreen();

	SDL_Surface* getScreen();
};

#endif /* VIDEO_H_ */
