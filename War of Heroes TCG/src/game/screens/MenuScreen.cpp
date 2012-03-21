/*
 * MenuScreen.cpp
 *
 *  Created on: 30/01/2012
 *      Author: Arthur
 */

#include "MenuScreen.h"

MenuScreen::MenuScreen() {
	theme = NULL;
}

MenuScreen::~MenuScreen() {
	theme = NULL;
}

void MenuScreen::onInit(Game game) {
	Screen::onInit(game);

	System::getInstance()->setFontSize(32);
	System::getInstance()->setColor(0, 0, 0);

	menu_newgame.onInit(game.getGraphic().newImageFromText("NEW GAME"));

	menu_exit.onInit(game.getGraphic().newImageFromText("EXIT"));

	menu_cursor.onInit(game.getGraphic().newImage(FileIO::getPicture("cursor.png")));

	cursorPosition = 0;

	menu_newgame.getImage()->x = (game.getGraphic().getWidth() - menu_newgame.getImage()->width) / 2;
	menu_newgame.getImage()->y = (game.getGraphic().getHeight() - menu_newgame.getImage()->height - menu_exit.getImage()->height) / 2;

	menu_exit.getImage()->x = (game.getGraphic().getWidth() - menu_exit.getImage()->width) / 2;
	menu_exit.getImage()->y = menu_newgame.getImage()->y + menu_newgame.getImage()->height;

	menu_cursor.getImage()->x = menu_newgame.getImage()->x - menu_cursor.getImage()->width;
	menu_cursor.getImage()->y = menu_newgame.getImage()->y + cursorPosition * menu_newgame.getImage()->height;

	theme = new Music("Theme5.ogg");
//	theme = game.getAudio().newMusic("Theme5.ogg");
	theme->play();
//	game.getAudio().newMusic("Theme5.ogg").play();
}

void MenuScreen::onDispose() {
	menu_newgame.onDispose();
	menu_exit.onDispose();
	menu_cursor.onDispose();
	theme->stop();
	theme->dispose();
}

void MenuScreen::onLoop(float deltaTime) {
	menu_cursor.getImage()->y = menu_newgame.getImage()->y + cursorPosition * menu_newgame.getImage()->height;
	std::vector<KeyEvent> keyEvents = game.getInput().getKeyEvents();
	for (unsigned int i = 0; i < keyEvents.size(); i++) {
		if (keyEvents[i].type == KeyEvent::KEY_UP && keyEvents[i].keyCode == SDLK_RETURN) {
			game.getAudio().newSound("Decision2.ogg").play();
			if (cursorPosition == 0)
				ScreenManager::getInstance()->setCurrentScreen(new NewGameScreen());
			else if (cursorPosition == 1)
				ScreenManager::getInstance()->onExit();
		}
		if (keyEvents[i].type == KeyEvent::KEY_UP && keyEvents[i].keyCode == SDLK_UP) {
			if (--cursorPosition < 0) {
				game.getAudio().newSound("Cancel1.ogg").play();
				cursorPosition = 0;
			} else
				game.getAudio().newSound("Cursor1.ogg").play();
		}
		if (keyEvents[i].type == KeyEvent::KEY_UP && keyEvents[i].keyCode == SDLK_DOWN) {
			if (++cursorPosition > 1) {
				game.getAudio().newSound("Cancel1.ogg").play();
				cursorPosition = 1;
			} else
				game.getAudio().newSound("Cursor1.ogg").play();
		}
	}
}

void MenuScreen::onRender() {
	System::getInstance()->setColor(255, 255, 255);
	game.getGraphic().clear();
	System::getInstance()->setColor(0, 0, 0);
	game.getGraphic().drawImage(*menu_newgame.getImage());
	game.getGraphic().drawImage(*menu_exit.getImage());
	game.getGraphic().drawImage(*menu_cursor.getImage());
}
