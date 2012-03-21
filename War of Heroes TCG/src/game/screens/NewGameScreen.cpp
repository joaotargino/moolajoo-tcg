/*
 * NewGameScreen.cpp
 *
 *  Created on: 01/02/2012
 *      Author: Arthur
 */

#include "NewGameScreen.h"

NewGameScreen::NewGameScreen() {
	theme = NULL;
}

NewGameScreen::~NewGameScreen() {
	theme = NULL;
}

void NewGameScreen::onInit(Game game) {
	Screen::onInit(game);

	System::getInstance()->setFontSize(22);
	System::getInstance()->setColor(0, 0, 0);

	label_insertNames.onInit(game.getGraphic().newImageFromText("INSERT PLAYERS NAMES"));
	label_insertNames.getImage()->x = (game.getGraphic().getWidth() - label_insertNames.getImage()->width) / 2;
	label_insertNames.getImage()->y = 80;

	label_nameOne.onInit(game.getGraphic().newImageFromText("PLAYER 1:"));
	label_nameOne.getImage()->x = (game.getGraphic().getWidth() - label_nameOne.getImage()->width) / 2 - 100;
	label_nameOne.getImage()->y = 160;

	label_nameTwo.onInit(game.getGraphic().newImageFromText("PLAYER 2:"));
	label_nameTwo.getImage()->x = (game.getGraphic().getWidth() - label_nameTwo.getImage()->width) / 2 - 100;
	label_nameTwo.getImage()->y = label_nameOne.getImage()->y + 60;

	label_Continue.onInit(game.getGraphic().newImageFromText("CONTINUE"));
	label_Continue.getImage()->x = game.getGraphic().getWidth() - label_Continue.getImage()->width - 100;
	label_Continue.getImage()->y = game.getGraphic().getHeight() - label_Continue.getImage()->height - 100;

	label_Back.onInit(game.getGraphic().newImageFromText("BACK"));
	label_Back.getImage()->x = 100;
	label_Back.getImage()->y = game.getGraphic().getHeight() - label_Back.getImage()->height - 100;

	System::getInstance()->setFontSize(16);
	System::getInstance()->setColor(255, 0, 0);
	label_PressEnter.onInit(game.getGraphic().newImageFromText("PRESS [ENTER] TO CONTINUE"), 500);
	label_PressEnter.getImage()->x = (game.getGraphic().getWidth() - label_PressEnter.getImage()->width) / 2;
	label_PressEnter.getImage()->y = (game.getGraphic().getHeight() - label_PressEnter.getImage()->height) - 20;

	menu_cursor.onInit(game.getGraphic().newImage(FileIO::getPicture("cursor.png")));

	menu_cursor.getImage()->x = label_nameOne.getImage()->x - menu_cursor.getImage()->width;
	menu_cursor.getImage()->y = label_nameOne.getImage()->y + cursorPosition * label_nameOne.getImage()->height;

	cursorPosition = 0;
}

void NewGameScreen::onDispose() {
	label_insertNames.onDispose();
	label_nameOne.onDispose();
	label_nameTwo.onDispose();
	label_Back.onDispose();
	label_Continue.onDispose();
	label_PressEnter.onDispose();

	if (theme) {
		theme->stop();
		theme->dispose();
	}
}

void NewGameScreen::onLoop(float deltaTime) {
	label_PressEnter.onLoop(deltaTime);
}

void NewGameScreen::onRender() {
	System::getInstance()->setColor(255, 255, 255);
	game.getGraphic().clear();

	game.getGraphic().drawImage(*label_insertNames.getImage());
	game.getGraphic().drawImage(*label_nameOne.getImage());
	game.getGraphic().drawImage(*label_nameTwo.getImage());
	game.getGraphic().drawImage(*label_Continue.getImage());
	game.getGraphic().drawImage(*label_Back.getImage());
	game.getGraphic().drawImage(*label_PressEnter.getImage());
	game.getGraphic().drawImage(*menu_cursor.getImage());
}
