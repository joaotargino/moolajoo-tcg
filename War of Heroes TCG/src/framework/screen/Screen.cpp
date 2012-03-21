/*
 * Screen.cpp
 *
 *  Created on: 25/01/2012
 *      Author: Aranha
 */

#include "Screen.h"

Screen::Screen() {
}

Screen::~Screen() {
	// TODO Auto-generated destructor stub
}

void Screen::onInit(Game game) {
	this->game = game;
}

void Screen::onDispose() {}

void Screen::onLoop(float deltaTime) {}

void Screen::onRender() {}
