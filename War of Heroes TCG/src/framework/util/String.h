/*
 * String.h
 *
 *  Created on: 26/01/2012
 *      Author: Aranha
 */

#ifndef STRING_H_
#define STRING_H_

#include <string>
#include <sstream>

class String {
private:
	std::string string;
public:
	String();
	String(char character);
	String(int number);
	String(double number);
	String(std::string string);
	virtual ~String();

	String concat(String string);
	String concat(const char* string);
	String concat(int i);

	bool isEmpty();

	std::string toString();

	const char* toCharArray();
};

#endif /* STRING_H_ */
