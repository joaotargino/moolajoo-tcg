/*
 * KeyEvent.h
 *
 *  Created on: 25/01/2012
 *      Author: Arthur
 */

#ifndef KEYEVENT_H_
#define KEYEVENT_H_

class KeyEvent {
public:
	enum {
		KEY_DOWN = 0,
		KEY_UP
	};

	int type;
	int keyCode;
	char keyChar;
};

#endif /* KEYEVENT_H_ */
