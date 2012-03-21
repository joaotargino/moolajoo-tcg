/*
 * InputManager.cpp
 *
 *  Created on: 26/01/2012
 *      Author: Aranha
 */

#include "InputManager.h"

InputManager::InputManager() {
	keyboardHandler = NULL;
}

InputManager::~InputManager() {
	keyboardHandler = NULL;
}

void InputManager::setKeyboardHandler(KeyboardHandler* keyboardHandler) {
	this->keyboardHandler = keyboardHandler;
}

KeyboardHandler* InputManager::getKeyboardHandler() {
	return keyboardHandler;
}
