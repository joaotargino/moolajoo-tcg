/*
 * ScreenGame.h
 *
 *  Created on: 25/01/2012
 *      Author: Aranha
 */

#ifndef SCREENGAME_H_
#define SCREENGAME_H_

#include "../../framework/graphic/Graphic.h"
#include "../../framework/screen/Screen.h"
#include "../../framework/surface/Image.h"

class ScreenGame : public Screen {
private:
	Image image;
public:
	ScreenGame();
	virtual ~ScreenGame();

	void onInit(Game game);
	void onDispose();

	void onLoop(float deltaTime);

	void onRender();
};

#endif /* SCREENGAME_H_ */
