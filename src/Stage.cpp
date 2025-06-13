#include "App.hpp"
#include "Util/Logger.hpp"
#include "Util/Renderer.hpp"

Stage::Stage()
    : m_BackgroundImage(std::make_shared<Util::Image>("Resources/map1.png")){
    m_Transform.translation = {0, 10}; // 初始化位置0,10
    m_Transform.scale = {1.00f, 0.95f};

    SetDrawable(m_BackgroundImage);
    SetZIndex(0);
}
void Stage::SetBackgroundImage(const std::string& imagePath, int phase) {
    m_BackgroundImage = std::make_shared<Util::Image>(imagePath);
    if (phase == 7)
        m_Transform.translation = {-50, -40};
    else if (phase == 13)
        m_Transform.translation = {-50, -35};
    else if (phase == 19)
        m_Transform.translation = {5, 15};
    else if (phase == 25)
        m_Transform.translation = {0, 10};
    SetDrawable(m_BackgroundImage);
}
void Stage::Update() {

}