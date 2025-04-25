#ifndef STAGE_HPP
#define STAGE_HPP

#include "Util/Image.hpp"
#include "Util/GameObject.hpp"
#include "pch.hpp"
#include <memory>


class Stage : public Util::GameObject {
public:
    Stage();
    void Update();

private:
    std::shared_ptr<Util::Image> m_BackgroundImage;
};

#endif
