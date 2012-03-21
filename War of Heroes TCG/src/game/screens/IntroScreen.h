/*
 * IntroScreen.h
 *
 *  Created on: 26/01/2012
 *      Author: Aranha
 */

#ifndef INTROSCREEN_H_
#define INTROSCREEN_H_

#include "../../framework/screen/Screen.h"

#include "../../framework/fileIO/FileIO.h"
#include "../../framework/screen/ScreenManager.h"
#include "../../framework/surface/Image.h"
#include "../../framework/surface/Surface.h"
#include "../../framework/surface/SurfaceBlink.h"
#include "../../framework/surface/SurfaceFadeIn.h"
#include "../../framework/surface/SurfaceFadeOut.h"
#include "../../framework/system/System.h"
#include "../../framework/timer/Timer.h"

#include "../../game/screens/MenuScreen.h"

class IntroScreen: public Screen {
private:
//	Surface surface;
	Timer timer;

	SurfaceFadeIn fadeIn;

//	SurfaceFadeOut fadeOut;
public:
	IntroScreen();
	virtual ~IntroScreen();

	void onInit(Game game);
	void onDispose();

	void onLoop(float deltaTime);

	void onRender();
};

#endif /* INTROSCREEN_H_ */
