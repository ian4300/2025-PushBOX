#include "App.hpp"
#include "Util/Input.hpp"
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"

Box::Box()
    : m_Image(std::make_shared<Util::Image>("Resources/box.png"))
{
    m_Transform.scale = {0.7f, 0.7f};
    m_Transform.translation = {-1000, -1000};
    SetDrawable(m_Image); // 設置單一圖片
    SetZIndex(4);
}

void Box::Update() {

}
