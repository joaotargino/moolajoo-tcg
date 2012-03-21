/*
 * FileIO.cpp
 *
 *  Created on: 26/01/2012
 *      Author: Arthur
 */

#include "FileIO.h"

FileIO::FileIO() {
	// TODO Auto-generated constructor stub

}

FileIO::~FileIO() {
	// TODO Auto-generated destructor stub
}

const char* FileIO::RESOURCES = "Resources";

const char* FileIO::AUDIO = "Audio";

const char* FileIO::GRAPHICS = "Graphics";

const char* FileIO::MUSIC = "Music";

const char* FileIO::SOUND = "Sound";

const char* FileIO::PICTURE = "Picture";

const char* FileIO::FONT = "Font";

const char* FileIO::XML = "Xml";

const char* FileIO::DELIMITER = "/";

const char* FileIO::getResourcesPath() {
	String path(RESOURCES);
	path.concat(String(DELIMITER));

	return path.toCharArray();
}

const char* FileIO::getAudioPath() {
	String path(getResourcesPath());
	path.concat(String(AUDIO));
	path.concat(String(DELIMITER));

	return path.toCharArray();
}

const char* FileIO::getGraphicsPath() {
	String path(getResourcesPath());
	path.concat(String(GRAPHICS));
	path.concat(String(DELIMITER));

	return path.toCharArray();
}

const char* FileIO::getMusicPath() {
	String path(getAudioPath());
	path.concat(String(MUSIC));
	path.concat(String(DELIMITER));

	return path.toCharArray();
}

const char* FileIO::getSoundPath() {
	String path(getAudioPath());
	path.concat(String(SOUND));
	path.concat(String(DELIMITER));

	return path.toCharArray();
}

const char* FileIO::getPicturePath() {
	String path(getGraphicsPath());
	path.concat(String(PICTURE));
	path.concat(String(DELIMITER));

	return path.toCharArray();
}

const char* FileIO::getFontPath() {
	String path(getResourcesPath());
	path.concat(String(FONT));
	path.concat(String(DELIMITER));

	return path.toCharArray();
}

const char* FileIO::getXmlPath() {
	String path(getResourcesPath());
	path.concat(String(XML));
	path.concat(String(DELIMITER));

	return path.toCharArray();
}

const char* FileIO::getMusic(const char* filename) {
	String path(getMusicPath());
	path.concat(String(filename));

	return path.toCharArray();
}

const char* FileIO::getSound(const char* filename) {
	String path(getSoundPath());
	path.concat(String(filename));

	return path.toCharArray();
}

const char* FileIO::getPicture(const char* filename) {
	String path(getPicturePath());
	path.concat(String(filename));

	return path.toCharArray();
}

const char* FileIO::getFont(const char* filename) {
	String path(getFontPath());
	path.concat(String(filename));

	return path.toCharArray();
}

const char* FileIO::getXml(const char* filename) {
	String path(getXmlPath());
	path.concat(String(filename));

	return path.toCharArray();
}
