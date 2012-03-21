#include "CApp.h"

void CApp::OnRender() {
	ScreenManager::getInstance()->onRender();

	System::getInstance()->setColor(255, 0, 0);
	System::getInstance()->showFPS();

	video.onRender();
}
