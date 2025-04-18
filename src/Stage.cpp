#include "Stage.hpp"
#include "Util/Logger.hpp"
#include "Util/Renderer.hpp"

Stage::Stage()
    : m_BackgroundImage(std::make_shared<Util::Image>("Resources/box.png")){
    m_Transform.translation = {3, 20}; // 初始化位置
    m_Transform.scale = {22.00f, 12.00f};

    SetDrawable(m_BackgroundImage);
    SetZIndex(0);
}

void Stage::Update() {

}