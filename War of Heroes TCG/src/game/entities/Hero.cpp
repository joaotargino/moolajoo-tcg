/*
 * Hero.cpp
 *
 *  Created on: 21/03/2012
 *      Author: andre
 */

#include "Hero.h"

Hero::Hero() {
	// TODO Auto-generated constructor stub
}

Hero::~Hero() {
	// TODO Auto-generated destructor stub
}

int Hero::getId() {
	return id;
}
void Hero::setId(int id) {
	this->id = id;
}

int Hero::getClassId() {
	return classId;
}
void Hero::setClassId(int classId) {
	this->classId = classId;
}

int Hero::getHp() {
	return hp;
}

void Hero::setHp(int hp) {
	this->hp = hp;
}

int Hero::getMp() {
	return mp;
}

void Hero::setMp(int mp) {
	this->mp = mp;
}

const char* Hero::getName() {
	return name.toCharArray();
}

void Hero::setName(const char* name) {
	this->name = String(name);
}

const char* Hero::toString() {
	return String("ID: ").concat(getId()).concat(", Name: ").concat(getName()).toCharArray();
}
