/*
 * HeroReader.cpp
 *
 *  Created on: 21/03/2012
 *      Author: andre
 */

#include "HeroReader.h"

HeroReader::HeroReader() {
	// TODO Auto-generated constructor stub

}

HeroReader::~HeroReader() {
	// TODO Auto-generated destructor stub
}

Hero HeroReader::getClass(CMarkup xml) {
	Hero h;

	int id = Integer(xml.GetAttrib("id")).toInt();
	h.setId(id);

	xml.IntoElem();
	xml.FindElem("name");

	h.setName(String(xml.GetData()).toCharArray());

	xml.OutOfElem();

	return h;
}

Hero HeroReader::findHeroById(int id) {
	return Hero();
}
