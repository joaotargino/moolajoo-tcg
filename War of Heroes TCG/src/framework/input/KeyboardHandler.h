/*
 * KeyboardHandler.h
 *
 *  Created on: 24/01/2012
 *      Author: Arthur
 */

#ifndef KEYBOARDHANDLER_H_
#define KEYBOARDHANDLER_H_

#include "Event.h"

#include <vector>

#include "KeyEvent.h"

class KeyboardHandler : public Event {
private:
	const static int KEYS_LENGTH = SDLK_LAST;

	std::vector<KeyEvent> keyEventsBuffer;

	void setAllFalse();
public:
	KeyboardHandler();
	virtual ~KeyboardHandler();

	bool pressedKeys[KEYS_LENGTH];


	void onEvent(SDL_Event* event);

	void onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

	void onKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);

	bool isKeyPressed(int keyCode);

	std::vector<KeyEvent> getKeyEvents();
};

#endif /* KEYBOARDHANDLER_H_ */
