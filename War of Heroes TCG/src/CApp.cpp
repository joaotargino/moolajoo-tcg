//==============================================================================
#include "CApp.h"

//==============================================================================
CApp::CApp() {
}

//------------------------------------------------------------------------------
int CApp::OnExecute() {
    if(OnInit() == false) {
        return -1;
    }

    SDL_Event Event;

    while(ScreenManager::getInstance()->isRunning()) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();
    }

    OnCleanup();

    return 0;
}

//==============================================================================
//int main(int argc, char* argv[]) {
//    CApp theApp;
//
//    return theApp.OnExecute();
//}

//==============================================================================
