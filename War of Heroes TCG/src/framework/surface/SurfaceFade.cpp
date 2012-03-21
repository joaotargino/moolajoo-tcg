/*
 * SurfaceFade.cpp
 *
 *  Created on: 30/01/2012
 *      Author: Arthur
 */

#include "SurfaceFade.h"

SurfaceFade::SurfaceFade() {
	// TODO Auto-generated constructor stub
}

SurfaceFade::~SurfaceFade() {
//	if (image)
		image.onDispose();
}

void SurfaceFade::setPos(int x, int y) {
	image.x = x;
	image.y = y;
}

void SurfaceFade::setAlpha(int alpha) {
	image.alpha = alpha;
}

void SurfaceFade::onInit(Image image) {
	this->image = image;
}

void SurfaceFade::onDispose() {
	image.onDispose();
}

Image SurfaceFade::getImage() {
	return image;
}
