/*
 * HeroReader.h
 *
 *  Created on: 21/03/2012
 *      Author: andre
 */

#ifndef HEROREADER_H_
#define HEROREADER_H_

#include "../../framework/fileIO/xml/reader/XMLReader.h"
#include "../../framework/util/String.h"
#include "../../framework/util/Integer.h"

#include "../entities/Hero.h"

class HeroReader : public XMLReader<Hero> {
protected:
	Hero getClass(CMarkup xml);
public:
	HeroReader();
	virtual ~HeroReader();

	Hero findHeroById(int id);
};

#endif /* HEROREADER_H_ */
