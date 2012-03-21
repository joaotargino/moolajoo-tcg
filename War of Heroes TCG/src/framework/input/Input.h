/*
 * Input.h
 *
 *  Created on: 24/01/2012
 *      Author: Aranha
 */

#ifndef INPUT_H_
#define INPUT_H_

#include "InputManager.h"
#include "KeyboardHandler.h"

class Input {
private:
	KeyboardHandler* keyboardHandler;
public:
	Input();
	virtual ~Input();

	void onInit(InputManager* inputManager);
	void onDispose();

	bool isKeyPressed(int keyCode);

	std::vector<KeyEvent> getKeyEvents();
};

#endif /* INPUT_H_ */
