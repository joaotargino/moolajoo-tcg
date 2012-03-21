/*
 * Surface.cpp
 *
 *  Created on: 31/01/2012
 *      Author: Arthur
 */

#include "Surface.h"

Surface::Surface() {
}

Surface::~Surface() {
}

void Surface::onInit(Image image) {
	this->image = image;
}

void Surface::onDispose() {
	image.onDispose();
}

void Surface::onLoop(int deltaTime) {}

Image* Surface::getImage() {
	return &image;
}
