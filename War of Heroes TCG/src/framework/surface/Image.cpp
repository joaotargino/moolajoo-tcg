/*
 * Image.cpp
 *
 *  Created on: 25/01/2012
 *      Author: Aranha
 */

#include "Image.h"

Image::Image() {
	image_surface = NULL;
	x = y = width = height = 0;
	alpha = 255;
}

Image::~Image() {
	image_surface = NULL;
}

void Image::onInit(SDL_Surface* surface) {
	if (surface == NULL)
		return;
	image_surface = surface;
	width = image_surface->w;
	height = image_surface->h;
}

void Image::onDispose() {
	if (image_surface)
		SDL_FreeSurface(image_surface);
	image_surface = NULL;
}

SDL_Surface* Image::getSurface() {
	return image_surface;
}
