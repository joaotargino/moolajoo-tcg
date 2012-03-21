/*
 * IntroScreen.cpp
 *
 *  Created on: 26/01/2012
 *      Author: Aranha
 */

#include "IntroScreen.h"

IntroScreen::IntroScreen() {
	// TODO Auto-generated constructor stub

}

IntroScreen::~IntroScreen() {
	// TODO Auto-generated destructor stub
}

void IntroScreen::onInit(Game game) {
	Screen::onInit(game);
//	Image Image = game.getGraphic().newImage(FileIO::getPicture("splash.png"));

//	surface.onInit(Image);

//	fadeOut.onInit(Image, 1500);
	fadeIn.onInit(game.getGraphic().newImage(FileIO::getPicture("splash.png")), 2000);

	timer.setTick(3000);

//	Image.onDispose();

//	sur.onInit(game.getGraphic().newImage(FileIO::getPicture("splash.png")));
//	sur.onInit(surface);
//	surface = game.getGraphic().newImage(FileIO::getPicture("splash.png"));
//	textBlink.onInit(surface, 500);
//	System::getInstance()->setFontSize(12);
//	textSurface = game.getGraphic().newImageFromText("Press [ENTER] to skip.");
//	textSurface.x = game.getGraphic().getWidth() - textSurface.width;
//	textSurface.y = game.getGraphic().getHeight() - textSurface.height;
//	textBlink.onInit(textSurface, 500);
//
//	surface.alpha = 0;
//
//	fadeOut.onInit(surface, 3000);
//	fadeIn.onInit(surface, 3000);
//
}

void IntroScreen::onDispose() {
//	surface.onDispose();
	fadeIn.onDispose();
//	fadeOut.onDispose();
}

void IntroScreen::onLoop(float deltaTime) {
	fadeIn.onLoop(deltaTime);
//	if (!fadeIn.isFadingIn())
//		fadeOut.onLoop(deltaTime);

	std::vector<KeyEvent> keyEvents = game.getInput().getKeyEvents();
	for (unsigned int i = 0; i < keyEvents.size(); i++)
		if (keyEvents[i].type == KeyEvent::KEY_UP && keyEvents[i].keyCode == SDLK_RETURN)
			ScreenManager::getInstance()->setCurrentScreen(new MenuScreen());

	if (timer.isTimetoAct(deltaTime))
		ScreenManager::getInstance()->setCurrentScreen(new MenuScreen());
}

void IntroScreen::onRender() {
//	if (fadeIn.isFadingIn())
		game.getGraphic().drawImage(*fadeIn.getImage());
//	else if (fadeOut.isFadingOut())
//		game.getGraphic().drawImage(fadeOut.getImage());
//	else
//		game.getGraphic().drawImage(surface.getImage());
}
