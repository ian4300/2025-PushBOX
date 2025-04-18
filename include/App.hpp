#ifndef APP_HPP
#define APP_HPP

#include "pch.hpp" // IWYU pragma: export

#include "Util/Renderer.hpp"
#include "Character.hpp"
#include "Util/Image.hpp"
#include "PhaseResourceManger.hpp"
#include "Util/GameObject.hpp"

class man : public Util::GameObject {
public:
    man();
    void Update();
private:
    std::shared_ptr<Util::Image> m_Image;

};
class App {
public:
    enum class State {
        START,
        UPDATE,
        END,
    };

    State GetCurrentState() const { return m_CurrentState; }

    void Start();

    void Update();

    void End();

    void Render();

private:
    void ValidTask();

private:

    enum class Phase {
        CHANGE_CHARACTER_IMAGE,
        ABLE_TO_MOVE,
        COLLIDE_DETECTION,
    };
    State m_CurrentState = State::START;
    Phase m_Phase = Phase::CHANGE_CHARACTER_IMAGE;

    Util::Renderer m_Root;

    std::shared_ptr<man> m_man = std::make_shared<man>();

    std::shared_ptr<PhaseResourceManger> m_PRM;
    bool m_EnterDown = false;
};

#endif