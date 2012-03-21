/*
 * Timer.h
 *
 *  Created on: 27/01/2012
 *      Author: Aranha
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <SDL/SDL.h>

class Timer {
private:
	int ONE_SECOND;

	long tickTime;

	float tick;
public:
	Timer();
	virtual ~Timer();

	bool isTimetoAct(int deltaTime);

	float getTick();

	void setTick(float tick);
};

#endif /* TIMER_H_ */
