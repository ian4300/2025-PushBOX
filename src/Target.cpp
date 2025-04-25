#include "App.hpp"
#include "Util/Input.hpp"
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"

Target::Target()
    : m_Image(std::make_shared<Util::Image>("Resources/point.png"))
{
    m_Transform.scale = {1.00f, 1.00f};
    m_Transform.translation = {300, 110};
    SetDrawable(m_Image); // 設置單一圖片
    SetZIndex(2);
}

void Target::Update() {

}