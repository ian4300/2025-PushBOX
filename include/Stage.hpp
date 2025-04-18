#ifndef STAGE_H
#define STAGE_H

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
