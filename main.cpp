#include <SFML/Graphics.hpp>
#include "GameEngine.h"

#ifdef _DEBUG
int main() {
    GameEngine::getInstance().start();
    return 0;
}
#else
#include <windows.h>
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    GameEngine::getInstance().start();
    return 0;
}
#endif
