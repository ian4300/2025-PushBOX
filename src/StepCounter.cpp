#include "App.hpp"
#include "Util/Logger.hpp"
#include "Util/Renderer.hpp"
#include "iostream"
#include "Util/Color.hpp"
#include "Util/Time.hpp"
#include "Util/GameObject.hpp"

StepCounter::StepCounter()
    : m_StepCounterImage(std::make_shared<Util::Image>("Resources/counter.png")){
    m_Transform.translation = {-515, -190};
    m_Transform.scale = {0.5f, 0.5f};

    SetDrawable(m_StepCounterImage);
    SetZIndex(5);
}
void StepCounter::Update() {

}

void StepText::Start() {
    m_Text = std::make_shared<Util::Text>("../assets/fonts/Inter.ttf", 24, "0", Util::Color::FromRGB(255, 255, 255));
    SetDrawable(m_Text);
}

void StepText::Update(int step) {
    ImGui::Begin("Step Text");
    ImGui::SetWindowSize({300, 100});
    ImGui::DragFloat2("Translation", &m_Transform.translation[0], 1, -100, 100);
    ImGui::DragFloat("Rotation", &m_Transform.rotation, 0.01F, 0,
                     2 * glm::pi<float>());
    ImGui::DragFloat2("Scale", &m_Transform.scale[0], 0.1F, 1, 10);
    ImGui::End();
    // 將 step 的值轉換為字串並設置到 m_Text
    m_Text->SetText(fmt::format("{}", step));

    m_Text->SetColor(Util::Color::FromName(Util::Colors::WHITE));;
}