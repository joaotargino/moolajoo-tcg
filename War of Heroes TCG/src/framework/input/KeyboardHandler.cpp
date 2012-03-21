/*
 * KeyboardHandler.cpp
 *
 *  Created on: 24/01/2012
 *      Author: Arthur
 */

#include "KeyboardHandler.h"

KeyboardHandler::KeyboardHandler() {
	setAllFalse();

	keyEventsBuffer.clear();
}

KeyboardHandler::~KeyboardHandler() {

}

void KeyboardHandler::onEvent(SDL_Event* event) {
	Event::onEvent(event);
}

void KeyboardHandler::onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
	KeyEvent keyEvent;
	keyEvent.keyCode = sym;
	keyEvent.keyChar = (char) sym;
	keyEvent.type = KeyEvent::KEY_DOWN;
	pressedKeys[sym] = true;
	keyEventsBuffer.push_back(keyEvent);
}

void KeyboardHandler::onKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
	KeyEvent keyEvent;
	keyEvent.keyCode = sym;
	keyEvent.keyChar = (char) sym;
	keyEvent.type = KeyEvent::KEY_UP;
	pressedKeys[sym] = false;
	keyEventsBuffer.push_back(keyEvent);
}

bool KeyboardHandler::isKeyPressed(int keyCode) {
	if (keyCode < 0 || keyCode >= KEYS_LENGTH)
		return false;
	return pressedKeys[keyCode];
}

std::vector<KeyEvent> KeyboardHandler::getKeyEvents() {
	std::vector<KeyEvent> keyEvents;
	keyEvents.clear();

	for (unsigned int i = 0; i < keyEventsBuffer.size(); i++)
		keyEvents.push_back(keyEventsBuffer[i]);

	keyEventsBuffer.clear();

	return keyEvents;
}

void KeyboardHandler::setAllFalse() {
	for (int i = 0; i < KEYS_LENGTH; i++)
		pressedKeys[i] = false;
}
