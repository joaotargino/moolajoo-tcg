/*
 * SurfaceFade.h
 *
 *  Created on: 30/01/2012
 *      Author: Arthur
 */

#ifndef SURFACEFADE_H_
#define SURFACEFADE_H_

#include "Image.h"

class SurfaceFade {
private:
	Image image;
public:
	SurfaceFade();
	virtual ~SurfaceFade();

	void setPos(int x, int y);
	void setAlpha(int alpha);

	void onInit(Image image);
	void onDispose();

	Image getImage();
};

#endif /* SURFACEFADE_H_ */
