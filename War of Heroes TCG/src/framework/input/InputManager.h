/*
 * InputManager.h
 *
 *  Created on: 26/01/2012
 *      Author: Aranha
 */

#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#include "KeyboardHandler.h"

class InputManager {
private:
	KeyboardHandler* keyboardHandler;
public:
	InputManager();
	virtual ~InputManager();

	void setKeyboardHandler(KeyboardHandler* keyboardHandler);

	KeyboardHandler* getKeyboardHandler();
};

#endif /* INPUTMANAGER_H_ */
