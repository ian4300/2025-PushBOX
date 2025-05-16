#include "App.hpp"
#include "Util/Logger.hpp"
#include "Util/Renderer.hpp"

Stage::Stage()
    : m_BackgroundImage(std::make_shared<Util::Image>("Resources/map1.png")){
    m_Transform.translation = {0, 10}; // 初始化位置
    m_Transform.scale = {1.00f, 0.95f};

    SetDrawable(m_BackgroundImage);
    SetZIndex(0);
}
void Stage::SetBackgroundImage(const std::string& imagePath) {
    m_BackgroundImage = std::make_shared<Util::Image>(imagePath);
    SetDrawable(m_BackgroundImage);
}
void Stage::Update() {

}