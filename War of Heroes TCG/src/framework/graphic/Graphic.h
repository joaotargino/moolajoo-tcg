/*
 * Graphic.h
 *
 *  Created on: 25/01/2012
 *      Author: Aranha
 */

#ifndef GRAPHIC_H_
#define GRAPHIC_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "../surface/Image.h"

class Graphic {
private:
	SDL_Surface* surface;

	void drawImageWithAlpha(Image image);

	bool onDraw(SDL_Surface* surface_dest, SDL_Surface* surface_src, int x, int y);

	bool transparent(SDL_Surface* surface_dest, int r, int g, int b);
public:
	Graphic();
	virtual ~Graphic();

	void onInit(SDL_Surface* surface);
	void onDispose();

	Image newImage(const char* filename);

	Image newImageFromText(const char* text);

	void clear(SDL_Color color);

	void clear();

	void drawImage(Image image, int x, int y, int srcX, int srcY, int srcWidth, int srcHeight);

	void drawImage(Image image, int x, int y);

	void drawImage(Image image);

	void drawText(const char* text, int x, int y);

	int getWidth();

	int getHeight();
};

#endif /* GRAPHIC_H_ */
