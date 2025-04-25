#include "App.hpp"
#include "Util/Logger.hpp"
#include "Util/Renderer.hpp"

Stage::Stage()
    : m_BackgroundImage(std::make_shared<Util::Image>("Resources/map1.png")){
    m_Transform.translation = {0, 0}; // 初始化位置
    m_Transform.scale = {1.00f, 1.00f};

    SetDrawable(m_BackgroundImage);
    SetZIndex(0);
}

void Stage::Update() {

}