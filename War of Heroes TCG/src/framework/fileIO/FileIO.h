/*
 * FileIO.h
 *
 *  Created on: 26/01/2012
 *      Author: Arthur
 */

#ifndef FILEIO_H_
#define FILEIO_H_

#include "../util/String.h"

class FileIO {
private:
	static const char* RESOURCES;

	static const char* AUDIO;

	static const char* GRAPHICS;

	static const char* MUSIC;

	static const char* SOUND;

	static const char* PICTURE;

	static const char* FONT;

	static const char* XML;

	static const char* getResourcesPath();

	static const char* getAudioPath();

	static const char* getGraphicsPath();

	static const char* getMusicPath();

	static const char* getSoundPath();

	static const char* getPicturePath();

	static const char* getFontPath();

	static const char* getXmlPath();
public:
	FileIO();
	virtual ~FileIO();

	static const char* DELIMITER;

	static const char* getMusic(const char* filename);

	static const char* getSound(const char* filename);

	static const char* getPicture(const char* filename);

	static const char* getFont(const char* filename);

	static const char* getXml(const char* filename);
};

#endif /* FILEIO_H_ */
