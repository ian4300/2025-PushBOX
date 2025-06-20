#include "App.hpp"
#include "Util/Input.hpp"
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"

man::man(App& app)
    : m_App(app), m_Image(std::make_shared<Util::Image>("../Resources/character1.png"))
{
    m_Transform.scale = {1.0f, 1.0f};
    m_Transform.translation = {50, 0};
    SetDrawable(m_Image); // 設置單一圖片
    SetZIndex(5);
}
void man::SetImage(const std::string& imagePath)
{
    m_Image = std::make_shared<Util::Image>(imagePath);
}
void man::Update(const std::vector<std::shared_ptr<Box>>& boxes, int phase)
{
    int direction = 0;
    Impact impact;
    // 第一章地圖移動邏輯
    if (phase <= 6)
    {
        //下判定
        if (Util::Input::IsKeyDown(Util::Keycode::DOWN)) {
            if (m_Transform.translation.x > -350 && m_Transform.translation.x < 250)
            {
                if (m_Transform.translation.y - 100 >= -200)
                {
                    m_Transform.translation.y -= 100;
                    m_App.minus();
                }
            }
            else
            {
                if (m_Transform.translation.y - 100 >= -100)
                {
                    m_Transform.translation.y -= 100;
                    m_App.minus();
                }
            }
            direction = 2;
            SetDrawable(m_Image);
        }
        //上判定
        else if (Util::Input::IsKeyDown(Util::Keycode::UP)) {
            if (m_Transform.translation.x == 350)
            {
                if (m_Transform.translation.y + 100 <= 0) {
                    m_Transform.translation.y += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.x == 250 || m_Transform.translation.x == 150 || m_Transform.translation.x == -250)
            {
                if (m_Transform.translation.y + 100 <= 100) {
                    m_Transform.translation.y += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.x >= -350 && m_Transform.translation.x <= 50 && m_Transform.translation.x != -250)
            {
                if (m_Transform.translation.y + 100 <= 200) {
                    m_Transform.translation.y += 100;
                    m_App.minus();
                }
            }
            direction = 8;
            SetDrawable(m_Image);
        }
        //左判定
        else if (Util::Input::IsKeyDown(Util::Keycode::LEFT)) {
            if (m_Transform.translation.y == 200)
            {
                if (m_Transform.translation.x - 100 != -250 && m_Transform.translation.x - 100 >= -350)
                {
                    m_Transform.translation.x -= 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.y >= -100 && m_Transform.translation.y <= 100)
            {
                if (m_Transform.translation.x - 100 >= -350)
                {
                    m_Transform.translation.x -= 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.y == -200)
            {
                if (m_Transform.translation.x - 100 >= -250)
                {
                    m_Transform.translation.x -= 100;
                    m_App.minus();
                }
            }
            direction = 4;
            m_Transform.scale.x = -1.0f;
            SetDrawable(m_Image);
        }
        //右判定
        else if (Util::Input::IsKeyDown(Util::Keycode::RIGHT)) {
            if (m_Transform.translation.y == 200)
            {
                if (m_Transform.translation.x + 100 <= 50 && m_Transform.translation.x + 100 != -250)
                {
                    m_Transform.translation.x += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.y == 100)
            {
                if (m_Transform.translation.x + 100 <= 250)
                {
                    m_Transform.translation.x += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.y == -200)
            {
                if (m_Transform.translation.x + 100 <= 150)
                {
                    m_Transform.translation.x += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.y == 0 || m_Transform.translation.y == -100)
            {
                if (m_Transform.translation.x + 100 <= 350)
                {
                    m_Transform.translation.x += 100;
                    m_App.minus();
                }
            }
            direction = 6;
            m_Transform.scale.x = 1.0f;
            SetDrawable(m_Image);
        }
    }
    //第二張地圖移動邏輯
    else if (phase >= 7 && phase <= 12)
    {
        //下判定
        if (Util::Input::IsKeyDown(Util::Keycode::DOWN)) {
            if (m_Transform.translation.y <= -100 && m_Transform.translation.y -100 >= -300)
            {
                m_Transform.translation.y -= 100;
                m_App.minus();
            }
            else
            {
                if (m_Transform.translation.x == -250 && m_Transform.translation.y -100 >= -300)
                {
                    m_Transform.translation.y -= 100;
                    m_App.minus();
                }
                else if (m_Transform.translation.x >= -150 && m_Transform.translation.x <= 50 && m_Transform.translation.y -100 >= 0)
                {
                    m_Transform.translation.y -= 100;
                    m_App.minus();
                }
                else if (m_Transform.translation.x == 150 &&  m_Transform.translation.y -100 >= 100)
                {
                    m_Transform.translation.y -= 100;
                    m_App.minus();
                }
            }
            direction = 2;
            SetDrawable(m_Image);
        }
         //上判定
        else if (Util::Input::IsKeyDown(Util::Keycode::UP)) {
            if (m_Transform.translation.x <= 150 && m_Transform.translation.x >= -150 && m_Transform.translation.y <= 0)
            {
                if (m_Transform.translation.y + 100 != -100) {
                    m_Transform.translation.y += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.x == -350)
            {
                if (m_Transform.translation.y + 100 != 0) {
                    m_Transform.translation.y += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.x >= -250 && m_Transform.translation.x <= -50 && m_Transform.translation.y > 0)
            {
                if (m_Transform.translation.y + 100 != 200) {
                    m_Transform.translation.y += 100;
                    m_App.minus();
                }
            }
            else if(m_Transform.translation.x == -250)
            {
                if (m_Transform.translation.y + 100 != 200) {
                    m_Transform.translation.y += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.x >= 50 && m_Transform.translation.x <= 150 && m_Transform.translation.y > 0)
            {
                if (m_Transform.translation.y + 100 != 300) {
                    m_Transform.translation.y += 100;
                    m_App.minus();
                }
            }
            direction = 8;
            SetDrawable(m_Image);
        }
        //左判定
        else if (Util::Input::IsKeyDown(Util::Keycode::LEFT)) {
            if (m_Transform.translation.y == 200)
            {
                if (m_Transform.translation.x -100 >= 50)
                {
                    m_Transform.translation.x -= 100;
                    m_App.minus();
                }
            }
            if (m_Transform.translation.y <= 100 && m_Transform.translation.y >= 0)
            {
                if (m_Transform.translation.x -100 >= -250)
                {
                    m_Transform.translation.x -= 100;
                    m_App.minus();
                }
            }
            if (m_Transform.translation.y <= -100)
            {
                if (m_Transform.translation.x -100 >= -350)
                {
                    m_Transform.translation.x -= 100;
                    m_App.minus();
                }
            }
            direction = 4;
            m_Transform.scale.x = -1.0f;
            SetDrawable(m_Image);
        }
        //右判定
        else if (Util::Input::IsKeyDown(Util::Keycode::RIGHT)) {
            if (m_Transform.translation.y <= 200 && m_Transform.translation.y >= 100)
            {
                if (m_Transform.translation.x + 100 <= 150)
                {
                    m_Transform.translation.x += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.y == 0)
            {
                if (m_Transform.translation.x + 100 <= 50)
                {
                    m_Transform.translation.x += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.y == -100)
            {
                if (m_Transform.translation.x + 100 <= -250)
                {
                    m_Transform.translation.x += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.y == -200)
            {
                if (m_Transform.translation.x + 100 <= 150)
                {
                    m_Transform.translation.x += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.y == -300)
            {
                if (m_Transform.translation.x + 100 <= 250)
                {
                    m_Transform.translation.x += 100;
                    m_App.minus();
                }
            }
            direction = 6;
            m_Transform.scale.x = 1.0f;
            SetDrawable(m_Image);
        }
    }
    //第三張地圖移動邏輯
    else if (phase >= 13 && phase <= 18)
    {
        //下判定
        if (Util::Input::IsKeyDown(Util::Keycode::DOWN)) {
            if (m_Transform.translation.x == -250 || m_Transform.translation.x == -50)
            {
                if (m_Transform.translation.y - 100 >= -200)
                {
                    m_Transform.translation.y -= 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.x == -150)
            {
                if (m_Transform.translation.y - 100 != -100 && m_Transform.translation.y - 100 >= -200)
                {
                    m_Transform.translation.y -= 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.x == 50 || m_Transform.translation.x == 150)
            {
                if (m_Transform.translation.y - 100 >= -400)
                {
                    m_Transform.translation.y -= 100;
                    m_App.minus();
                }
            }
            direction = 2;
            SetDrawable(m_Image);
        }
         //上判定
        else if (Util::Input::IsKeyDown(Util::Keycode::UP)) {
            if (m_Transform.translation.x == -250 || m_Transform.translation.x == -50)
            {
                if (m_Transform.translation.y + 100 <= 300)
                {
                    m_Transform.translation.y += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.x == -150)
            {
                if (m_Transform.translation.y + 100 != -100 && m_Transform.translation.y + 100 <= 300)
                {
                    m_Transform.translation.y += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.x == 50)
            {
                if (m_Transform.translation.y + 100 <= 0)
                {
                    m_Transform.translation.y += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.x == 150)
            {
                if (m_Transform.translation.y + 100 <= -100)
                {
                    m_Transform.translation.y += 100;
                    m_App.minus();
                }
            }
            direction = 8;
            SetDrawable(m_Image);
        }
        //左判定
        else if (Util::Input::IsKeyDown(Util::Keycode::LEFT)) {
            if (m_Transform.translation.y != 100 && m_Transform.translation.y != -100 && m_Transform.translation.y >= -200)
            {
                if (m_Transform.translation.x - 100 >= -250)
                {
                    m_Transform.translation.x -= 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.y == 100)
            {
                if (m_Transform.translation.x - 100 >= -350)
                {
                    m_Transform.translation.x -= 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.y == -100)
            {
                if (m_Transform.translation.x - 100 != -150 && m_Transform.translation.x -100 >= -250)
                {
                    m_Transform.translation.x -= 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.y <= -300)
            {
                if (m_Transform.translation.x - 100 >= 50)
                {
                    m_Transform.translation.x -= 100;
                    m_App.minus();
                }
            }
            direction = 4;
            m_Transform.scale.x = -1.0f;
            SetDrawable(m_Image);
        }
        //右判定
        else if (Util::Input::IsKeyDown(Util::Keycode::RIGHT)) {
            if (m_Transform.translation.y >= 100)
            {
                if (m_Transform.translation.x + 100 <= -50)
                {
                    m_Transform.translation.x += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.y == 0)
            {
                if (m_Transform.translation.x + 100 <= 50)
                {
                    m_Transform.translation.x += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.y == -100 || m_Transform.translation.y == -300)
            {
                if (m_Transform.translation.x + 100 <= 250)
                {
                    if(m_Transform.translation.y == -100)
                    {
                        if (m_Transform.translation.x + 100 == -150)
                        {
                            m_Transform.translation.x -= 100;
                            m_App.add();
                        }
                    }
                    m_Transform.translation.x += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.y == -200 || m_Transform.translation.y == -400)
            {
                if (m_Transform.translation.x + 100 <= 150)
                {
                    m_Transform.translation.x += 100;
                    m_App.minus();
                }
            }
            direction = 6;
            m_Transform.scale.x = 1.0f;
            SetDrawable(m_Image);
        }
    }
    //第四張地圖移動邏輯
    else if (phase >= 19 && phase <= 24)
    {
        //下判定
        if (Util::Input::IsKeyDown(Util::Keycode::DOWN)) {
            if (m_Transform.translation.x == 50 || m_Transform.translation.x == -250)
            {
                if (m_Transform.translation.y - 100 >= -300)
                {
                    m_Transform.translation.y -= 100;
                    m_App.minus();
                }
            }
            else if(m_Transform.translation.x == -50 || m_Transform.translation.x == 150 || m_Transform.translation.x == 250)
            {
                if (m_Transform.translation.y - 100 >= -100)
                {
                    m_Transform.translation.y -= 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.x == -150)
            {
                if (m_Transform.translation.y - 100 >= 0)
                {
                    m_Transform.translation.y -= 100;
                    m_App.minus();
                }
            }
            direction = 2;
            SetDrawable(m_Image);
        }
         //上判定
        else if (Util::Input::IsKeyDown(Util::Keycode::UP)) {
            if (m_Transform.translation.x == -250)
            {
                if (m_Transform.translation.y + 100 <= 100)
                {
                    m_Transform.translation.y += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.x == -150)
            {
                if (m_Transform.translation.y >= 0 && m_Transform.translation.y + 100 <= 100)
                {
                    m_Transform.translation.y += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.x == -50)
            {
                if (m_Transform.translation.y >= -100 && m_Transform.translation.y + 100 <= 0)
                {
                    m_Transform.translation.y += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.x == 50 || m_Transform.translation.x == 150)
            {
                if (m_Transform.translation.y + 100 <= 300)
                {
                    m_Transform.translation.y += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.x == 250)
            {
                if (m_Transform.translation.y + 100 <= 200)
                {
                    m_Transform.translation.y += 100;
                    m_App.minus();
                }
            }
            direction = 8;
            SetDrawable(m_Image);
        }
        //左判定
        else if (Util::Input::IsKeyDown(Util::Keycode::LEFT)) {
            if (m_Transform.translation.y == 200 || m_Transform.translation.y == 300)
            {
                if (m_Transform.translation.x - 100 >= 0)
                {
                    m_Transform.translation.x -= 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.y == 100)
            {
                if (m_Transform.translation.x - 100 >= -250 && m_Transform.translation.x - 100 != -50)
                {
                    m_Transform.translation.x -= 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.y == 0 || m_Transform.translation.y == -300)
            {
                if (m_Transform.translation.x - 100 >= -250)
                {
                    m_Transform.translation.x -= 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.y == -100)
            {
                if (m_Transform.translation.x - 100 >= -50)
                {
                    m_Transform.translation.x -= 100;
                    m_App.minus();
                }
            }
            direction = 4;
            m_Transform.scale.x = -1.0f;
            SetDrawable(m_Image);
        }
        //右判定
        else if (Util::Input::IsKeyDown(Util::Keycode::RIGHT)) {
            if (m_Transform.translation.y == 200 || m_Transform.translation.y == 0)
            {
                if (m_Transform.translation.x + 100 <= 250)
                {
                    m_Transform.translation.x += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.y == 300)
            {
                if (m_Transform.translation.x + 100 <= 150)
                {
                    m_Transform.translation.x += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.y == 100)
            {
                if (m_Transform.translation.x + 100 <= 250 && m_Transform.translation.x + 100 != -50)
                {
                    m_Transform.translation.x += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.y == -100)
            {
                if (m_Transform.translation.x >= -50 && m_Transform.translation.x + 100 <= 250)
                {
                            m_Transform.translation.x += 100;
                            m_App.minus();
                }
            }
            else if (m_Transform.translation.y == -300)
            {
                if (m_Transform.translation.x + 100 <= 50)
                {
                    m_Transform.translation.x += 100;
                    m_App.minus();
                }
            }
            direction = 6;
            m_Transform.scale.x = 1.0f;
            SetDrawable(m_Image);
        }
    }
    //第五張地圖移動邏輯
    else if (phase >= 25 && phase <= 30)
    {
        //下判定
        if (Util::Input::IsKeyDown(Util::Keycode::DOWN)) {
            if (m_Transform.translation.x == -350 || m_Transform.translation.x == 250)
            {
                if (m_Transform.translation.y - 100 >= -300)
                {
                    m_Transform.translation.y -= 100;
                    m_App.minus();
                }
            }
            else if(m_Transform.translation.x == -150 || m_Transform.translation.x == 50)
            {
                if (m_Transform.translation.y - 100 >= -300 && m_Transform.translation.y <= 100)
                {
                    m_Transform.translation.y -= 100;
                    m_App.minus();
                }
            }
            if (m_Transform.translation.x == 350)
            {
                if (m_Transform.translation.y - 100 >= 0)
                {
                    m_Transform.translation.y -= 100;
                    m_App.minus();
                }
            }
            direction = 2;
            SetDrawable(m_Image);
        }
         //上判定
        else if (Util::Input::IsKeyDown(Util::Keycode::UP)) {
            if (m_Transform.translation.x == -350)
            {
                if (m_Transform.translation.y + 100 <= -200)
                {
                    m_Transform.translation.y += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.x == 50 || m_Transform.translation.x == -150)
            {
                if (m_Transform.translation.y + 100 <= 100)
                {
                    m_Transform.translation.y += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.x == 250)
            {
                if (m_Transform.translation.y + 100 <= 300)
                {
                    m_Transform.translation.y += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.x == 350)
            {
                if (m_Transform.translation.y + 100 <= 100)
                {
                    m_Transform.translation.y += 100;
                    m_App.minus();
                }
            }
            direction = 8;
            SetDrawable(m_Image);
        }
        //左判定
        else if (Util::Input::IsKeyDown(Util::Keycode::LEFT)) {
            if (m_Transform.translation.y == 300)
            {
                if (m_Transform.translation.x - 100 >= -50)
                {
                    m_Transform.translation.x -= 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.y == 100 || m_Transform.translation.y == -100)
            {
                if (m_Transform.translation.x - 100 >= -150)
                {
                    m_Transform.translation.x -= 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.y == 0 || m_Transform.translation.y == -200)
            {
                if (m_Transform.translation.x - 100 >= -150 && m_Transform.translation.x - 100 != -50 && m_Transform.translation.x - 100 != 150)
                {
                    m_Transform.translation.x -= 100;
                    m_App.minus();
                }
            }
            if (m_Transform.translation.y == -300)
            {
                if (m_Transform.translation.x - 100 >= -350)
                {
                    m_Transform.translation.x -= 100;
                    m_App.minus();
                }
            }
            direction = 4;
            m_Transform.scale.x = -1.0f;
            SetDrawable(m_Image);
        }
        //右判定
        else if (Util::Input::IsKeyDown(Util::Keycode::RIGHT)) {
            if (m_Transform.translation.y == 300)
            {
                if (m_Transform.translation.x + 100 <= 250)
                {
                    m_Transform.translation.x += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.y == 100)
            {
                if (m_Transform.translation.x + 100 <= 350)
                {
                    m_Transform.translation.x += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.y == 0)
            {
                if (m_Transform.translation.x == 250)
                {
                    m_Transform.translation.x += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.y == -100)
            {
                if (m_Transform.translation.x + 100 <= 250)
                {
                    m_Transform.translation.x += 100;
                    m_App.minus();
                }
            }
            else if (m_Transform.translation.y == -300)
            {
                if (m_Transform.translation.x + 100 <= 250)
                {
                    m_Transform.translation.x += 100;
                    m_App.minus();
                }
            }
            direction = 6;
            m_Transform.scale.x = 1.0f;
            SetDrawable(m_Image);
        }
    }
    glm::vec2 newPosition = m_Transform.translation;

    // 提取箱子座標
    std::vector<glm::vec2> boxPositions;

    for (const auto& box : boxes) {
        boxPositions.push_back(box->GetPosition());
    }

    // 碰撞檢測
    for (const auto& box : boxes) {
        if (newPosition == box->GetPosition()) {
            if (impact.CheckBoxCollision(box->GetPosition(), boxPositions, direction , phase)) {
                // 還原角色位置
                switch (direction) {
                case 8: m_Transform.translation.y -= 100;m_App.add(); break;
                case 2: m_Transform.translation.y += 100;m_App.add(); break;
                case 4: m_Transform.translation.x += 100;m_App.add(); break;
                case 6: m_Transform.translation.x -= 100;m_App.add(); break;
                }
            } else {
                // 更新箱子位置
                switch (direction) {
                case 8: box->m_Transform.translation.y += 100; break;
                case 2: box->m_Transform.translation.y -= 100; break;
                case 4: box->m_Transform.translation.x -= 100; break;
                case 6: box->m_Transform.translation.x += 100; break;
                }
            }
        }
    }
}