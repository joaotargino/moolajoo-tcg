/*
 * Integer.cpp
 *
 *  Created on: 21/03/2012
 *      Author: andre
 */

#include "Integer.h"

Integer::Integer() {
	i = 0;
}

Integer::Integer(int i) {
	this->i = i;
}

Integer::Integer(std::string str) {
	i = atoi(str.data());
}

Integer::~Integer() {
	// TODO Auto-generated destructor stub
}

int Integer::toInt() {
	return i;
}
