#ifndef APP_HPP
#define APP_HPP

#include "pch.hpp" // IWYU pragma: export

#include "Util/Renderer.hpp"
#include "Util/Image.hpp"
#include "PhaseResourceManger.hpp"
#include "Util/GameObject.hpp"

class Stage : public Util::GameObject {
public:
    Stage();
    void Update();

private:
    std::shared_ptr<Util::Image> m_BackgroundImage;
};

class man : public Util::GameObject {
public:
    man();
    void Update();
    glm::vec2 GetPosition() const {
        return m_Transform.translation;
    }
private:
    std::shared_ptr<Util::Image> m_Image;

};

class Box : public Util::GameObject {
public:
    Box(); // 新增構造函數
    void Update();
private:
    std::shared_ptr<Util::Image> m_Image;

};
class Target : public Util::GameObject {
public:
    Target(); // 新增構造函數
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

    App() : m_PRM() {};

    void Start();

    void Update();

    void End();

    void Render();

private:
    void ValidTask();
    PhaseResourceManger m_PRM;
    enum class Phase {
        CHANGE_CHARACTER_IMAGE,
        ABLE_TO_MOVE,
        COLLIDE_DETECTION,
    };
    State m_CurrentState = State::START;
    Phase m_Phase = Phase::CHANGE_CHARACTER_IMAGE;

    Util::Renderer m_Root;

    std::shared_ptr<man> m_man = std::make_shared<man>();

    std::shared_ptr<Stage> m_Stage = std::make_shared<Stage>();

    std::shared_ptr<Box> m_box1 = std::make_shared<Box>();
    std::shared_ptr<Box> m_box2 = std::make_shared<Box>();
    std::shared_ptr<Box> m_box3 = std::make_shared<Box>();

    std::shared_ptr<Target> m_target1 = std::make_shared<Target>();

    bool m_EnterDown = false;
};

#endif