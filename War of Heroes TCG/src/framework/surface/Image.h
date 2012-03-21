/*
 * Image.h
 *
 *  Created on: 25/01/2012
 *      Author: Aranha
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#include <SDL/SDL.h>

class Image {
private:
	SDL_Surface* image_surface;
public:
	Image();
	virtual ~Image();

	int x;
	int y;
	int width;
	int height;

	int alpha;

	void onInit(SDL_Surface* surface);
	void onDispose();

	SDL_Surface* getSurface();
};

#endif /* IMAGE_H_ */
