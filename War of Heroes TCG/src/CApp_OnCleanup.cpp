//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnCleanup() {
	ScreenManager::getInstance()->onDispose();
	game.onDispose();
	video.onDispose();
	system->onDispose();

	Mix_CloseAudio();
	TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

//==============================================================================
