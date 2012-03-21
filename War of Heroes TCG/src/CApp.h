//==============================================================================
// SDL Tutorial 1
//==============================================================================
#ifndef _CAPP_H_
#define _CAPP_H_

#include "framework/input/Event.h"

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "framework/fileIO/FileIO.h"
#include "framework/game/Game.h"
#include "framework/input/InputManager.h"
#include "framework/screen/ScreenManager.h"
#include "framework/system/System.h"
#include "framework/timer/FPS.h"
#include "framework/video/Video.h"

//==============================================================================
class CApp : public Event {
    private:
        Game game;

        Video video;

        InputManager inputManager;

        System* system;

        FPS fps;

        Screen* screen;

    public:
        CApp();

        int OnExecute();

    public:

        void onKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);

        void onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

        bool OnInit();

        void OnEvent(SDL_Event* Event);

        void OnLoop();

        void OnRender();

        void OnCleanup();

        void setStartScreen(Screen* screen);
};

//==============================================================================

#endif
