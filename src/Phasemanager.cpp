#include "iostream"
#include "thread"
#include "chrono"
#include "App.hpp"
#include "PhaseResourceManger.hpp"
#include "Util/Logger.hpp"

PhaseResourceManger::PhaseResourceManger() {
}

void PhaseResourceManger::NextPhase() {
        m_Phase++;
        LOG_DEBUG("Passed! Next phase: {}", m_Phase);
}
void PhaseResourceManger::Reset() {
        m_Phase--;
    LOG_DEBUG("Passed! Next phase: {}", m_Phase);
}
void PhaseResourceManger::Fail()
{

}
void PhaseResourceManger::Victory()
{
    if (m_man)
    {
        // 切換到勝利圖片
        m_man->SetImage("Resources/Victory.png");

        // 等待 5 秒
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    m_man->SetImage("Resources/character1.png");
}
void PhaseResourceManger::Jump()
{

}
int PhaseResourceManger::GetPhase() const {
    return m_Phase;
}