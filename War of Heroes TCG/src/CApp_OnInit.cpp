//==============================================================================
#include "CApp.h"

//==============================================================================
bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    TTF_Init();

    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);

    video.onInit();

    game.onInit(video.getScreen(), &inputManager);

    system = System::getInstance();
    system->onInit(game.getGraphic(), &fps);

    ScreenManager::getInstance()->onInit(game);
    ScreenManager::getInstance()->setCurrentScreen(screen);

    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL);

//    game.getAudio().newSound((char*) "Cursor1.ogg").play(MIX_MAX_VOLUME);
//    game.getAudio().newMusic((char*) "world_of_warcraft_wotlk_log_in_screen_music_youtube.mp3").play();

    return true;
}

//==============================================================================
