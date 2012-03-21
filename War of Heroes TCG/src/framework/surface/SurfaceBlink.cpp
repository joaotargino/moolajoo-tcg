/*
 * SurfaceBlink.cpp
 *
 *  Created on: 31/01/2012
 *      Author: Aranha
 */

#include "SurfaceBlink.h"

SurfaceBlink::SurfaceBlink() {
	// TODO Auto-generated constructor stub

}

SurfaceBlink::~SurfaceBlink() {
	// TODO Auto-generated destructor stub
}

void SurfaceBlink::onInit(Image image, int blinkTime) {
	Surface::onInit(image);
	timer.setTick(blinkTime);
}

void SurfaceBlink::onLoop(int deltaTime) {
	if (timer.isTimetoAct(deltaTime))
		image.alpha = 255 - image.alpha;
}
