/*
 * String.cpp
 *
 *  Created on: 26/01/2012
 *      Author: Aranha
 */

#include "String.h"

String::String() {
}

String::String(char character) {
	string = character;
}

String::String(double number) {
	std::stringstream stream;
	stream << number;

	string = stream.str();
}

String::String(int number) {
	std::stringstream stream;
	stream << number;

	string = stream.str();
}

String::String(std::string string) {
	this->string = string;
}

String::~String() {
	// TODO Auto-generated destructor stub
}

String String::concat(String string) {
	this->string += string.toString();
	return this->string;
}

String String::concat(const char* string) {
	return concat(String(string));
}

String String::concat(int i) {
	return concat(String(i));
}

bool String::isEmpty() {
	return string.empty();
}

std::string String::toString() {
	return string;
}

const char* String::toCharArray() {
	return string.data();
}
