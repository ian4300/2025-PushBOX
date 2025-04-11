#ifndef APP_HPP
#define APP_HPP

#include <vector>
#include <SDL.h>
#include "pch.hpp"
#include "Character.hpp" // 玩家角色類
#include "Box.hpp"       // 箱子類
#include "Target.hpp"    // 目標區域類

class App {
public:
    enum class State {
        START,
        UPDATE,
        END
    };

    void InitSDL(); // 新增初始化 SDL 的方法
    void LoadTextures(); // 新增載入圖片的方法
    void Start();
    void Update();
    void Render();
    void End();
    void MoveMan(const glm::vec2& direction, int textureIndex);

    State GetCurrentState() const { return m_CurrentState; }

    void SetCurrentState(State state);

private:
    State m_CurrentState = State::START;
    int m_Phase = 1;
    Character m_man;
    std::vector<Box> m_boxes;
    std::vector<Target> m_targets;

    SDL_Window* m_Window = nullptr;
    SDL_Renderer* m_Renderer = nullptr;
    SDL_Texture* m_Textures[4] = {nullptr};
    SDL_Texture* m_CurrentTexture = nullptr;
};

#endif // APP_HPP