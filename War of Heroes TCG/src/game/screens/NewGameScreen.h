/*
 * NewGameScreen.h
 *
 *  Created on: 01/02/2012
 *      Author: Arthur
 */

#ifndef NEWGAMESCREEN_H_
#define NEWGAMESCREEN_H_

#include "../../framework/screen/Screen.h"

#include "../../framework/audio/Music.h"
#include "../../framework/fileIO/FileIO.h"
#include "../../framework/screen/ScreenManager.h"
#include "../../framework/surface/Surface.h"
#include "../../framework/surface/SurfaceBlink.h"
#include "../../framework/system/System.h"

class NewGameScreen: public Screen {
private:
	Surface label_insertNames;

	Surface label_nameOne;

	Surface label_nameTwo;

	Surface label_Continue;

	Surface label_Back;

	SurfaceBlink label_PressEnter;

	Surface menu_cursor;

	int cursorPosition;

	Music* theme;
public:
	NewGameScreen();
	virtual ~NewGameScreen();

	void onInit(Game game);
	void onDispose();

	void onLoop(float deltaTime);

	void onRender();
};

#endif /* NEWGAMESCREEN_H_ */
