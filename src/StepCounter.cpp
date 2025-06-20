#include "App.hpp"
#include "Util/Logger.hpp"
#include "Util/Renderer.hpp"
#include "iostream"
#include "Util/Color.hpp"
#include "Util/Time.hpp"
#include "Util/GameObject.hpp"

StepCounter::StepCounter()
    : m_StepCounterImage(std::make_shared<Util::Image>("../Resources/counter.png")){
    m_Transform.translation = {-515, -190};
    m_Transform.scale = {0.5f, 0.5f};

    SetDrawable(m_StepCounterImage);
    SetZIndex(5);
}
void StepCounter::Update() {

}