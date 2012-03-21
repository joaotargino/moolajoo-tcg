/*
 * SurfaceFadeOut.h
 *
 *  Created on: 31/01/2012
 *      Author: Aranha
 */

#ifndef SURFACEFADEOUT_H_
#define SURFACEFADEOUT_H_

#include "Surface.h"

#include "Image.h"

#include "../timer/Timer.h"

class SurfaceFadeOut : public Surface {
private:
	Timer timer;

	float alpha;
	int fadeStep;
	float dec;
public:
	SurfaceFadeOut();
	virtual ~SurfaceFadeOut();

	void onInit(Image image, float fadingOutTime);

	void onLoop(int deltaTime);

	bool isFadingOut();
};

#endif /* SURFACEFADEOUT_H_ */
