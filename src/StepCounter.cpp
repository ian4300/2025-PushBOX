#include "App.hpp"
#include "Util/Logger.hpp"
#include "Util/Renderer.hpp"

#include "Util/Color.hpp"
#include "Util/Time.hpp"

StepCounter::StepCounter()
    : m_StepCounterImage(std::make_shared<Util::Image>("Resources/counter.png")){
    m_Transform.translation = {0, 0};
    m_Transform.scale = {0.7f, 0.7f};

    SetDrawable(m_StepCounterImage);
    SetZIndex(5);
}
void StepCounter::Update() {

}

void GiraffeText::Start() {
    m_Text = std::make_unique<Util::Text>(m_Font, m_Size, "0",
                                          Util::Color::FromRGB(255, 255, 255));
    SetDrawable(m_Text);
}

void GiraffeText::Update() {
    ImGui::Begin("Giraffe Text");
    ImGui::SetWindowSize({300, 100});
    ImGui::DragFloat2("Translation", &m_Transform.translation[0], 1, -100, 100);
    ImGui::DragFloat("Rotation", &m_Transform.rotation, 0.01F, 0,
                     2 * glm::pi<float>());
    ImGui::DragFloat2("Scale", &m_Transform.scale[0], 0.1F, 1, 10);
    ImGui::End();
    m_Text->SetText(
        fmt::format("{:.02f}", 1000.0F / Util::Time::GetDeltaTimeMs()));

    m_Text->SetColor(Util::Color::FromName(Util::Colors::RED));
}