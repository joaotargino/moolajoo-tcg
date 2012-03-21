/*
 * MenuScreen.h
 *
 *  Created on: 30/01/2012
 *      Author: Arthur
 */

#ifndef MENUSCREEN_H_
#define MENUSCREEN_H_

#include "../../framework/screen/Screen.h"

#include "../../framework/audio/Music.h"
#include "../../framework/fileIO/FileIO.h"
#include "../../framework/screen/ScreenManager.h"
#include "../../framework/surface/Surface.h"
#include "../../framework/system/System.h"

#include "NewGameScreen.h"

class MenuScreen: public Screen {
private:
	Surface menu_newgame;

	Surface menu_exit;

	Surface menu_cursor;

	int cursorPosition;

	Music* theme;
public:
	MenuScreen();
	virtual ~MenuScreen();

	void onInit(Game game);
	void onDispose();

	void onLoop(float deltaTime);

	void onRender();
};

#endif /* MENUSCREEN_H_ */
