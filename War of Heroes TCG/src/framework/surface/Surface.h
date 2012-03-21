/*
 * Surface.h
 *
 *  Created on: 31/01/2012
 *      Author: Arthur
 */

#ifndef SURFACE_H_
#define SURFACE_H_

#include "Image.h"

class Surface {
protected:
	Image image;
public:
	Surface();
	virtual ~Surface();

	void onInit(Image image);

	void onDispose();

	void onLoop(int deltaTime);

	Image* getImage();
};

#endif /* SURFACE_H_ */
