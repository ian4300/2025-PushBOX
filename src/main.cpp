#include "App.hpp"
#include "SDL.h"

int main(int argc, char* argv[]) {
    App app;
    app.InitSDL(); // 初始化 SDL
    app.LoadTextures(); // 載入圖片

    while (app.GetCurrentState() != App::State::END) {
        switch (app.GetCurrentState()) {
        case App::State::START:
            app.Start();
            break;
        case App::State::UPDATE:
            app.Update();
            app.Render();
            break;
        case App::State::END:
            app.End(); // 清理資源
            break;
        default:
            break;
        }
    }

    return 0;
}