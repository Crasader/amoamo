#pragma once

#include "cocos2d.h"
#include <utility>

USING_NS_CC;

namespace amoamo {
namespace common {
namespace node {
    
    class SpriteScroller
    {
    protected:
        typedef std::pair<Sprite*, Vec2> scrolls;
        std::vector<scrolls> sprites;
    public:
        void add(Sprite* s, Vec2 vector);
        virtual void scroll(const Vec2 &factor);
    };
    
}// namespace node
}// namespace common
}// namespace amoamo