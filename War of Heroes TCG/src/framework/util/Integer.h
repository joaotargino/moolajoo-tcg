/*
 * Integer.h
 *
 *  Created on: 21/03/2012
 *      Author: andre
 */

#ifndef INTEGER_H_
#define INTEGER_H_

#include <string>
#include <stdlib.h>

class Integer {
private:
	int i;
public:
	Integer();
	Integer(int i);
	Integer(std::string str);
	virtual ~Integer();

	int toInt();
};

#endif /* INTEGER_H_ */
