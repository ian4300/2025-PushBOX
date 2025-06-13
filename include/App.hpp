#ifndef APP_HPP
#define APP_HPP

#include "pch.hpp"
#include "Util/Renderer.hpp"
#include "Util/Image.hpp"
#include "Util/Text.hpp"
#include "PhaseResourceManger.hpp"
#include "Util/GameObject.hpp"
#include "../example/include/GiraffeText.hpp"
///
class Stage : public Util::GameObject {
public:
    Stage();
    void Update();
    void SetBackgroundImage(const std::string& imagePath, int phase);

private:
    std::shared_ptr<Util::Image> m_BackgroundImage;
};
///
class Box : public Util::GameObject {
public:
    Box(); // 新增構造函數
    void Update();
    glm::vec2 GetPosition() const {
        return m_Transform.translation;
    }
private:
    std::shared_ptr<Util::Image> m_Image;

};
///
class man : public Util::GameObject {
public:
    man(App& app);
    void Update(const std::vector<std::shared_ptr<Box>>& boxes, int phase);
    glm::vec2 GetPosition() const {
        return m_Transform.translation;
    }
    void SetImage(const std::string& imagePath);
private:
    std::shared_ptr<Util::Image> m_Image;
    App& m_App;
};
///
class Target : public Util::GameObject {
public:
    Target(); // 新增構造函數
    void Update();
private:
    std::shared_ptr<Util::Image> m_Image;

};
///
class Impact {
public:
    Impact();
    bool CheckBoxCollision(const glm::vec2& currentBoxPosition, const std::vector<glm::vec2>& otherBoxes, int direction ,int phase);
};
///
class StepCounter : public Util::GameObject {
public:
    StepCounter();
    void Update();
    void SetStepCounterImage(const std::string& imagePath);

private:
    std::shared_ptr<Util::Image> m_StepCounterImage;
};
///
class App
{
public:
    enum class State {
        START,
        UPDATE,
        END,
    };


    State GetCurrentState() const { return m_CurrentState; }

    App() : m_PRM() {};

    int step = 0;

    void Start();

    void HideBoxesAndTargets();

    void Update();

    void End();

    void minus() {
            step--;
    }
    void add() {
        step++;
    }
    int getStep() {
        return step;
    }

private:
    void ValidTask();
    int finishtarget[6] = {0, 0, 0, 0, 0};\

    PhaseResourceManger m_PRM;
    State m_CurrentState = State::START;

    Util::Renderer m_Root;

    std::shared_ptr<man> m_man = std::make_shared<man>(*this);

    std::shared_ptr<Stage> m_Stage = std::make_shared<Stage>();

    std::shared_ptr<StepCounter> m_StepCounter = std::make_shared<StepCounter>();

    std::shared_ptr<GiraffeText> m_StepText;

    std::shared_ptr<Box> m_box1 = std::make_shared<Box>();
    std::shared_ptr<Box> m_box2 = std::make_shared<Box>();
    std::shared_ptr<Box> m_box3 = std::make_shared<Box>();
    std::shared_ptr<Box> m_box4 = std::make_shared<Box>();
    std::shared_ptr<Box> m_box5 = std::make_shared<Box>();

    std::shared_ptr<Target> m_target1 = std::make_shared<Target>();
    std::shared_ptr<Target> m_target2 = std::make_shared<Target>();
    std::shared_ptr<Target> m_target3 = std::make_shared<Target>();
    std::shared_ptr<Target> m_target4 = std::make_shared<Target>();
    std::shared_ptr<Target> m_target5 = std::make_shared<Target>();

    bool m_EnterDown = false;
};

#endif