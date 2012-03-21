/*
 * SurfaceBlink.h
 *
 *  Created on: 31/01/2012
 *      Author: Aranha
 */

#ifndef SURFACEBLINK_H_
#define SURFACEBLINK_H_

#include "Surface.h"

#include "Image.h"

#include "../timer/Timer.h"

class SurfaceBlink : public Surface {
private:
	Timer timer;
public:
	SurfaceBlink();
	virtual ~SurfaceBlink();

	void onInit(Image image, int blinkTime);

	void onLoop(int deltaTime);
};

#endif /* SURFACEBLINK_H_ */
