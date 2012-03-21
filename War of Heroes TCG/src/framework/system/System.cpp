/*
 * System.cpp
 *
 *  Created on: 27/01/2012
 *      Author: Aranha
 */

#include "System.h"

System* System::instance;

System::System() {
	FONT_DEFAULT = "ARIAL.TTF";
	fontName = FONT_DEFAULT;
	font = NULL;
	showingFPS = false;
}

System::~System() {
	font = NULL;
}

System* System::getInstance() {
	if (instance == NULL)
		instance = new System();
	return instance;
}

void System::onInit(Graphic graphic, FPS* fps) {
	this->graphic = graphic;
	this->fps = fps;

	setFontSize(20);
	setFont(FONT_DEFAULT);

	setColor(255, 0, 0);
}

void System::onDispose() {
	if (font)
		TTF_CloseFont(font);
	font = NULL;
}

void System::setFontSize(int fontSize) {
	this->fontSize = fontSize;
	setFont(fontName);
}

int System::getFontSize() {
	return fontSize;
}

void System::setFont(const char* filename) {
	fontName = filename;
	font = TTF_OpenFont(FileIO::getFont(fontName), getFontSize());
}

TTF_Font* System::getFont() {
	return font;
}

void System::setColor(int r, int g, int b) {
	color.r = r;
	color.g = g;
	color.b = b;
}

SDL_Color System::getColor() {
	return color;
}

bool System::isShowingFPS() {
	return showingFPS;
}

void System::setShowFPS(bool showingFPS) {
	this->showingFPS = showingFPS;
}

void System::showFPS() {
	setColor(255, 0, 0);
	setFontSize(16);
	String fps("Current FPS: ");
	fps.concat(String(this->fps->getFPS()));
	if (isShowingFPS())
		graphic.drawText(fps.toCharArray(), 0, 0);
}
