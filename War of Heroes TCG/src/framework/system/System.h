/*
 * System.h
 *
 *  Created on: 27/01/2012
 *      Author: Aranha
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <SDL/SDL_ttf.h>

#include "../fileIO/FileIO.h"
#include "../graphic/Graphic.h"
#include "../timer/FPS.h"
#include "../util/String.h"

class System {
private:
	static System* instance;

	const char* FONT_DEFAULT;

	const char* fontName;

	int fontSize;

	bool showingFPS;

	TTF_Font* font;

	SDL_Color color;

	Graphic graphic;

	FPS* fps;

	System();
public:
	virtual ~System();

	static System* getInstance();

	void onInit(Graphic graphic, FPS* fps);
	void onDispose();

	void setFontSize(int fontSize);
	int getFontSize();

	void setFont(const char* filename);
	TTF_Font* getFont();

	void setColor(int r, int g, int b);
	SDL_Color getColor();

	bool isShowingFPS();
	void setShowFPS(bool showingFPS);

	void showFPS();
};

#endif /* SYSTEM_H_ */
