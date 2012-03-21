/*
 * SurfaceFadeIn.h
 *
 *  Created on: 31/01/2012
 *      Author: Arthur
 */

#ifndef SURFACEFADEIN_H_
#define SURFACEFADEIN_H_

#include "Surface.h"

#include "Image.h"

#include "../timer/Timer.h"

class SurfaceFadeIn : public Surface {
private:
	Timer timer;

	float alpha;
	int fadeStep;
	float inc;
public:
	SurfaceFadeIn();
	virtual ~SurfaceFadeIn();

	void onInit(Image image, float fadingInTime);

	void onLoop(int deltaTime);

	bool isFadingIn();
};

#endif /* SURFACEFADEIN_H_ */
