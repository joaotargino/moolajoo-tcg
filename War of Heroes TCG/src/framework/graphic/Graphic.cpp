/*
 * Graphic.cpp
 *
 *  Created on: 25/01/2012
 *      Author: Aranha
 */

#include "Graphic.h"

#include "../system/System.h"

Graphic::Graphic() {
	surface = NULL;
}

Graphic::~Graphic() {
	surface = NULL;
}

void Graphic::onInit(SDL_Surface* surface) {
	this->surface = surface;
}

void Graphic::onDispose() {
	if (surface)
		SDL_FreeSurface(surface);
	surface = NULL;
}

Image Graphic::newImage(const char* filename) {
	Image image;

	SDL_Surface* surface_temp = NULL;
	surface_temp = IMG_Load(filename);

	image.onInit(SDL_DisplayFormatAlpha(surface_temp));

	if (surface_temp)
		SDL_FreeSurface(surface);
	surface_temp = NULL;

	return image;
}

Image Graphic::newImageFromText(const char* text) {
	Image image;

	SDL_Surface* surface_temp = NULL;

	surface_temp = TTF_RenderText_Blended(System::getInstance()->getFont(), text, System::getInstance()->getColor());

	image.onInit(SDL_DisplayFormatAlpha(surface_temp));

	if (surface_temp)
		SDL_FreeSurface(surface);
	surface_temp = NULL;

	return image;
}

void Graphic::clear(SDL_Color color) {
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, color.r, color.g, color.b));
}

void Graphic::clear() {
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, System::getInstance()->getColor().r, System::getInstance()->getColor().g, System::getInstance()->getColor().b));
}

void Graphic::drawImage(Image image, int x, int y, int srcX, int srcY, int srcWidth, int srcHeight) {
	SDL_Rect destR;
	destR.x = x;
	destR.y = y;

	SDL_Rect srcR;
	srcR.x = srcX;
	srcR.y = srcY;
	srcR.w = srcWidth;
	srcR.h = srcHeight;

	if (image.getSurface())
		SDL_BlitSurface(image.getSurface(), &srcR, surface, &destR);
}

void Graphic::drawImage(Image image, int x, int y) {
	drawImage(image, x, y, 0, 0, image.width, image.height);
}

bool Graphic::transparent(SDL_Surface* surface_dest, int r, int g, int b) {
	if (surface_dest == NULL)
		return false;

	SDL_SetColorKey(surface_dest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(surface_dest->format, r, g, b));
	return true;
}

bool Graphic::onDraw(SDL_Surface* surface_dest, SDL_Surface* surface_src, int x, int y) {
	if (surface_dest == NULL || surface_src == NULL)
		return false;

	SDL_Rect destR;
	destR.x = x;
	destR.y = y;

	SDL_Rect srcR;
	srcR.x = 0;
	srcR.y = 0;
	srcR.w = surface_src->w;
	srcR.h = surface_src->h;

	SDL_BlitSurface(surface_src, &srcR, surface_dest, &destR);

	return true;
}

void Graphic::drawImageWithAlpha(Image image) {
	SDL_Surface* tempScreen = NULL;

	if ((tempScreen = SDL_CreateRGBSurface(SDL_HWSURFACE | SDL_SRCALPHA | SDL_DOUBLEBUF, image.getSurface()->w, image.getSurface()->h, 32, 0, 0, 0, 0)) == NULL)
		return;

	if (SDL_SetAlpha(tempScreen, SDL_SRCALPHA, image.alpha) < 0) {
		SDL_FreeSurface(tempScreen);
		tempScreen = NULL;
		return;
	}

	if (!transparent(tempScreen, 0, 0, 0)) {
		SDL_FreeSurface(tempScreen);
		tempScreen = NULL;
		return;
	}

	SDL_Rect destR;
	destR.x = image.x;
	destR.y = image.y;

	SDL_Rect srcR;
	srcR.x = 0;
	srcR.y = 0;
	srcR.w = image.width;
	srcR.h = image.height;

	SDL_BlitSurface(image.getSurface(), &srcR, tempScreen, &destR);

	if (!onDraw(surface, tempScreen, image.x, image.y)) {
		SDL_FreeSurface(tempScreen);
		tempScreen = NULL;
		return;
	}

	SDL_FreeSurface(tempScreen);
	tempScreen = NULL;
}

void Graphic::drawImage(Image image) {
//	printf("Graphic::drawImage - image.alpha: %d\n", image.alpha);
	if (image.alpha < 255)
		drawImageWithAlpha(image);
	else {
		SDL_Rect destR;
		destR.x = image.x;
		destR.y = image.y;

		if (image.getSurface())
			SDL_BlitSurface(image.getSurface(), NULL, surface, &destR);
	}
}

void Graphic::drawText(const char* text, int x, int y) {
	Image image;
	image.onInit(TTF_RenderText_Blended(System::getInstance()->getFont(), text, System::getInstance()->getColor()));

	drawImage(image, x, y);
}

int Graphic::getWidth() {
	return (surface == NULL) ? 0 : surface->w;
}

int Graphic::getHeight() {
	return (surface == NULL) ? 0 : surface->h;
}
