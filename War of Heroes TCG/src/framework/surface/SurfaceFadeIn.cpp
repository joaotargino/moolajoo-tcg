/*
 * SurfaceFadeIn.cpp
 *
 *  Created on: 31/01/2012
 *      Author: Arthur
 */

#include "SurfaceFadeIn.h"

SurfaceFadeIn::SurfaceFadeIn() {
	// TODO Auto-generated constructor stub

}

SurfaceFadeIn::~SurfaceFadeIn() {
	// TODO Auto-generated destructor stub
}

void SurfaceFadeIn::onInit(Image image, float fadingInTime) {
	Surface::onInit(image);
	fadeStep = 100;

	timer.setTick(fadingInTime / fadeStep);
	this->image.alpha = 0;
	alpha = this->image.alpha;
	inc = (255 - alpha) / fadeStep;
//	printf("SurfaceFadeIn::onInit - alpha, image.alpha: %G, %d, %o, %G\n", alpha, this->image.alpha, SDL_GetTicks(), inc);
}

void SurfaceFadeIn::onLoop(int deltaTime) {
//	printf("Time: %o\n", SDL_GetTicks());
//	printf("SurfaceFadeIn::onInit - alpha, image.alpha: %G, %d\n", alpha, image.alpha);
	if (timer.isTimetoAct(deltaTime) && image.alpha < 255) {
		alpha += inc;
		image.alpha = alpha;
	}
}

bool SurfaceFadeIn::isFadingIn() {
	return image.alpha < 255;
}
