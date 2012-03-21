/*
 * XMLReader.h
 *
 *  Created on: 20/03/2012
 *      Author: andre
 */

#ifndef XMLREADER_H_
#define XMLREADER_H_

#include <vector>

#include "../../FileIO.h"
#include "../Markup/Markup.h"

#include <iostream>
#include <stdio.h>

template <typename T> class XMLReader {
protected:
	virtual T getClass(CMarkup xml) = 0;
public:
	XMLReader() { }

	virtual ~XMLReader() {}

	std::vector<T> findClasses(const char* filename) {
		std::vector<T> classes;
		classes.clear();

		CMarkup xml;
		xml.Load(FileIO::getXml(filename));

		xml.FindElem();
		xml.IntoElem();

		while (xml.FindElem())
			classes.push_back(getClass(xml));

		return classes;
	}
};

#endif /* XMLREADER_H_ */
