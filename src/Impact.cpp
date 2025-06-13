#include <vector>
#include "App.hpp"


Impact::Impact() {
    // Constructor implementation
}

// 檢測箱子是否碰撞到其他箱子或邊界
bool Impact::CheckBoxCollision(const glm::vec2& currentBoxPosition, const std::vector<glm::vec2>& otherBoxes, int direction ,int phase) {
    glm::vec2 newBoxPosition = currentBoxPosition;
    // 根據方向計算新位置
    switch (direction)
    {
        case 8: newBoxPosition.y += 100; break; // 上
        case 2: newBoxPosition.y -= 100; break; // 下
        case 4: newBoxPosition.x -= 100; break; // 左
        case 6: newBoxPosition.x += 100; break; // 右
    }

    // 第一章地圖檢測是否超出邊界
    if (phase <= 6)
    {
        if (newBoxPosition.x < -350 || newBoxPosition.x > 350 ||
            newBoxPosition.y < -200 || newBoxPosition.y > 200) {
            return true; // 無效位置
            }
        else if (newBoxPosition.y == 200)
        {
            if (newBoxPosition.x >= 150 || newBoxPosition.x == -250)
           {return true;}
        }
        else if (newBoxPosition.y == 100)
        {
            if (newBoxPosition.x > 250)
            {return true;}
        }
        else if (newBoxPosition.y == 0 || newBoxPosition.y == -100)
        {
            if (newBoxPosition.x > 350 || newBoxPosition.x < -350)
            {return true;}
        }
        else if (newBoxPosition.y == -200)
        {
            if (newBoxPosition.x >= 250 || newBoxPosition.x <= -350)
            {return true;}
        }
    }
    //第二章地圖檢測是否超出邊界
    if (phase >= 7 && phase <= 12)
    {
       if (newBoxPosition.y > 200 || newBoxPosition.y < -300)
       {return true;}
       if (newBoxPosition.y == 200)
       {
           if (newBoxPosition.x < 50 || newBoxPosition.x > 150)
           {return true;}
       }
       if (newBoxPosition.y == 100)
       {
            if (newBoxPosition.x < -250 || newBoxPosition.x > 150)
            {return true;}
       }
       if (newBoxPosition.y == 0)
       {
            if (newBoxPosition.x < -250 || newBoxPosition.x > 50)
            {return true;}
       }
       if (newBoxPosition.y == -100)
       {
            if (newBoxPosition.x < -350 || newBoxPosition.x > -250)
            {return true;}
       }
       if (newBoxPosition.y == -200)
       {
            if (newBoxPosition.x < -350 || newBoxPosition.x > 150)
            {return true;}
       }
       if (newBoxPosition.y == -300)
       {
            if (newBoxPosition.x < -350 || newBoxPosition.x > 250)
            {return true;}
       }
    }
    // 第三章地圖檢測是否超出邊界
    if (phase >= 13 && phase <= 18)
    {
       if (newBoxPosition.y > 300 || newBoxPosition.y < -400)
       {return true;}
       if (newBoxPosition.y >= 200)
       {
           if (newBoxPosition.x < -250 || newBoxPosition.x > -50)
           {return true;}
       }
       if (newBoxPosition.y == 100)
       {
            if (newBoxPosition.x < -350 || newBoxPosition.x > -50)
            {return true;}
       }
       if (newBoxPosition.y == 0)
       {
            if (newBoxPosition.x < -250 || newBoxPosition.x > 50)
            {return true;}
       }
       if (newBoxPosition.y == -100)
       {
            if (newBoxPosition.x < -250 || newBoxPosition.x > 250 || newBoxPosition.x == -150)
            {return true;}
       }
       if (newBoxPosition.y == -200)
       {
            if (newBoxPosition.x < -250 || newBoxPosition.x > 150)
            {return true;}
       }
       if (newBoxPosition.y == -300)
       {
            if (newBoxPosition.x < 0 || newBoxPosition.x > 250)
            {return true;}
       }
       if (newBoxPosition.y == -400)
       {
            if (newBoxPosition.x < 0 || newBoxPosition.x > 150)
            {return true;}
       }
    }
    //第四張地圖邊界檢測
    if (phase >= 19 && phase <= 24)
    {
       if (newBoxPosition.y > 300 || newBoxPosition.y < -300)
       {return true;}
       if (newBoxPosition.y == 300)
       {
           if (newBoxPosition.x < 50 || newBoxPosition.x > 150)
           {return true;}
       }
       if (newBoxPosition.y == 200)
       {
            if (newBoxPosition.x < 50 || newBoxPosition.x > 250)
            {return true;}
       }
       if (newBoxPosition.y == 100)
       {
            if (newBoxPosition.x < -250 || newBoxPosition.x > 250 || newBoxPosition.x == -50)
            {return true;}
       }
       if (newBoxPosition.y == 0)
       {
            if (newBoxPosition.x < -250 || newBoxPosition.x > 250)
            {return true;}
       }
       if (newBoxPosition.y == -100)
       {
            if (newBoxPosition.x < -250 || newBoxPosition.x > 250 || newBoxPosition.x == -150)
            {return true;}
       }
       if (newBoxPosition.y == -200)
       {
            if (newBoxPosition.x == 50 || newBoxPosition.x == -250)
            {}
            else
            {return true;}
       }
       if (newBoxPosition.y == -300)
       {
            if (newBoxPosition.x < -250 || newBoxPosition.x > 50)
            {return true;}
       }
    }
    // 第五張地圖邊界檢測
    if (phase >= 25 && phase <= 30)
    {
       if (newBoxPosition.y > 300 || newBoxPosition.y < -300)
       {return true;}
       if (newBoxPosition.y == 300)
       {
           if (newBoxPosition.x < -50 || newBoxPosition.x > 250)
           {return true;}
       }
       if (newBoxPosition.y == 200)
       {
            if (newBoxPosition.x != 250)
            {return true;}
       }
       if (newBoxPosition.y == 100)
       {
            if (newBoxPosition.x < -150 || newBoxPosition.x > 350)
            {return true;}
       }
        if (newBoxPosition.y == -100)
        {
            if (newBoxPosition.x < -150 || newBoxPosition.x > 250)
            {return true;}
        }
       if (newBoxPosition.y == 0)
       {
           if (newBoxPosition.x < -150 || newBoxPosition.x > 350 || newBoxPosition.x == -50 || newBoxPosition.x == 150)
           {return true;}
       }
       if (newBoxPosition.y == -200)
       {
           if (newBoxPosition.x < -150 || newBoxPosition.x > 250 || newBoxPosition.x == -50 || newBoxPosition.x == 150)
           {return true;}
       }
       if (newBoxPosition.y == -300)
       {
           if (newBoxPosition.x < -350 || newBoxPosition.x > 250)
           {return true;}
       }
    }
    // 檢測是否與其他箱子碰撞
    for (const auto& otherBox : otherBoxes) {
        if (newBoxPosition == otherBox) {
            return true; // 無效位置
        }
    }
    return false; // 位置有效
}