/*
 * Input.cpp
 *
 *  Created on: 24/01/2012
 *      Author: Aranha
 */

#include "Input.h"

Input::Input() {
	keyboardHandler = NULL;
}

Input::~Input() {
	keyboardHandler = NULL;
}

void Input::onInit(InputManager* inputManager) {
	keyboardHandler = new KeyboardHandler();
	inputManager->setKeyboardHandler(keyboardHandler);
}

void Input::onDispose() {
	keyboardHandler = NULL;
}

bool Input::isKeyPressed(int keyCode) {
	return keyboardHandler->isKeyPressed(keyCode);
}

std::vector<KeyEvent> Input::getKeyEvents() {
	return keyboardHandler->getKeyEvents();
}
