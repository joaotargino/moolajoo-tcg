//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnEvent(SDL_Event* event) {
	Event::onEvent(event);
	inputManager.getKeyboardHandler()->onEvent(event);

    if(event->type == SDL_QUIT)
    	ScreenManager::getInstance()->onExit();
}

void CApp::onKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
	if (sym == SDLK_TAB)
		System::getInstance()->setShowFPS(!System::getInstance()->isShowingFPS());
}

void CApp::onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
	if (sym == SDLK_RETURN && (mod & KMOD_ALT))
		video.toggleFullscreen();
	else if (sym == SDLK_F4 && (mod & KMOD_ALT))
		ScreenManager::getInstance()->onExit();
}
