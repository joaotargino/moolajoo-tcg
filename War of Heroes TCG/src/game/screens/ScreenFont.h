/*
 * ScreenFont.h
 *
 *  Created on: 25/01/2012
 *      Author: Arthur
 */

#ifndef SCREENFONT_H_
#define SCREENFONT_H_

#include "../../framework/screen/Screen.h"

#include <vector>

#include "../../framework/fileIO/FileIO.h"
#include "../../framework/system/System.h"
#include "../../framework/util/String.h"

class ScreenFont : public Screen {
private:
	int x, y, time;

	String string;
	int timer;
public:
	ScreenFont();
	virtual ~ScreenFont();

	void onInit(Game game);
	void onDispose();

	void onLoop(float deltaTime);

	void onRender();
};

#endif /* SCREENFONT_H_ */
