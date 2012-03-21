/*
 * Timer.cpp
 *
 *  Created on: 27/01/2012
 *      Author: Aranha
 */

#include "Timer.h"

Timer::Timer() {
	ONE_SECOND = 1000;

	tickTime = 0;
	tick = 1000;
}

Timer::~Timer() {
	// TODO Auto-generated destructor stub
}

bool Timer::isTimetoAct(int deltaTime) {
	tickTime += deltaTime;

	if (tickTime > tick) {
		tickTime -= tick;

		return true;
	}
	return false;
}

float Timer::getTick() {
	return tick;
}

void Timer::setTick(float tick) {
	this->tick = tick;
}
