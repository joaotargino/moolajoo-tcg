/*
 * Hero.h
 *
 *  Created on: 21/03/2012
 *      Author: andre
 */

#ifndef HERO_H_
#define HERO_H_

#include "../../framework/util/String.h"

class Hero {
private:
	int id;
	int classId;

	int hp;
	int mp;

	String name;
public:
	Hero();
	virtual ~Hero();

	int getId();
	void setId(int id);

	int getClassId();
	void setClassId(int classId);

	int getHp();
	void setHp(int hp);

	int getMp();
	void setMp(int mp);

	const char* getName();
	void setName(const char* name);

	const char* toString();
};

#endif /* HERO_H_ */
