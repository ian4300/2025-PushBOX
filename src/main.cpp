#include "App.hpp"
#include "SDL.h"
#include "SDL_main.h"

int main(int argc, char* argv[]) {
    App app;
    app.InitSDL();
    app.LoadTextures();
    app.Start();
    while (app.GetCurrentState() != App::State::END) {
        app.Update();
        app.Render();
    }

    app.End(); // 結束程式
    return 0;
}