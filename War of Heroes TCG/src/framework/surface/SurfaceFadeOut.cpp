/*
 * SurfaceFadeOut.cpp
 *
 *  Created on: 31/01/2012
 *      Author: Aranha
 */

#include "SurfaceFadeOut.h"

SurfaceFadeOut::SurfaceFadeOut() {
	// TODO Auto-generated constructor stub

}

SurfaceFadeOut::~SurfaceFadeOut() {
	// TODO Auto-generated destructor stub
}

void SurfaceFadeOut::onInit(Image image, float fadingOutTime) {
	Surface::onInit(image);
	fadeStep = 100;

	timer.setTick(fadingOutTime / fadeStep);
//	image.alpha = 255;
	alpha = image.alpha;
	dec = alpha / fadeStep;

	printf("SurfaceFadeOut::onInit - alpha, image.alpha: %G, %d, %o\n", alpha, image.alpha, SDL_GetTicks());
}

void SurfaceFadeOut::onLoop(int deltaTime) {
	if (timer.isTimetoAct(deltaTime) && image.alpha > 0) {
		alpha -= dec;
		image.alpha = alpha;
	}
}

bool SurfaceFadeOut::isFadingOut() {
//	if (image.alpha > 0) {
//		printf("Is Fading Out: %o\n", SDL_GetTicks());
//	} else {
//		printf("Is NOT Fading Out: %o, %d, %G\n", SDL_GetTicks(), image.alpha, alpha);
//	}
	return image.alpha > 0;
}
